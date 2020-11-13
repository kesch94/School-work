#include <iostream>

using namespace std;

int main()

{

char svar;

cout << "Svara ja eller nej (j/n) ";

cin >> svar;


if(svar=='j'||svar=='J')
	{
	cout << "du svarade ja";
	}
 
 if(svar=='n'||svar=='N')
	{
	cout << "du svarade nej";
	}
else 
	{
	cout << "Felaktigt svar";
	}
	
	return 0;

}
