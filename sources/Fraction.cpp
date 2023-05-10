#include "Fraction.hpp"
#include "iostream"
#include "algorithm"
#include <sstream>

/////// help functions
int MAX_INT(){
    return std::numeric_limits<int>::max();
}
int MIN_INT(){
    return std::numeric_limits<int>::min();
}
void overFlowCheak(long long num){
    if(num > MAX_INT())
        throw std::overflow_error("to BIG number");
    if(num < MIN_INT())
        throw std::overflow_error("to SMALL number");
}
bool isInteger(const std::string& str) {
    if(str.find('.') == 1)
        return false;
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}
void Fraction::set(float number)
{
    float eps = EPS;
    number =number +eps;
    float Thousend = THOUSEND;
    number= floor(number*Thousend);
    this->numerator =  (int)number;
    this->denominator = THOUSEND;
}

int Fraction::_gcd(  long long a,   long long b) {
    int temp = (int)a ;
    if (b > a ){ /// swap
        a = b ;
        b = temp;
    }
    a = abs(a); /// for negative values
    b= abs(b);
    if (b == 0)
        return (int)a;
    else
        return __gcd(b, (a % b));
}
///////// operators
Fraction operator+(const Fraction &x1,const Fraction& x2) {
     long long newX1N =  ( long long)x1.numerator *   ( long long)x2.denominator;
     long long newX2N =  ( long long)x2.numerator *   ( long long)x1.denominator;
     long long mulDeno = x1.denominator* x2.denominator;
     long long sumOfNewN =  newX1N + newX2N ;
    overFlowCheak(sumOfNewN);
    overFlowCheak(mulDeno);
    return Fraction(sumOfNewN , mulDeno);
}
Fraction Fraction::operator+(float f) {
    Fraction fFrac = Fraction(f);
    return *this + fFrac;
}
Fraction operator+(float  x1, const Fraction& frac) {
    Fraction frac_x1 = Fraction(x1);
    return frac + frac_x1 ;
}



Fraction operator-(const Fraction& plus, const Fraction& minus) {
    long long newX1N = ( long long)plus.numerator*  ( long long)minus.denominator;
    long long newX2N =  ( long long)minus.numerator *  ( long long)plus.denominator;
    long long mulDeno = plus.denominator *minus.denominator;
    long  long subtractOfNewN =    newX1N - newX2N ;
    overFlowCheak(mulDeno);
    overFlowCheak(subtractOfNewN);
    Fraction ans =  Fraction(subtractOfNewN , mulDeno);
    return ans;
}

Fraction Fraction::operator-(float x) {
    Fraction represetX = Fraction(x);
    return (*this - represetX);
}

Fraction operator-(float x, const Fraction& frac) {
    Fraction represetX = Fraction(x);
    return (represetX - frac);
}

Fraction operator*(const Fraction& f1,const  Fraction &f2) {
    long long mulNUM = (long long )f1.numerator * (long long )f2.numerator;
    long long mulDEN = (long long )f1.denominator * (long long )f2.denominator;
    overFlowCheak(mulDEN);   /// if there is an error it will throw exeption inside overFlowCheak
    overFlowCheak(mulNUM);
    Fraction ans = Fraction(mulNUM  , mulDEN );
    return ans;
}

Fraction operator*(float x,const Fraction& f) {
    Fraction x_frac = Fraction(x);
    return (f * x_frac);
}

/// divied
Fraction Fraction::operator/(const Fraction& other) const{
    if(other.numerator == 0)
        throw std::runtime_error("");
    long  long  mulNUM = (long long)this->numerator * (long long)other.denominator;
    long  long  mulDEN = (long long)this->denominator * (long  long )other.numerator;
    overFlowCheak(mulNUM);
    overFlowCheak(mulDEN);
    Fraction ans = Fraction(mulNUM  , mulDEN );
    return ans;
}
Fraction operator /(float f, const Fraction & x ) {
    Fraction x_frac = Fraction(f);
    return(x_frac / x );
}

Fraction operator /(const Fraction &x , float f ){
    Fraction x_frac = Fraction(f);
    return( x / x_frac);
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
    *this = *this + 1 ;
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

ostream & operator<<(ostream &ostream,  Fraction & f) {
    if((f.numerator < 0 && f.denominator > 0 ) || (f.denominator < 0 && f.numerator > 0  ))
        ostream << "-";
    f.numerator = abs( f.numerator);
    f.denominator = abs( f.denominator);
    f.red();
    ostream << f.numerator << "/" << f.denominator;
    return ostream;
}
static int correctInput(istream& in) {
    string reader;
    in >> reader;
    int num ;
    num = isInteger(reader);   /// returnes True Or False
    if(num)
        return stoi(reader);
    throw std::runtime_error("") ;
    }
///https://www.geeksforgeeks.org/isdigit-function-in-c-cpp-with-examples/
///https://www.geeksforgeeks.org/basic_istreamoperator-in-c/
istream &operator>>(istream& in,  Fraction & f ){
         string final_input;
         f.numerator = correctInput(in );
         int den  = correctInput(in);
         if(den == 0 )
             throw std::runtime_error("");
         f.denominator = den;
         return in;
}
















