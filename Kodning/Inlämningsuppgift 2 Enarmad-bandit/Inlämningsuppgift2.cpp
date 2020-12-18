#include <iostream>
#include <vector>
#include <string>

using namespace std;

char bandit[3][3];

void Spin() 
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
                bandit[x][y] = 'X' ;
            }

            
        }
    }
}

void outputStatistics(int bal, int games, int wins, int losses, int winnings) 
{
    cout << "\n\nSTATISTICS\n\n";
    cout << "CURRENT BALANCE:" << bal <<"\n";
    cout << "GAMES PLAYED:" << games <<"\n";
    cout << "WINS:" << wins <<"\n";
    cout << "LOSSES:"<< losses <<"\n";
    cout << "WINNINGS"<< winnings <<"\n";
}

void output_board()
{
    
    for (int x = 0; x < 3; x++)
    {
        std::cout << "\n";
       for (int y = 0; y < 3; y++)
       {
           std::cout << bandit[x][y];
       } 
    }
    std::cout << "\n";

}

int checkWinCondition()
{
    int lines = 0;


    for (int x = 0; x < 2; x++)
    {
        if (bandit[0+x][0] == bandit [0+x][1] && bandit[0+x][0] == bandit[0+x][2])
        {
            lines++;
        }
    }

    for (int y = 0; y < 2; y++)
    {
        if (bandit[0][0+y] == bandit [1][0+y] && bandit[0][0+y] == bandit[2][0+y])
        {
            lines++;
        }
    }

    output_board();

    if(lines == 5)
    {
        return 7;
    }

    else if(lines == 6)
    {
        return 10;
    }

    else 
    {
        return lines+1;
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
            cout << "You are to broke to bet that much, please try again " << "\n";
            return user_bet;
        }

        else if (user_bet <=-1)
        {
            cout << "Please enter a valid amount to bet" << "\n";
            user_bet = -1;
            return user_bet;
        }

        else if (user_bet >= 0 && user_bet <= balance)
        {
            cout << "You bet:" << user_bet << "\n";
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

    letTheOneArmBanditSpin();

    winnings = checkWinCondition() * user_bet;
    return winnings;
}

int setSaldo(){
    int returnSaldo;
    cout << "Please Enter Your Starting Saldo" << "\n";
    try
    {
        cin >> returnSaldo;
        return returnSaldo;
    }
    catch(...) 
    {
        return 0;
    }
}

bool continueGame()
{
    string continue_game;
    cout << "Would you like to place a bet? Y/N" << "\n";
    cin >> continue_game;
    if (continue_game == "Y")
    {
        return true;
    }

    else if (continue_game == "N")
    {
        return false;
    }

    else
    {
        cout << "Please be serious" << "\n";
        return false;
    }
    
}




void return_saldo(int saldo)
{
    std::cout << "Your current balance is:" << saldo << "\n";
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
    
    
    cout << "Hello and welcome to the internet roulette wheel" << "\n";

    saldo = setSaldo();
    

    
    while (saldo > 0)
    {
     if(continueGame()) 
        {
            bet = 0; 
            return_saldo(saldo);
            while(bet == 0)
            {
                bet = user_bet(saldo);
                if(bet == 0)
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
                     if(returned_winnings > 0)
                     {
                        total_winnings = total_winnings + returned_winnings;
                        gamesPlayed++;
                        wins++;
                        saldo = (saldo - bet) + returned_winnings;
                        return_saldo(saldo);
                     }

                     else if (returned_winnings < 0)
                     {
                        gamesPlayed++;
                        losses++;
                        saldo = saldo + returned_winnings;
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
    
return 0;

}



