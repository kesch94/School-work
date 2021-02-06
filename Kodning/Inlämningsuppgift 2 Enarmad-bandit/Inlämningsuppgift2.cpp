#include <iostream> /////N�dv�ndiga biblioteken f�r att alla funktioner ska fungera korrekt i dev-c++
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char bandit[3][3]; //Definierar arrayen

void Spin() //Funktion f�r snurrandet och genererar slumpm�ssiga tal som sedan konverteras till symboler
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

void outputStatistics(int balance, int games, int wins, int losses, int winnings) //funktion f�r output p� spelstatistiken
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
	cout << "////////////////////";
    for (int x = 0; x < 3; x++)
    {
        cout << "\n";
        for (int y = 0; y < 3; y++)
        {
            cout << bandit[x][y];
        }
    }
    cout << "\n" << "////////////////////" << endl;;
}

int checkWinCondition() //Funktion som kollar antalet linjer (element som �r i linje) som �r av lika symboler f�r att addera totalt antal linjer med lika symboler 
						//som sedan anv�nds f�r vinst-multiplikation
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
       
         output_board(); //funktion f�r att skriva ut arrayen (symbolerna)

    
	if (lines == 2)
	{
		return 3;
	}
	
	if (lines == 3)
	{
		return 4;
	}
	
	if (lines == 4)
	{
		return 5;
	}
	
	if (lines == 5)
    {
        return 7;
    }
	
    else if (lines == 8)
    {
        return 10;
    }

    else
    {
        return lines;
    }
}

int user_bet(int balance) //Funktion f�r insats, kallar p� varibeln balance (saldo).
{
    int user_bet = -1; //satt till user bet = -1 f�r att kunna anv�nda 0 f�r att inte placera ett bet och sedan kunna avsluta.
    cout << "How much would you like to bet? enter 0 if you would like to go back" << "\n";
   
    if (cin >> user_bet)
    {
        if (user_bet > balance)
        {
            cout << "You don't have enough money', please try again " << "\n";
            user_bet =-1;
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
            cout << "\n You bet: " << user_bet << "\n";
            return user_bet;
        }
	}

    else
    {
        cout << "Please enter a numerical value" << "\n";
        return user_bet;
    }
}

int user_guess(int user_bet) //Funktion f�r att r�kna ut vinst med hj�lp av funktionen Spin och funktionen checkWinCondition
{
	int winnings;
	 Spin();
	 winnings = checkWinCondition() * user_bet;
    return winnings;
}

int setSaldo() //Funktion f�r att ta emot ins�ttning med krav (s�tta startsaldo)
{
    int returnSaldo=0;
    cout << "Please Enter Your Starting Saldo (100,300 or 500)" << "\n";
    
    try  //Anv�nder mig utav try and catch statements f�r att kolla att det �r numeriskt v�rde, ifall n�gon skulle skriva in en bokstav ist�llet. Dock f�rhindrade deet inte kraschandet vid inmatning utav en bokstav.
    {
    	while (returnSaldo != 100 || returnSaldo != 300 || returnSaldo != 500)
		{
			cin >> returnSaldo; 
			if (returnSaldo == 100 || returnSaldo == 300 || returnSaldo == 500)
			{
			break;
			}
        	if (returnSaldo != 100 || returnSaldo != 300 || returnSaldo != 500)
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

bool continueGame() //Funktion f�r att fr�ga spelaren om hen vill forts�tta spela 
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


void return_saldo(int saldo) //Funktion f�r att skriva ut nuvarande saldo
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

    //spel loopen, fungerar endast med saldo > 0 , samt funktionen continueGame som �r spelf�rfr�gan.
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
                returned_winnings = user_guess(bet); //Funktion f�r spel-vinsten, r�knar med hj�lp utav betstorleken som blivit kallad i funktionen
                    
					if (returned_winnings > 0) //funktion f�r vinstmeddelande som adderar vinst och uppdaterar statistik
                    {
                        total_winnings = total_winnings + returned_winnings;
                        gamesPlayed++;
                        wins++;
                        cout << "\n" << "You won!: " << returned_winnings << endl;
                        saldo = saldo + returned_winnings;
                        return_saldo(saldo);
                    }

                    else if (returned_winnings <= 0) //funktion f�r f�rlustmeddelande som adderar statistik och subtraherar saldot
                    {
                        gamesPlayed++;
                        losses++;
                        cout << "You lost!" << endl;
                        saldo = saldo - bet;
                        return_saldo(saldo);
                    }
                }
            }
            outputStatistics(saldo, gamesPlayed, wins, losses, total_winnings); //funktion som kallas och skriver ut variablerna f�r statistik
		}

        else //Avslutningsmeddelande
        {
            cout << "Have a nice day, bye!" << "\n";
            break;
        }
    }
}


