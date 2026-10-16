#include "fraction.h"
#include <iostream> 
#include <cmath> 

using namespace std;

//gcd function
int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


Fraction::Fraction(int num, int den) {
    numerator = num;
    if (den != 0) {
        denominator = den;
    }
    else {
        denominator = 1;
    }
}

//input function
void Fraction::input() {
    cout << "Please enter the numerator:";
    cin >> numerator;
    do {
        cout << "Please enter the denominator (non-zero number):";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Please try again." << endl;
        }
    } while (denominator == 0);
}

//output 
std::ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.getNumerator() << "/" << f.getDenominator();
    return os;
}
//ostream needs getter functions to access private members, that's why we use getter functions in the operator<< 

//getter functions
int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

//reduction function
Fraction Fraction::reduce() {
    int n = numerator;
    int d = denominator;
    if (denominator < 0) {
        n = -n;
        d = -d;
    }
    int G = gcd(n, d);
    n /= G;
    d /= G;

    return Fraction(n, d);
}


//set 
void Fraction::setNumerator(int num) {
    numerator = num;
    return;
}

void Fraction::setDenominator(int den) {
    if (denominator == 0) {
        cerr << "ERROR: THE DENOMINATOR CANNOT BE ZERO";
            return;
    }else
            denominator = den;
    }
//inversion function 
Fraction Fraction::inverse() const {
    if (numerator == 0) {
        cout << "ERROR: Can't invert a fraction with a numerator of zero\n";
        return *this; //return the original fraction if inversion is impossible
    }
    return Fraction(denominator, numerator);

}

//addition operation 

Fraction Fraction::add(const Fraction& another) const {
    int newNum = numerator * another.denominator + another.numerator * denominator;
    int newDen = denominator * another.denominator;
    return Fraction(newNum, newDen);
}

//subtraction
Fraction Fraction::subtract(const Fraction& another) const {
    int newNum = numerator * another.denominator - another.numerator * denominator;
    int newDen = denominator * another.denominator;
    return Fraction(newNum, newDen);
}

//multiply
Fraction Fraction::multiply(const Fraction& another) const {
    int newNum = numerator * another.numerator;
    int newDen = denominator * another.denominator;
    return Fraction(newNum, newDen);
}

//divide
Fraction Fraction::divide(const Fraction& another) const {
    if (another.numerator != 0) {
        int newNum = numerator * another.denominator;
        int newDen = denominator * another.numerator;
        return Fraction(newNum, newDen);
    }
    else cout << "ERROR: Cannot perform the calculation because the numerator of the 2nd fraction is zero";
}
