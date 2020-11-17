#include <iostream>

using namespace std;

int main()

{

// float datatyper för att få med decimaler	
float pris;
float moms;
float slutpris;

moms = 25;

cout << "Vad kostar din vara? ";
cin >> pris;
cout << "Priset exklusive moms: " << pris << "kr" << endl;
cout << "Moms i procent: " << moms << "%" << endl;
cout << "Priset inklusive moms: " << (pris * 1.25) << "kr" << endl;

return 0;






}
