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
	//Satt datatyper och värden.
	int startsaldo = 1000;
	int saldo;
	long int insats; //long int för att ett större tal vid insats INTE ska krascha programmet.
	int random_number; //Slumpmässigt tal som genererats utav Random-funktionen.
	int vinst; 
	char svar;
	saldo = startsaldo;
	
	cout << "Hej och välkommen till att spela Roulette  " << endl;
	cout << "Ditt startsaldo är:  " << startsaldo << "kr" << endl;
	
	cout << "Vill du spela? (J/N) " << endl;
	cin >> svar;
	
	
	
	
	while (svar == 'J' || svar == 'j' and saldo > 0)
	{
		cout << "Vad kul att du vill spela, var snäll och ange storlek på din insats (100,300 eller 500kr) " << endl;
		cin >> insats;
		
		if (insats > saldo)
		{
			cout << "Du kan inte satsa mer än ditt tillgängliga saldo!" << endl;
		}
		
		else if (insats == 100 || insats == 300 || insats == 500)
		{
			random_number = random();
			cout << "Du har satsat:  " << insats << "kr" << endl;
			saldo = saldo - insats;	
			cout << "Ditt nuvarande saldo är:  " << saldo << endl;
			cout << "Vill du välja ett nummer eller färg? (N för Nummer, F för färg)"<< endl;
			cout << "Notera att rätt nummer ger 10x insatsen, rätt färg ger 2x insatsen" << endl;
			char val;
			cin >> val;
		
			if (val == 'N' || val == 'n') 
			{
				cout << "Du får nu välja ett nummer mellan 1 - 36  " << endl;
				int nummer; //add check for range 
				cin >> nummer;
				cout << "Du ha valt; " << nummer << endl;
				cout << "Lycka till! \n" << endl;
				
				if (random_number == nummer)
				{
					vinst = (insats*10);
					saldo = saldo + vinst;
					cout << "Bollen landade på nummer: " << random_number << endl;
					cout << "Grattis du vann! " << endl;
					cout << "Vinst: " << (vinst - insats)<< "kr" << endl;
					cout << "Ditt nuvarande saldo är: " << saldo << "kr" << endl;
				}
				
				else 
				{
					cout << "Bollen landade på nummer: " << random_number << endl;
					cout << "Otur! Du förlorade! " << endl;
					cout << "Förlust: " << insats << "kr" << endl;
					cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; 
				}
				
			}
		
			else if (val == 'F'|| val == 'f')
			{
				cout << "Du får nu välja mellan färgen Röd och Svart (R/S)" << endl;
				char farg;
				cin >> farg;
				
				if(farg == 'R' || farg == 'r')
				{
					cout  << "Du valde färgen Röd" << endl;
					cout << "Korrekt färg ger två gånger pengarna" << endl;
						if (black(random_number) == false)
						{
							cout << "Bollen landade på nummer: " << random_number << endl;
							vinst = (insats*2);
							saldo = saldo + vinst;
							cout << "Grattis du vann! " << endl;
							cout << "Vinst: " << (vinst - insats) << "kr" << endl;
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl;
						}
						else 
						{
							cout << "Bollen landade på nummer: " << random_number << endl;
							cout << "Otur! Du förlorade! " << endl;
							cout << "Förlust: " << insats << "kr" << endl;
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; 
						}
				}
				else if (farg == 'S' || farg == 's')
				{
					cout << "Du valde färgen Svart" << endl;
					cout << "Korrekt färg ger två gånger pengarna" << endl;
						if (black(random_number) == true)
						{
							cout << "Bollen landade på nummer: " << random_number << endl;
							vinst = (insats*2);
							saldo = saldo + vinst;
							cout << "Grattis du vann! " << endl;
							cout << "Vinst: " << (vinst - insats) << "kr" << endl;
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl;
						}
						else 
						{
							cout << "Bollen landade på nummer: " << random_number << endl;
							cout << "Otur! Du förlorade! " << endl;
							cout << "Förlust: " << insats << "kr" << endl;
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; 
						}
				}
			
			}
		
		}
		else
		{
		 cout << "Felaktigt värde" << endl;
		}
		
		cout << "Vill du spela igen? (J/N) " << endl;
		cin >> svar;
	
	}
	
	
	if (svar == 'N' || svar == 'n')
	{
	cout << "Vad tråkigt att du inte vill spela, Hejdå!" << endl;	
	}
	
	if (saldo <= 0)
	{
		cout << "Ditt saldo är för lågt, bättre lycka nästa gång!" << endl;
	}
	
	
	
return 0;
	
}
