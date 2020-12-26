#include <iostream> //Nödvändiga biblioteken för att alla funktioner ska fungera korrekt i dev-c++
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char bandit[3][3]; //Definierar arrayen

void Spin() //Funktion för snurrandet och genererar slumpmässiga tal som sedan konverteras till symboler
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            int intRandomSymbol = rand() % 3;
            if (intRandomSymbol == 0)
            {
                bandit[x][y] = 'O';
            }
            else if (intRandomSymbol == 1)
            {
                bandit[x][y] = 'A';
            }
            else if (intRandomSymbol == 2)
            {
                bandit[x][y] = 'X';
            }


        }
    }
}

void outputStatistics(int balance, int games, int wins, int losses, int winnings) //funktion för output på spelstatistiken
{
    cout << "\n\nSTATISTICS\n\n";
    cout << "CURRENT BALANCE: " << balance << "\n";
    cout << "GAMES PLAYED: " << games << "\n";
    cout << "WINS: " << wins << "\n";
    cout << "LOSSES: " << losses << "\n";
    cout << "WINNINGS: " << winnings << "\n";
}

void output_board() //Funktion som skriver ut symbolerna i arrayen
{

    for (int x = 0; x < 3; x++)
    {
        cout << "\n";
        for (int y = 0; y < 3; y++)
        {
            cout << bandit[x][y];
        }
    }
    cout << "\n";

}

int checkWinCondition() //Funktion som kollar antalet linjer (element som är i linje) som är av lika symboler för att addera totalt antal linjer med lika symboler 
						//som sedan används för vinst-multiplikation
{
    int lines = 0;


    for (int x = 0; x < 3; x++)
    {
        if (bandit[0 + x][0] == bandit[0 + x][1] && bandit[0 + x][0] == bandit[0 + x][2])
        {
            lines++;
        }
    }

    for (int y = 0; y < 3; y++)
    {
        if (bandit[0][0 + y] == bandit[1][0 + y] && bandit[0][0 + y] == bandit[2][0 + y])
        {
            lines++;
        }
    }
	
	if (bandit[0][0] == bandit[1][1] && bandit[0][0] == bandit[2][2])
        {
            lines++;
        }
    
	if (bandit[0][2] == bandit[1][1] && bandit[0][2] == bandit[2][0])
        {
            lines++;
        }   
       
        
    output_board(); //Output för vinst-multiplikation med hjälp av antal rätta linjer

    if (lines == 6)
    {
        return 7;
    }

    else if (lines == 8)
    {
        return 9;
    }

    else
    {
        return lines;
    }
}

int user_bet(int balance) //Funktion för insats
{
    int user_bet = -1; //satt till user_bet = -1 för att kunna använda 0 för att inte placera ett bet och sedan kunna avsluta.
    cout << "How much would you like to bet? enter 0 if you would like to go back" << "\n";
    if (cin >> user_bet)
    {
        if (user_bet > balance)
        {
            cout << "You don't have enough money', please try again " << "\n";
            return user_bet;
        }

        else if (user_bet <= -1)
        {
            cout << "Please enter a valid amount to bet" << "\n";
            user_bet = -1;
            return user_bet;
        }

        else if (user_bet >= 0 && user_bet <= balance)
        {
            cout << "You bet: " << user_bet << "\n";
            return user_bet;
        }

    }

    else
    {
        cout << "Please enter a numerical value" << "\n";
        return user_bet;
    }


}

int user_guess(int user_bet) //Funktion för att räkna ut vinst med hjälp av funktionen Spin och funktionen checkWinCondition
{

    int winnings;

    Spin();

    winnings = checkWinCondition() * user_bet;
    return winnings;
}

int setSaldo() //Funktion för att ta emot insättning med krav
{
    int returnSaldo=0;
    cout << "Please Enter Your Starting Saldo (100,300 or 500)" << "\n";
    try
    {
    	while (returnSaldo != 100 || returnSaldo != 300 || returnSaldo != 500)
		{
			cin >> returnSaldo; 
			if (returnSaldo == 100 || returnSaldo == 300 || returnSaldo == 500)
			{
			break;
			}
        	if (returnSaldo =! 100 || returnSaldo != 300 || returnSaldo != 500)
			{
        		cout << "Please insert a valid amount!" << endl;
			}
		}
        
        return returnSaldo;
    }
    catch (...)
    {
        return 0;
    }
}

bool continueGame() //Funktion för att fråga spelaren om hen vill fortsätta spela 
{
    char continue_game;
    cout << "Would you like to place a bet? Y/N" << "\n";
    cin >> continue_game;
    if (continue_game == 'Y' || continue_game == 'y')
    {
        return true;
    }

    else if (continue_game == 'N' || continue_game == 'n')
    {
        return false;
    }

    else
    {
        cout << "Incorrect value" << "\n";
        return false;
    }

}




void return_saldo(int saldo) //Funktion för att skriva ut nuvarande saldo
{
    cout << "Your current balance is:" << saldo << "\n";
}

int main()
{
    ////////////////////////////////////////////////////////////
    int saldo = 0;
    int bet;
    int gamesPlayed = 0;
    int wins = 0;
    int losses = 0;
    int total_winnings = 0;
    int returned_winnings;
    ////////////////////////////////////////////////////////////


    cout << "Hello and welcome to the One Armed Bandit" << "\n";

    saldo = setSaldo();


    //spel loopen, fungerar endast med saldo > 0
    while (saldo > 0)
    {
        if (continueGame())
        {
            bet = 0;
            return_saldo(saldo);
            while (bet == 0)
            {
                bet = user_bet(saldo);
                if (bet == 0)
                {
                    break;
                }

                else if (bet < 0)
                {
                    break;
                }

                else
                {
                    returned_winnings = user_guess(bet); //kommentar 
                    if (returned_winnings > 0) //funktion för vinstmeddelande som adderar vinst och uppdaterar statistik
                    {
                        total_winnings = total_winnings + returned_winnings;
                        gamesPlayed++;
                        wins++;
                        cout << "\n" << "You won!: " << returned_winnings << endl;
                        saldo = saldo + returned_winnings;
                        return_saldo(saldo);
                    }

                    else if (returned_winnings <= 0) //funktion för förlustmeddelande som adderar statistik och subtraherar saldot
                    {
                        gamesPlayed++;
                        losses++;
                        cout << "You lost!" << endl;
                        saldo = saldo - bet;
                        return_saldo(saldo);
                    }

                }

            }

            outputStatistics(saldo, gamesPlayed, wins, losses, total_winnings); //Skriver ut all statistik i variablerna

        }

        else //Avslutningsmeddelande
        {
            cout << "Have a nice day" << "\n";
            break;
        }
    }


}


