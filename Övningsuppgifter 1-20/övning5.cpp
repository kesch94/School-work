#include <iostream>

using namespace std;

int main()

{
	



	int x;
	int y;
	int z;

	cout << "Skriv in tal1: " << endl;
	cin >> x;
	cout << "Skriv in tal2: " << endl;
	cin >> y;
	z = x + y;
	
	if (x=='0') 
	{
		cout << "Du kan inte dividera med 0";
	
	}
	
	if (y=='0')
	{
		cout << "Du kan inte dividera med 0";
	}
	
	else 
	{
	
	cout << "SUMMAN AV tal1 och tal2 är: " << z << endl;
	
	cout << "Om du dividerar tal1 och tal2 får du: " << (x / y) << endl;
			
	}

}
