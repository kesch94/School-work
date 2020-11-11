//Bibliotek för alla kommandon och funktioner ska fungera korrekt.
#include <iostream>
#include <ctime>
#include <cstdlib>

//För att använda standardformat på kommandon utan tillägg std::
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
		return true; //Om number är jämnt sätt värdet till sant
	}
	
	else //Else statement, vad som ska göras om if-statementets krav inte "avfyras"
	{
		return false; // Annars sätts värdet till falskt.
	}
}

int main() //Main funktionen
{	
	//Satta datatyper och värden.
	int startsaldo = 1000; //Sätter startsaldo till 1000 med integer (heltal)
	int saldo; //Definierar saldo med datatyp integer
	long int insats; //long int för att ett större tal vid insats INTE ska krascha programmet.
	int random_number; //Slumpmässigt tal som genererats utav Random-funktionen.
	int vinst; //Definierar vinst med datatyp integer (heltal)
	char svar; //Definierar svar med datatyp char, för att lagra en bokstav som svarsalternativ.
	saldo = startsaldo; //Sätter saldo till samma värde som startsaldo.
	long int totalvinst; //Definierar totalvinst med long int ifall spelaren vinner mycket.
	
	
	//Välkomstmeddelande och saldo information.
	cout << "Hej och välkommen till att spela Roulette  " << endl; //Välkomstmeddelande
	cout << "Ditt startsaldo är:  " << startsaldo << "kr" << endl; //Meddelande om startsaldo
	
	//Förfrågan om spelaren vill spela
	cout << "Vill du spela? (J/N) " << endl; //String output
	cin >> svar; //Tar emot input och lagrar bokstaven i svar.
	
	
	
	//While funktion så att spelet bara fungerar medan spelaren svarat Ja och saldot är över värdet 0.
	while (svar == 'J' || svar == 'j' and saldo > 0) 
	{
		cout << "Vad kul att du vill spela, var snäll och ange storlek på din insats (100,300 eller 500kr) " << endl; //Meddelande om insats
		cin >> insats; //Input insats (insatsstorlek)
		
		if (insats > saldo) //If statement som går igång om insatsen är större än saldo
		{
			cout << "Du kan inte satsa mer än ditt tillgängliga saldo!" << endl; //Varningsmeddelande
		}
		
		else if (insats == 100 || insats == 300 || insats == 500) //Om insatsen stämmer med satta insatsvärden
		{
			random_number = random(); //Random_number sätts till värdet som random funktionen genererat.
			cout << "Du har satsat:  " << insats << "kr" << endl; //Output hur mycket spelaren har satsat
			saldo = saldo - insats;	//Saldo justeras efter insats
			cout << "Ditt nuvarande saldo är:  " << saldo << endl; //Output på saldo efter justering
			cout << "Vill du välja ett nummer eller färg? (N för Nummer, F för färg)"<< endl; //Fråga om spelare vill spela på färg eller nummer
			cout << "Notera att rätt nummer ger 10x insatsen, rätt färg ger 2x insatsen" << endl; //Output om vinst multiplikatorn
			char val; //Definierar val med datatypen char
			cin >> val; //Input för om spelaren till satsa på färg eller nummer, sparas som bokstav i val.
		
			if (val == 'N' || val == 'n') //Om valet är N (Nummer)
			{
<<<<<<< HEAD
				cout << "Du får nu välja ett nummer mellan 1 - 36  " << endl; //Meddelande om att spelaren ska välja nummer
				int nummer; //Definierar nummer med datatyp integet
				cin >> nummer; //Input önskat nummer spelaren vill spela på
				cout << "Du har valt; " << nummer << endl; //Output där spelaren ser vilket nummer hen har valt
				cout << "Lycka till! \n" << endl; //Meddelande
=======
				cout << "Du far nu välja ett nummer mellan 1 - 36  " << endl;
				int nummer; //add check for range 
				cin >> nummer;
				cout << "Du ha valt; " << nummer << endl;
				cout << "Lycka till! \n" << endl;
>>>>>>> 8e77c5174190c2065160e8eefffea7714fe8c5f2
				
				if (random_number == nummer) //Om det slumpmässiga talet som genererats är samma som det valda nummret (vinst)
				{
					vinst = (insats*10); //Vinsten räknas ut med insats multiplicerat med 10
					saldo = saldo + vinst; //Saldo uppdateras med nuvarande saldo + vinsten.
					cout << "Bollen landade på nummer: " << random_number << endl; //Meddelande om vilket nummer som genererades
					cout << "Grattis du vann! " << endl; //Vinst meddelande
					cout << "Vinst: " << (vinst - insats)<< "kr" << endl; //Meddelande om hur mycket vinsten är på 
					cout << "Ditt nuvarande saldo är: " << saldo << "kr" << endl; //Meddelande om uppdaterade saldot
				}
				
				else //Om det ej är vinst sker detta
				{
					cout << "Bollen landade på nummer: " << random_number << endl; //Visar genererade nummret
					cout << "Otur! Du förlorade! " << endl; //Meddelande om att förlust har skett
					cout << "Förlust: " << insats << "kr" << endl; //Visar insatsen som förlorats
					cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; //Visar nuvarande saldo
				}
				
			}
		
			else if (val == 'F'|| val == 'f') //Om valet är F att spela på färg sker detta.
			{
				cout << "Du får nu välja mellan färgen Röd och Svart (R/S)" << endl; //Meddelande om att välja färg mellan svart och röd
				char farg; //Definierar farg i datatyp char
				cin >> farg; //Input för farg
				
				if(farg == 'R' || farg == 'r') //Om färgen R (röd) väljs sker detta
				{
					cout  << "Du valde färgen Röd" << endl; //Meddelande om att färgen röd har valts
					cout << "Korrekt färg ger två gånger pengarna" << endl; //Meddelande om potentiella vinst multiplikationen
						if (black(random_number) == false) //Om nummret som genererats i random_number är ojämnt räknas det som rött och vinst sker.
						{
							cout << "Bollen landade på nummer: " << random_number << endl; //Meddelande om vilket nummer som har genererats
							vinst = (insats*2); //Uträkning utav vinst
							saldo = saldo + vinst; //Uppdatering utav saldo
							cout << "Grattis du vann! " << endl; //Vinstmeddelande
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om vinst
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
						else //Om det inte är jämnt nummer händer detta (förlust)
						{
							cout << "Bollen landade på nummer: " << random_number << endl; //Meddelande om genererat nummer
							cout << "Otur! Du förlorade! " << endl; //Förlust meddelande
							cout << "Förlust: " << insats << "kr" << endl; //Meddelande om insatsen som förlorats
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo
						}
				}
				else if (farg == 'S' || farg == 's') //Om valt färg är S (svart) sker detta
				{
					cout << "Du valde färgen Svart" << endl; //Meddelande om vald färg
					cout << "Korrekt färg ger två gånger pengarna" << endl; //Meddelande om vinst multiplikatorn
						if (black(random_number) == true) //Om talet är jämnt (true) och räknas som svart sker detta
						{
							cout << "Bollen landade på nummer: " << random_number << endl; //Meddelande om nummret som genererats
							vinst = (insats*2); //Uträkning för vinsten
							saldo = saldo + vinst; //Uppdatering utav saldo efter vinst
							cout << "Grattis du vann! " << endl; //Vinst meddelande
							cout << "Vinst: " << (vinst - insats) << "kr" << endl; //Meddelande om vinsten som vunnits
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo efter vinst
							cout << "Totala vinster: " << saldo - startsaldo << "kr" << endl;
						}
						else //Vad som händer om talet inte är jämnt alltså false sker detta
						{
							cout << "Bollen landade på nummer: " << random_number << endl; //Meddelande om nummret som genererats
							cout << "Otur! Du förlorade! " << endl; //Meddelande om förust
							cout << "Förlust: " << insats << "kr" << endl; //Meddelande om insatsen som förlorats
							cout << "Ditt nuvarande saldo är:  " << saldo << "kr" << endl; //Meddelande om nuvarande saldo, efter förlust
						}
				}
			
			}
		
		}
		else //Vad som sker om insatsvärdet är felaktigt (OM DET INTE ÄR 100,300 eller 500)
		{
		 cout << "Felaktigt värde" << endl;
		}
		//Förfrågan om spelaren vill spela igen efter avklarad spelomgång
		cout << "Vill du spela igen? (J/N) " << endl;
		totalvinst = saldo - startsaldo;
		cout << "Totalvinst: " << totalvinst << "kr" << endl; //Meddelande om totalvinst (Kan visa negativt tal vid förluster)
		cin >> svar; //Nytt input om spelaren vill spela, om svar ändras till N istället för J så avbryts while loopen
	
	}
	
	//Om spelaren svarar Nej till förfrågan om att spela/spela igen
	if (svar == 'N' || svar == 'n')
	{
	cout << "Vad tråkigt att du inte vill spela, Hejdå!" << endl; //Meddelande vid avslutning utav spel	
	}
	
	if (saldo <= 0) //Om saldot blir lägre eller likamed 0, så kommer detta meddelande att skrivas ut
	{
		cout << "Ditt saldo är för lågt, bättre lycka nästa gång!" << endl; //Meddelande om att saldot är för lågt för att spela vidare.
	}
	
	
	
return 0; //Returnerar värdet 0
	
}
