#include <iostream> //Nödvändiga biblioteken för att alla funktioner ska fungera korrekt i dev-c++
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char bandit[3][3]; //Definierar arrayen

void Spin() //Funktion för snurrandet (skapar 9 element)
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

void outputStatistics(int balance, int games, int wins, int losses, int winnings) //Output för spelstatistiken
{
    cout << "\n\nSTATISTICS\n\n";
    cout << "CURRENT BALANCE: " << balance << "\n";
    cout << "GAMES PLAYED: " << games << "\n";
    cout << "WINS: " << wins << "\n";
    cout << "LOSSES: " << losses << "\n";
    cout << "WINNINGS: " << winnings << "\n";
}

void output_board() //Output för att skriva ut karaktärerna i arrayen Itterate through items of the array sequintely 
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

int checkWinCondition()
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

    output_board();

    if (lines == 5)
    {
        return 7;
    }

    else if (lines == 6)
    {
        return 10;
    }

    else
    {
        return lines;
    }
}

int user_bet(int balance)
{
    int user_bet = -1;
    cout << "How much would you like to bet? enter 0 if you would like to cancel" << "\n";
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

int user_guess(int user_bet)
{

    int winnings;

    Spin();

    winnings = checkWinCondition() * user_bet;
    return winnings;
}

int setSaldo() {
    int returnSaldo;
    cout << "Please Enter Your Starting Saldo" << "\n";
    try
    {
        cin >> returnSaldo;
        return returnSaldo;
    }
    catch (...)
    {
        return 0;
    }
}

bool continueGame()
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




void return_saldo(int saldo)
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
                    returned_winnings = user_guess(bet);
                    if (returned_winnings > 0)
                    {
                        total_winnings = total_winnings + returned_winnings;
                        gamesPlayed++;
                        wins++;
                        cout << "\n" << "You won!: " << returned_winnings << endl;
                        saldo = saldo + returned_winnings;
                        return_saldo(saldo);
                    }

                    else if (returned_winnings <= 0)
                    {
                        gamesPlayed++;
                        losses++;
                        cout << "You lost!" << endl;
                        saldo = saldo - bet;
                        return_saldo(saldo);
                    }

                }

            }

            outputStatistics(saldo, gamesPlayed, wins, losses, total_winnings);

        }

        else
        {
            cout << "Have a nice day" << "\n";
            break;
        }
    }


}


