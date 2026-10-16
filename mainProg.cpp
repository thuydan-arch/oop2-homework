#include "fraction.h"
#include <iostream> 

using namespace std;

int main() {
    Fraction f1, f2;

    cout << "Please enter the first fraction: \n";
    f1.input();

    cout << "Please enter the second fraction : \n";
    f2.input();

    cout << "The first fraction is: " << f1 << endl;
    cout << "The second fraction is:" << f2 << endl;

    //reduction of the 1st fraction
    cout << "The reduction of the 1st fraction:" << f1.reduce() << endl;

    //inversion of the 1st fraction
    cout << "The inversion of the first fraction is: " << f1.inverse() << endl;

// sum, subtraction, multiplication, division
    cout << "The sum of the 1st and 2nd fraction: " << f1.add(f2) << endl;

    cout << "The subtraction from the 1st fraction and 2nd fraction:  " << f1.subtract(f2) << endl;


    cout << "The multiplication of the 1st fraction and the 2nd fraction:  " << f1.multiply(f2) << endl;

    cout << "The division of the 1st fraction by the 2nd fraction:  " << f1.divide(f2) << endl;


    return 0;
}