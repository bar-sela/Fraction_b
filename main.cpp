#include <iostream>
#include <math.h>
#include "sources/Fraction.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

int d(float w ){
    std::cout << std::fixed << std::setprecision(2) << w << std::endl;
    return 0;
}

int main() {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    Fraction f1(max_int, 1);

    // Test arithmetic with large numerator and/or denominator
    Fraction f4(max_int - 100, max_int);

    (f1 * f4);
    (f1 / f4);

}
