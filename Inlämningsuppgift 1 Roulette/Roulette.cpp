//Inkluderar bibliotek för alla kommandon och funktioner ska fungera korrekt samt att vi använder standard namespace för enkelhetensskull.
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Funktion som genererar ett slumpmässigttal mellan 1 och 36, Lärarens rekommendation.
int random()
{
	srand(time(0));
	return rand() % 36 + 1;
}

//Datatyp bool för sant eller falsk till färgsatsningen. Med funktion som kallar på number.
bool black(int number)
{
	if (number % 2 == 0) //If statement med uträkning för att få fram om talet är jämnt eller ojämnt. Med hjälp utav modulus.
	{
		return true; //Om number är jämnt sätts vädet till sant
	}

	else //Else statement, vad som ska göras om if-statementets krav inte "avfyras"
	{
		return false; // Annars sätts värdet till falskt.
	}
}

int main() //Main funktionen
{
	//Skapar datatyper och värden.
	int startsaldo = 1000; //Sï¿½tter startsaldo till 1000 med integer (heltal)
	int saldo; //Definierar saldo med datatyp integer
	long int insats; //long int för att ett större tal vid insats INTE ska krascha programmet. (till exempel insats 999999)
	int random_number; //Här sparas det slumpmässiga talet som genererats utav Random-funktionen.
	int vinst; //Definierar vinst med datatyp integer (heltal)
	char svar; //Definierar svar med datatyp char, för att lagra en bokstav som svarsalternativ.
	saldo = startsaldo; //Sätter saldo till samma värde som startsaldo.
	long int totalvinst; //Definierar totalvinst med long int ifall spelaren vinner mycket.


	//Vï¿½lkomstmeddelande och saldo information.
	cout << "Hej och valkommen till att spela Roulette  " << endl;
	cout << "Ditt startsaldo ar:  " << startsaldo << "kr" << endl; 

	//Förfrågan om spelaren vill spela och tar emot input
	cout << "Vill du spela? (J/N) " << endl; 
	cin >> svar;



	//While funktion så att spelet bara fungerar medan spelaren svarat Ja och saldot är över värdet 0.
	while (svar == 'J' || svar == 'j' and saldo > 0)
	{
		cout << "Vad kul att du vill spela, var snall och ange storlek pa din insats (100,300 eller 500kr) " << endl; //Meddelande om insatsstorlekar
		cin >> insats; //Input insats (insatsstorlek)

		if (insats > saldo) //If statement som går igång om insatsen är större än saldo
		{
			cout << "Du kan inte satsa mer an ditt tillgangliga saldo!" << endl; //Varningsmeddelande
		}

		else if (insats == 100 || insats == 300 || insats == 500) //Om insatsen stämmer med satta insatskraven
		{
			random_number = random(); //Random_number sätts till värdet som random funktionen genererat.
			cout << "Du har satsat:  " << insats << "kr" << endl; //Output hur mycket spelaren har satsat
			saldo = saldo - insats;	//Saldo justeras efter insats
			cout << "Ditt nuvarande saldo ar:  " << saldo << endl; //Output på saldo efter justering
			cout << "Vill du valja ett nummer eller farg? (N for Nummer, F for farg)"<< endl; //Fråga om spelare vill spela p färg eller nummer
			cout << "Notera att ratt nummer ger 10x insatsen, ratt farg ger 2x insatsen" << endl; //Output om vinst multiplikatorn
			char val; //Definierar val med datatypen char
			cin >> val; //Input för om spelaren till satsa på färg eller nummer, sparas som bokstav i val.

			if (val == 'N' || val == 'n') //Om valet ar N (Nummer)
			{
				cout << "Du far nu valja ett nummer mellan 1 - 36  " << endl; //Meddelande om att spelaren ska välja nummer
				int nummer; 
				cin >> nummer; //Input änskat nummer spelaren vill satsa på
				cout << "Du har valt; " << nummer << endl; //Output där spelaren ser vilket nummer hen har valt
				cout << "Lycka till! \n" << endl; //Meddelande Lycka till

				if (random_number == nummer) //Om det slumpmässiga talet som genererats är samma som det valda nummret (vinst)
				{
					vinst = (insats*10); //Vinsten räknas ut med insats multiplicerat med 10
					saldo = saldo + vinst; //Saldo uppdateras med nuvarande saldo + vinsten.
					cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om vilket nummer som genererades
					cout << "Grattis du vann! \a " << endl; //Vinstmeddelande med alert för windowsljud vid vinst
					cout << "Vinst: " << (vinst - insats)<< "kr" << endl; //Meddelande om hur mycket vinst
					cout << "Ditt nuvarande saldo ar: " << saldo << "kr" << endl; //Meddelande om uppdaterade saldot
				}

				else //Om det ej ï¿½r vinst sker detta
				{
					cout << "Bollen landade pa nummer: " << random_number << endl; //Visar genererade nummret
					cout << "Otur! Du forlorade! " << endl; //Meddelande om att färlust har skett
					cout << "Forlust: " << insats << "kr" << endl; //Visar insatsen som förlorats
					cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Visar nuvarande saldo
				}

			}

			else if (val == 'F'|| val == 'f') //Om valet är F att spela på färg sker detta.
			{
				cout << "Du far nu valja mellan fargen R'o'd och Svart (skriv in R eller S)" << endl; //Meddelande om att välja mellan färgen röd och svart
				char farg; //Definierar farg i datatyp char
				cin >> farg; //Input för farg

				if(farg == 'R' || farg == 'r') //Om färgen R (röd) väljs sker detta
				{
					cout  << "Du valde fargen Rod" << endl; //Meddelande om att färgen röd har valts
					cout << "Korrekt farg ger tva ganger pengarna" << endl; //Meddelande om potentiella vinst multiplikationen
						if (black(random_number) == false) //Om nummret som genererats i random_number är ojämnt räknas det som rätt och vinst sker.
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om vilket nummer som har genererats
							vinst = (insats*2); //Uträkning utav vinst
							saldo = saldo + vinst; //Uppdatering utav saldo
							cout << "Grattis du vann! \a " << endl; //Vinstmeddelande med alert
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om reella vinsten
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
						else //Om det inte är jämnt nummer händer detta (förlust)
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om genererat nummer
							cout << "Otur! Du forlorade! " << endl; //Förlust meddelande
							cout << "Förlust: " << insats << "kr" << endl; //Meddelande om insatsen som förlorats
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
				}
				else if (farg == 'S' || farg == 's') //Om valt färg är S (svart) sker detta
				{
					cout << "Du valde fargen Svart" << endl; //Meddelande om vald färg
					cout << "Korrekt farg ger tva ganger pengarna" << endl; //Meddelande om vinst multiplikatorn
						if (black(random_number) == true) //Om talet är jämnt (true) och räknas som svart sker detta
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om nummret som genererats
							vinst = (insats*2); //Uträkning för vinsten
							saldo = saldo + vinst; //Uppdatering utav saldo efter vinst
							cout << "Grattis du vann!\a " << endl; //Vinst meddelande
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om vinsten som vunnits 
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo efter vinst
						}
						else //Vad som händer om talet inte är jämnt alltså false sker detta
						{
							cout << "Bollen landade pa nummer: " << random_number << endl; //Meddelande om nummret som genererats
							cout << "Otur! Du forlorade! " << endl; //Meddelande om förust
							cout << "Forlust: " << insats << "kr" << endl; //Meddelande om insatsen som förlorats
							cout << "Ditt nuvarande saldo ar:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo, efter förlust
						}
				}

			}

		}
		else //Vad som sker om insatsvärdet är felaktigt (OM DET INTE ÄR 100,300 eller 500)
		{
		 cout << "Felaktigt varde" << endl;
		}
		
		totalvinst = saldo - startsaldo; //Uträkning för differens sedan start
		
		if(saldo>=1000) //Om saldot är över startsaldot händer detta
		{
		cout << "Totalvinst: " << totalvinst << "kr" << endl; //Meddelande om totalvinst sedan start
		}
		if(saldo<1000) //Om saldot är lägre än startsaldo händer detta
		{
		cout << "Du ligger " << totalvinst << "kr" << endl; //skriver ut hur mycket minus spelare ligger
		}
		//Förfrågan om spelaren vill spela igen efter avklarad spelomgång
		cout << "Vill du spela igen? (J/N) " << endl;
		cin >> svar; //Nytt input om spelaren vill spela, om svar ändras till N istället för J så avbryts while-loopen
	}

	//Om spelaren svarar Nej till förfrågan om att spela/spela igen
	if (svar == 'N' || svar == 'n')
	{
	cout << "Vad trakigt att du inte vill spela, Hejda!" << endl; //Meddelande vid avslutning utav spel
	}

	if (saldo <= 0) //Om saldot blir lägre eller likamed 0, så kommer detta meddelande att skrivas ut
	{
		cout << "Ditt saldo ar for lagt, battre lycka nasta gang!" << endl; //Meddelande om att saldot är för lågt för att spela vidare.
	}



return 0;

}
