#include <iostream>

using namespace std;

int main()

{

// float datatyper f�r att f� med decimaler	
float pris;
float rabatt;
float slutpris;
float rabattprocent;

//F�rdefinerade rabatter
rabattprocent = 17;
rabatt = 0.83;

//output inputs f�r pris och visning utav strings med utr�knade priser
cout << "Vad kostar din vara? ";
cin >> pris;
cout << "Pris f�re rabatt: " << pris << "kr" << endl;
cout << "Rabatt i procent: " << rabattprocent << endl;
cout << "Pris efter rabatt: " << (pris * rabatt) << "kr" << endl;

return 0;






}
