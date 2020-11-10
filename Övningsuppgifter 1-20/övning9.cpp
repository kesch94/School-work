#include <iostream>

using namespace std;

int main()

{
	
	int x;
	int y;
	int z;

//tar in tal x
	cout << "Skriv in tal1: " << endl;
	cin >> x;
//tar in tal y	
	cout << "Skriv in tal2: " << endl;
	cin >> y;
//Algoritm för variabel Y
	z = x + y;
//Meddelande om SUMMA
	cout << "SUMMAN AV tal1 och tal2 är: " << z << endl;
//Meddelande om division

if (x==0)
	{
cout << "Du kan inte dividera med 0";
	}

if (y==0)
	{
	cout << "Du kan inte dividera med 0";
	}

else
	{
		cout << "Om du dividerar tal1 och tal2 får du: " << (x / y) << endl;
	}
}
