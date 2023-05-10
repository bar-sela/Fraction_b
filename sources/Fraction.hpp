//
// Created by Nachshon on 4/30/2023.
//

#ifndef INC_3B_FRACTION_HPP
#define INC_3B_FRACTION_HPP

#include <iostream>
#include <limits>
#include <cmath>
namespace ariel{

}
using namespace std;

#define EPS 0.0001;
#define THOUSEND 1000;
class Fraction {

private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (this->denominator == 0)
        {
            throw std::invalid_argument("");
        }
        int gcd = _gcd(numerator , denominator);
        this->numerator = numerator / gcd;
        this->denominator= denominator / gcd;

    }
    void set(float number);

    Fraction(): numerator(-1), denominator(-1){}
    Fraction(float number) : numerator(-1) ,denominator(-1) {
        this->set(number);
    }
    /// reduced function
    void red(){
        int gcd = _gcd(numerator , this->denominator);
        this->numerator = this->numerator/ gcd;
        this->denominator = this->denominator/ gcd;
    }
    ///plus
    friend Fraction operator+(const Fraction& , const Fraction& );
    Fraction operator+(float   );
    friend Fraction operator+(float  , const Fraction&  );
    /// minus
    friend Fraction operator-(const Fraction& , const Fraction& );
    Fraction operator-(float );
    friend  Fraction operator-(float   , const Fraction& );
    ///mul
    friend Fraction operator*(const Fraction& , const Fraction& );
    friend Fraction operator *(float , const Fraction &);
   ///divide
    Fraction operator/(const Fraction& ) const;
    friend Fraction operator /(float , const Fraction & );
    friend Fraction operator /(const Fraction & , float );
    /// < , <=  , > , >=
    ///<=
    bool operator <= (Fraction const &) const;
    friend bool operator<=(float , Fraction const& );
    /// >
    bool operator > (Fraction const & ) const;
    friend bool operator>(float  , Fraction const& );
    /// <
    bool operator<(Fraction const &other) const;
    friend bool operator<(float, Fraction const& );
    /// >=
    friend bool operator>=(float  ,const Fraction & );
    bool operator >= (Fraction const&) const;
    /// ==
    friend bool operator == (Fraction const&  , Fraction const& ) ;
    /// ++
    Fraction& operator ++ ();
    Fraction operator ++ (int);
    /// --
    Fraction& operator -- ();
    Fraction operator -- (int);
    /// <<
    friend ostream& operator << (ostream&  ,  Fraction & );
    /// >>
    friend istream & operator >> (istream &  ,  Fraction&  );
    /// reduce
    static int _gcd(  long long ,   long long ) ;
    int getDenominator() const {
        return this->denominator;
    }

    int getNumerator() const {
        return this->numerator;
    }


};



#endif //INC_3B_FRACTION_HPP
