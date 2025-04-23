#include "Newton.h"
#include <iostream>

int main() {
    double YourNum;

    cout.precision(12); // Print more digits for clarity
    cout << "sqrt(2)    = " << NewtonSqrt(2) << endl;   //1.4....
    cout << "sqrt(9)    = " << NewtonSqrt(9) << endl;   //9
    cout << "sqrt(0.25) = " << NewtonSqrt(0.25) << endl;  //0.5
    cout << "sqrt(100)  = " << NewtonSqrt(100) << endl;   // 10



    cout << "Enter your own # (make it a double if you wannt)" << endl;
    cin >> YourNum;
    cout << "\n" << NewtonSqrt(YourNum) << endl;

    return 0;

}