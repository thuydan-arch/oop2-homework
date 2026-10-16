#pragma once
#ifndef fraction_h
#define fraction_h
#include <iostream>
class Fraction {

    int numerator, denominator;
    int gcd(int a, int b);

public:
    Fraction(int num = 0, int den = 1);

    //IO
    void input();
    friend std::ostream& operator<< (std::ostream&, const Fraction&);

    //getter
    int getNumerator() const;
    int getDenominator() const;

    // set 
    
    void setNumerator(int num); 
    void setDenominator( int den);

    //reduction
    Fraction reduce();

    //inversion
    Fraction inverse() const;

    //arithmetic operations
    Fraction add(const Fraction& another) const;
    Fraction subtract(const Fraction& another) const;
    Fraction multiply(const Fraction& another) const;
    Fraction divide(const Fraction& another) const;

};
#endif