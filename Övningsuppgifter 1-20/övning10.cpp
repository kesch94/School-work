#include <iostream>

using namespace std;

int main()
{

int tal = 0;
	
	cout << "Skriv ett tal mellan 0 och 200 " << endl;
	cin >> tal;
	
		if(tal <=200 && tal >= 101)
		{
			cout << "Talet �r st�rre �n 100";
		}
	
		if(tal==100)
		{
			cout << "Talet �r 100";
		}
		
		if(tal<100)
		{
			cout << "Talet �r mindre �n 100";
		}
		
		if(tal>200)
		{
			cout << "V�rdet �r utanf�r omr�det";
		}
	
	return 0;
	
}
