#include <iostream>

using namespace std;

int main()
{

int tal = 0;
	
	cout << "Skriv ett tal mellan 0 och 200 " << endl;
	cin >> tal;
	
		if(tal <=200 && tal >= 101)
		{
			cout << "Talet är större än 100";
		}
	
		if(tal==100)
		{
			cout << "Talet är 100";
		}
		
		if(tal<100)
		{
			cout << "Talet är mindre än 100";
		}
		
		if(tal>200)
		{
			cout << "Värdet är utanför området";
		}
	
	return 0;
	
}
