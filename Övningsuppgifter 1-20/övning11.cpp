#include <iostream>

using namespace std;

int main()

{

char svar;

cout << "Svara ja eller nej (j/n) ";

cin >> svar;


if(svar == 'j' or 'J')
	{
	cout << "du svarade ja";
	}
 
 if(svar == 'n' or 'N')
	{
	cout << "du svarade nej";
	}
	
	return 0;

}
