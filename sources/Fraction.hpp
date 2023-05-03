
# pragma once
#include <iostream>

namespace ariel{
    
class Fraction
{
private:
    int numerator; //a
    int denominator; //b

    int gcd(int num1, int num2) const;

public:
    Fraction(): numerator(0), denominator(1){}
    Fraction(int nume, int deno): numerator(nume), denominator(deno){}
    Fraction(float frac);
    // Fraction(const Fraction &frac):numerator(frac.numerator), denominator(frac.denominator){}
    // ~Fraction(){};

    
    //operators on Fraction objects
    Fraction operator+(const Fraction& frac) const{return *this;}
    Fraction operator-(const Fraction& frac) const{return *this;}
    Fraction operator*(const Fraction& frac) const{return *this;}
    Fraction operator/(const Fraction& frac) const{return *this;}
    bool operator==(const Fraction& frac) const{return false;}
    bool operator>(const Fraction& frac) const{return false;}
    bool operator<(const Fraction& frac) const{return false;}
    bool operator>=(const Fraction& frac) const{return false;}
    bool operator<=(const Fraction& frac) const{return false;}
    // bool operator!=(const Fraction& b) const{return false;}

    Fraction& operator++(){return *this;} // ++n
    Fraction operator++(int num) const{return *this;} // n++
    Fraction& operator--(){return *this;} // --n
    Fraction operator--(int num) const{return *this;} // n--

    friend std::ostream& operator<<(std::ostream& output, const Fraction& obj){return output;}
    friend std::ostream& operator>>(std::ostream& input, Fraction& obj){return input;}

    //operators on Fraction and float
    Fraction operator+(float num) const{Fraction frac; return frac;}
    Fraction operator-(float num) const{Fraction frac; return frac;}
    Fraction operator*(float num) const{Fraction frac; return frac;}
    Fraction operator/(float num) const{Fraction frac; return frac;}
    bool operator==(float num) const{return false;}
    bool operator>(float num) const{return false;}
    bool operator<(float num) const{return false;}
    bool operator>=(float num) const{return false;}
    bool operator<=(float num) const{return false;}
    // bool operator!=(float b) const{return false;}

    //operators on float and Fraction
    friend Fraction operator+(float num, const Fraction& obj){Fraction frac; return frac;}
    friend Fraction operator-(float num, const Fraction& obj){Fraction frac; return frac;}
    friend Fraction operator*(float num, const Fraction& obj){Fraction frac; return frac;}
    friend Fraction operator/(float num, const Fraction& obj){Fraction frac; return frac;}
    friend bool operator==(float num, const Fraction& obj){return false;}
    friend bool operator>(float num, const Fraction& obj){return false;}
    friend bool operator<(float num, const Fraction& obj){return false;}
    friend bool operator>=(float num, const Fraction& obj){return false;}
    friend bool operator<=(float num, const Fraction& obj){return false;}
    // friend bool operator!=(float b, const Fraction& obj){return false;}

};
};