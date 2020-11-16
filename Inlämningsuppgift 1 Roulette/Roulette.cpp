//Inkluderar bibliotek f�r alla kommandon och funktioner ska fungera korrekt samt att vi anv�nder standard namespace f�r enkelhetensskull.
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Funktion som genererar ett slumpm�ssigttal mellan 1 och 36, L�rarens rekommendation.
int random()
{
	srand(time(0));
	return rand() % 36 + 1;
}

//Datatyp bool f�r sant eller falsk till f�rgsatsningen. Med funktion som kallar p� number.
bool black(int number)
{
	if (number % 2 == 0) //If statement med utr�kning f�r att f� fram om talet �r j�mnt eller oj�mnt. Med hj�lp utav modulus.
	{
		return true; //Om number �r j�mnt s�tts v�det till sant
	}

	else //Else statement, vad som ska g�ras om if-statementets krav inte "avfyras"
	{
		return false; // Annars s�tts v�rdet till falskt.
	}
}

int main() //Main funktionen
{
	//Skapar datatyper och v�rden.
	int startsaldo = 1000; //S�tter startsaldo till 1000 med integer (heltal)
	int saldo; //Definierar saldo med datatyp integer
	long int insats; //long int f�r att ett st�rre tal vid insats INTE ska krascha programmet. (till exempel insats 999999)
	int random_number; //H�r sparas det slumpm�ssiga talet som genererats utav Random-funktionen.
	int vinst; //Definierar vinst med datatyp integer (heltal)
	char svar; //Definierar svar med datatyp char, f�r att lagra en bokstav som svarsalternativ.
	saldo = startsaldo; //S�tter saldo till samma v�rde som startsaldo.
	long int totalvinst; //Definierar totalvinst med long int ifall spelaren vinner mycket.


	//V�lkomstmeddelande och saldo information.
	cout << "Hej och valkommen till att spela Roulette  " << endl;
	cout << "Ditt startsaldo ar:  " << startsaldo << "kr" << endl; 

	//F�rfr�gan om spelaren vill spela och tar emot input
	cout << "Vill du spela? (J/N) " << endl; 
	cin >> svar;



	//While funktion s� att spelet bara fungerar medan spelaren svarat Ja och saldot �r �ver v�rdet 0.
	while (svar == 'J' || svar == 'j' and saldo > 0)
	{
		cout << "Vad kul att du vill spela, var snall och ange storlek pa din insats (100,300 eller 500kr) " << endl; //Meddelande om insatsstorlekar
		cin >> insats; //Input insats (insatsstorlek)

		if (insats > saldo) //If statement som g�r ig�ng om insatsen �r st�rre �n saldo
		{
			cout << "Du kan inte satsa mer an ditt tillgangliga saldo!" << endl; //Varningsmeddelande
		}

		else if (insats == 100 || insats == 300 || insats == 500) //Om insatsen st�mmer med satta insatskraven
		{
			random_number = random(); //Random_number s�tts till v�rdet som random funktionen genererat.
			cout << "Du har satsat:  " << insats << "kr" << endl; //Output hur mycket spelaren har satsat
			saldo = saldo - insats;	//Saldo justeras efter insats
			cout << "Ditt nuvarande saldo ar:  " << saldo << endl; //Output p� saldo efter justering
			cout << "Vill du valja ett nummer eller farg? (N for Nummer, F for farg)"<< endl; //Fr�ga om spelare vill spela p f�rg eller nummer
			cout << "Notera att ratt nummer ger 10x insatsen, ratt farg ger 2x insatsen" << endl; //Output om vinst multiplikatorn
			char val; //Definierar val med datatypen char
			cin >> val; //Input f�r om spelaren till satsa p� f�rg eller nummer, sparas som bokstav i val.

			if (val == 'N' || val == 'n') //Om valet ar N (Nummer)
			{
				cout << "Du far nu valja ett nummer mellan 1 - 36  " << endl; //Meddelande om att spelaren ska v�lja nummer
				int nummer; 
				cin >> nummer; //Input �nskat nummer spelaren vill satsa p�
				cout << "Du har valt; " << nummer << endl; //Output d�r spelaren ser vilket nummer hen har valt
				cout << "Lycka till! \n" << endl; //Meddelande Lycka till

				if (random_number == nummer) //Om det slumpm�ssiga talet som genererats �r samma som det valda nummret (vinst)
				{
					vinst = (insats*10); //Vinsten r�knas ut med insats multiplicerat med 10
					saldo = saldo + vinst; //Saldo uppdateras med nuvarande saldo + vinsten.
					cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om vilket nummer som genererades
					cout << "Grattis du vann! \a " << endl; //Vinstmeddelande med alert f�r windowsljud vid vinst
					cout << "Vinst: " << (vinst - insats)<< "kr" << endl; //Meddelande om hur mycket vinst
					cout << "Ditt nuvarande saldo ar: " << saldo << "kr" << endl; //Meddelande om uppdaterade saldot
				}

				else //Om det ej �r vinst sker detta
				{
					cout << "Bollen landade pa nummer: " << random_number << endl; //Visar genererade nummret
					cout << "Otur! Du forlorade! " << endl; //Meddelande om att f�rlust har skett
					cout << "Forlust: " << insats << "kr" << endl; //Visar insatsen som f�rlorats
					cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Visar nuvarande saldo
				}

			}

			else if (val == 'F'|| val == 'f') //Om valet �r F att spela p� f�rg sker detta.
			{
				cout << "Du far nu valja mellan fargen R'o'd och Svart (skriv in R eller S)" << endl; //Meddelande om att v�lja mellan f�rgen r�d och svart
				char farg; //Definierar farg i datatyp char
				cin >> farg; //Input f�r farg

				if(farg == 'R' || farg == 'r') //Om f�rgen R (r�d) v�ljs sker detta
				{
					cout  << "Du valde fargen Rod" << endl; //Meddelande om att f�rgen r�d har valts
					cout << "Korrekt farg ger tva ganger pengarna" << endl; //Meddelande om potentiella vinst multiplikationen
						if (black(random_number) == false) //Om nummret som genererats i random_number �r oj�mnt r�knas det som r�tt och vinst sker.
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om vilket nummer som har genererats
							vinst = (insats*2); //Utr�kning utav vinst
							saldo = saldo + vinst; //Uppdatering utav saldo
							cout << "Grattis du vann! \a " << endl; //Vinstmeddelande med alert
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om reella vinsten
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
						else //Om det inte �r j�mnt nummer h�nder detta (f�rlust)
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om genererat nummer
							cout << "Otur! Du forlorade! " << endl; //F�rlust meddelande
							cout << "F�rlust: " << insats << "kr" << endl; //Meddelande om insatsen som f�rlorats
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
				}
				else if (farg == 'S' || farg == 's') //Om valt f�rg �r S (svart) sker detta
				{
					cout << "Du valde fargen Svart" << endl; //Meddelande om vald f�rg
					cout << "Korrekt farg ger tva ganger pengarna" << endl; //Meddelande om vinst multiplikatorn
						if (black(random_number) == true) //Om talet �r j�mnt (true) och r�knas som svart sker detta
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om nummret som genererats
							vinst = (insats*2); //Utr�kning f�r vinsten
							saldo = saldo + vinst; //Uppdatering utav saldo efter vinst
							cout << "Grattis du vann!\a " << endl; //Vinst meddelande
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om vinsten som vunnits 
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo efter vinst
						}
						else //Vad som h�nder om talet inte �r j�mnt allts� false sker detta
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om nummret som genererats
							cout << "Otur! Du forlorade! " << endl; //Meddelande om f�rust
							cout << "Forlust: " << insats << "kr" << endl; //Meddelande om insatsen som f�rlorats
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo, efter f�rlust
						}
				}

			}

		}
		else //Vad som sker om insatsv�rdet �r felaktigt (OM DET INTE �R 100,300 eller 500)
		{
		 cout << "Felaktigt varde" << endl;
		}
		
		totalvinst = saldo - startsaldo; //Utr�kning f�r differens sedan start
		
		if(saldo>=1000) //Om saldot �r �ver startsaldot h�nder detta
		{
		cout << "Totalvinst: " << totalvinst << "kr" << endl; //Meddelande om totalvinst sedan start
		}
		if(saldo<1000) //Om saldot �r l�gre �n startsaldo h�nder detta
		{
		cout << "Du ligger " << totalvinst << "kr" << endl; //skriver ut hur mycket minus spelare ligger
		}
		//F�rfr�gan om spelaren vill spela igen efter avklarad spelomg�ng
		cout << "Vill du spela igen? (J/N) " << endl;
		cin >> svar; //Nytt input om spelaren vill spela, om svar �ndras till N ist�llet f�r J s� avbryts while-loopen
	}

	//Om spelaren svarar Nej till f�rfr�gan om att spela/spela igen
	if (svar == 'N' || svar == 'n')
	{
	cout << "Vad trakigt att du inte vill spela, Hejda!" << endl; //Meddelande vid avslutning utav spel
	}

	if (saldo <= 0) //Om saldot blir l�gre eller likamed 0, s� kommer detta meddelande att skrivas ut
	{
		cout << "Ditt saldo ar for lagt, battre lycka nasta gang!" << endl; //Meddelande om att saldot �r f�r l�gt f�r att spela vidare.
	}



return 0;

}
