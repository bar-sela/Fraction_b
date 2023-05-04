#include "Fraction.hpp"
#include "iostream"
#include "algorithm"


int __gcd(int a, int b) {
    int temp = a ;
    if (b > a ){ /// swap
        a = b ;
        b = temp;
    }
    a = abs(a); /// for negative values
    b= abs(b);
    if (b == 0)
        return a;
    else
        return __gcd(b, (a % b));
}

Fraction operator+(Fraction x1, Fraction x2) {
    int newX1N = x1.getNumerator() *  x2.getDenominator();
    int newX2N = x2.getNumerator() *  x1.getDenominator();
    int  sumOfNewN =    newX1N + newX2N ;
    int gcD = __gcd(sumOfNewN, x1.getDenominator() * x2.getDenominator());
    return Fraction(sumOfNewN/gcD , (x1.getDenominator() * x2.getDenominator())/gcD);
}

Fraction Fraction::operator+(float x) {
    Fraction newFraction(x);
    return (*this + newFraction);
}

Fraction operator-(Fraction& plus, Fraction& minus) {
    int newX1N =  plus.getNumerator() *  minus.getDenominator();
    int newX2N = minus.getNumerator() *  plus.getDenominator();
    int  subtractOfNewN =    newX1N - newX2N ;
    int gcD = __gcd((subtractOfNewN), plus.getDenominator() *minus.getDenominator());
    Fraction ans =  Fraction(subtractOfNewN/gcD , (plus.getDenominator() * minus.getDenominator())/gcD);
    return ans;
}

Fraction Fraction::operator-(float x) {
    Fraction represetX = Fraction(x);
    return (*this - represetX);
}

Fraction operator-(float x, Fraction frac) {
    Fraction represetX = Fraction(x);
    return (represetX - frac);
}

Fraction operator*(Fraction &f1, Fraction &f2) {
    int mulNUM = f1.numerator * f2.numerator;
    int mulDEN = f1.denominator * f2.denominator;
    int gcD = __gcd(mulDEN, mulNUM);
    Fraction ans = Fraction(mulNUM / gcD , mulDEN / gcD);
    return ans;
}



Fraction operator*(float x,Fraction f) {
    Fraction x_frac = Fraction(x);
    return (f * x_frac);
}

Fraction operator*(Fraction f, float x) {
    return (x * f) ;
}
/// divied
Fraction Fraction::operator/(Fraction &other) const {
    if(other.denominator == 0)
        throw ;
    int mulNUM = this->numerator * other.denominator;
    int mulDEN = this->denominator * other.numerator;
    int gcD = __gcd(mulDEN, mulNUM);
    Fraction ans = Fraction(mulNUM / gcD , mulDEN / gcD);
    return ans;
}
Fraction operator/(float x, Fraction f ) {
    Fraction x_frac = Fraction(x);
    return(x_frac / f);
}

Fraction operator/(Fraction f, float x ) {
    Fraction x_frac = Fraction(x);
    return (f / x_frac);
}
/// < , <= , >= , >
bool Fraction::operator<(Fraction const &other) const {
    float  a = (float)this->numerator / (float)this->denominator;
    float b = (float)other.numerator / (float)other.denominator;
    if( b > a  )
        return true;
    return false;
}
bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);
}

bool operator<(float x, const Fraction &f) {
    Fraction x_frac = Fraction(x);
    return (x_frac < f);
}

bool operator>=(float x,  const Fraction& f) {
    return !(x<f );
}

bool Fraction::operator<=(const Fraction &other) const {
    return (other >= *this);
}

bool Fraction::operator>(const Fraction &other) const {
    return (other < *this);
}




bool operator>(float x, const Fraction& f) {
    Fraction x_frac = Fraction(x);
    return (f< x_frac);
}

bool operator<=(float x, const Fraction& f) {
    return!(x > f);
}
 /// important : when i compare in the tests float and Fraction :
 /// eventhough i dont have  bool operator==(float , const Fraction & f2) func , the compiler convert the float to
 /// Fraction by himself and then enter to this function !
 bool operator==(const Fraction &f1, const Fraction & f2) {
        bool b =  (f1 < f2) || ( f2<f1);
        if (b)
            return false;
        return true;
}

Fraction& Fraction::operator++() {
    *this  =(*this)+ 1 ;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction ans = *this;
    *this = *this +1 ;
    return ans ;
}

Fraction &Fraction::operator--() {
    *this  =(*this)- 1 ;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction ans = *this;
    *this = *this -1 ;
    return ans ;
}

ostream &operator<<(ostream &ostream, Fraction f) {
    ostream << f.numerator << "/" << f.denominator;
    return ostream;
}
///https://www.geeksforgeeks.org/isdigit-function-in-c-cpp-with-examples/
///https://www.geeksforgeeks.org/basic_istreamoperator-in-c/
void operator>>(istream &in, Fraction f) {
           if(isdigit(in.peek()))
               in >> f.numerator ;
           if( !in.eof() && isdigit(in.peek()))
               in >> f.denominator;
           else
               throw;
}
//operator to read a fraction from an input stream by taking two integers as input.





















