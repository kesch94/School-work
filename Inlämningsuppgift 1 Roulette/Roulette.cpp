#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random() 
{
	srand(time(0));
	return rand() % 36 + 1;
}

bool black(int number)
{
	if (number % 2 == 0)
	{
		return true;
	}
	
	else 
	{
		return false;
	}
}

int main()
{	
	//Satt datatyper och v�rden.
	int startsaldo = 1000;
	int saldo;
	long int insats; //long int f�r att ett st�rre tal vid insats INTE ska krascha programmet.
	int random_number; //Slumpm�ssigt tal som genererats utav Random-funktionen.
	int vinst; 
	char svar;
	saldo = startsaldo;
	
	cout << "Hej och v�lkommen till att spela Roulette  " << endl;
	cout << "Ditt startsaldo �r:  " << startsaldo << "kr" << endl;
	
	cout << "Vill du spela? (J/N) " << endl;
	cin >> svar;
	
	
	
	
	while (svar == 'J' || svar == 'j' and saldo > 0)
	{
		cout << "Vad kul att du vill spela, var sn�ll och ange storlek p� din insats (100,300 eller 500kr) " << endl;
		cin >> insats;
		
		if (insats > saldo)
		{
			cout << "Du kan inte satsa mer �n ditt tillg�ngliga saldo!" << endl;
		}
		
		else if (insats == 100 || insats == 300 || insats == 500)
		{
			random_number = random();
			cout << "Du har satsat:  " << insats << "kr" << endl;
			saldo = saldo - insats;	
			cout << "Ditt nuvarande saldo �r:  " << saldo << endl;
			cout << "Vill du v�lja ett nummer eller f�rg? (N f�r Nummer, F f�r f�rg)"<< endl;
			cout << "Notera att r�tt nummer ger 10x insatsen, r�tt f�rg ger 2x insatsen" << endl;
			char val;
			cin >> val;
		
			if (val == 'N' || val == 'n') 
			{
				cout << "Du f�r nu v�lja ett nummer mellan 1 - 36  " << endl;
				int nummer; //add check for range 
				cin >> nummer;
				cout << "Du ha valt; " << nummer << endl;
				cout << "Lycka till! \n" << endl;
				
				if (random_number == nummer)
				{
					vinst = (insats*10);
					saldo = saldo + vinst;
					cout << "Bollen landade p� nummer: " << random_number << endl;
					cout << "Grattis du vann! " << endl;
					cout << "Vinst: " << (vinst - insats)<< "kr" << endl;
					cout << "Ditt nuvarande saldo �r: " << saldo << "kr" << endl;
				}
				
				else 
				{
					cout << "Bollen landade p� nummer: " << random_number << endl;
					cout << "Otur! Du f�rlorade! " << endl;
					cout << "F�rlust: " << insats << "kr" << endl;
					cout << "Ditt nuvarande saldo �r:  " << saldo << "kr" << endl; 
				}
				
			}
		
			else if (val == 'F'|| val == 'f')
			{
				cout << "Du f�r nu v�lja mellan f�rgen R�d och Svart (R/S)" << endl;
				char farg;
				cin >> farg;
				
				if(farg == 'R' || farg == 'r')
				{
					cout  << "Du valde f�rgen R�d" << endl;
					cout << "Korrekt f�rg ger tv� g�nger pengarna" << endl;
						if (black(random_number) == false)
						{
							cout << "Bollen landade p� nummer: " << random_number << endl;
							vinst = (insats*2);
							saldo = saldo + vinst;
							cout << "Grattis du vann! " << endl;
							cout << "Vinst: " << (vinst - insats) << "kr" << endl;
							cout << "Ditt nuvarande saldo �r:  " << saldo << "kr" << endl;
						}
						else 
						{
							cout << "Bollen landade p� nummer: " << random_number << endl;
							cout << "Otur! Du f�rlorade! " << endl;
							cout << "F�rlust: " << insats << "kr" << endl;
							cout << "Ditt nuvarande saldo �r:  " << saldo << "kr" << endl; 
						}
				}
				else if (farg == 'S' || farg == 's')
				{
					cout << "Du valde f�rgen Svart" << endl;
					cout << "Korrekt f�rg ger tv� g�nger pengarna" << endl;
						if (black(random_number) == true)
						{
							cout << "Bollen landade p� nummer: " << random_number << endl;
							vinst = (insats*2);
							saldo = saldo + vinst;
							cout << "Grattis du vann! " << endl;
							cout << "Vinst: " << (vinst - insats) << "kr" << endl;
							cout << "Ditt nuvarande saldo �r:  " << saldo << "kr" << endl;
						}
						else 
						{
							cout << "Bollen landade p� nummer: " << random_number << endl;
							cout << "Otur! Du f�rlorade! " << endl;
							cout << "F�rlust: " << insats << "kr" << endl;
							cout << "Ditt nuvarande saldo �r:  " << saldo << "kr" << endl; 
						}
				}
			
			}
		
		}
		else
		{
		 cout << "Felaktigt v�rde" << endl;
		}
		
		cout << "Vill du spela igen? (J/N) " << endl;
		cin >> svar;
	
	}
	
	
	if (svar == 'N' || svar == 'n')
	{
	cout << "Vad tr�kigt att du inte vill spela, Hejd�!" << endl;	
	}
	
	if (saldo <= 0)
	{
		cout << "Ditt saldo �r f�r l�gt, b�ttre lycka n�sta g�ng!" << endl;
	}
	
	
	
return 0;
	
}
