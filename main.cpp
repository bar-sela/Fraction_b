#include <iostream>
#include <math.h>
#include "sources/Fraction.hpp"

#include <iostream>
#include <string>
#include <sstream>

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name(name), age(age) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }
};

int main() {
    Fraction a(2, 5);
    float b = 0.2001; // During the "+" operation it'll became 0.200, which is 1/5
    Fraction c = a + b; // 2/5 + 1/5 = 3/5
    cout<<(((c.getNumerator() == 3) && (c.getDenominator() == 5)))<< endl ;

    b = 0.2001;
    c = a - b; // 1/5
    cout<<(((c.getNumerator() == 1) && (c.getDenominator() == 5)))<< endl ;

    b = 0.2001;
    c = a * b; // 2/25
    cout<<(((c.getNumerator() == 2) && (c.getDenominator() == 25)))<< endl ;

    b = 0.2001;
    c = a / b; // 2/1
    cout<<(((c.getNumerator() == 2) && (c.getDenominator() == 1)))<< endl ;
}
