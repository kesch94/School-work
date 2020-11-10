#include <iostream>

using namespace std;

int main()

{

// float datatyper för att få med decimaler	
float pris;
float rabatt;
float slutpris;
float rabattprocent;

//Fördefinerade rabatter
rabattprocent = 17;
rabatt = 0.83;

//output inputs för pris och visning utav strings med uträknade priser
cout << "Vad kostar din vara? ";
cin >> pris;
cout << "Pris före rabatt: " << pris << "kr" << endl;
cout << "Rabatt i procent: " << rabattprocent << endl;
cout << "Pris efter rabatt: " << (pris * rabatt) << "kr" << endl;

return 0;






}
