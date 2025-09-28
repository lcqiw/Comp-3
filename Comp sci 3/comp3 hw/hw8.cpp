#include <iostream>
#include <stdexcept>

using namespace std;

class Rational {
private:
    long numerator;
    long denominator;

    static long gcd(long a, long b) 
    {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() 
    {
        long divisor = gcd(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;

        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(long num) : numerator(num), denominator(1) {}

    Rational(long num, long denom)
     {
        if (denom == 0) 
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = denom;
        simplify();
    }

    Rational operator+(const Rational& rhs)
    const {
        long num = numerator * rhs.denominator + rhs.numerator * denominator;
        long denom = denominator * rhs.denominator;
        return Rational(num, denom);
    }

    Rational operator-(const Rational& rhs) 
    const {
        long num = numerator * rhs.denominator - rhs.numerator * denominator;
        long denom = denominator * rhs.denominator;
        return Rational(num, denom);
    }

    
    Rational operator*(const Rational& rhs)
     const {
        long num = numerator * rhs.numerator;
        long denom = denominator * rhs.denominator;
        return Rational(num, denom);
    }

    Rational operator/(const Rational& rhs) 
    const {
        if (rhs.numerator == 0)
         {
            throw invalid_argument("Cannot divide by zero.");
        }
        long num = numerator * rhs.denominator;
        long denom = denominator * rhs.numerator;
        return Rational(num, denom);
    }

    friend ostream& operator<<(ostream& out, const Rational& r) 
    {
        out << r.numerator << "/" << r.denominator;
        return out;
    }
};
int main(int argc, char* argv[])
 {
    try {
        Rational r1(6, 8);     
        Rational r2(-2, 5);    
        Rational r3(4);        
        Rational r4;           

        std::cout << "r1 = " << r1 << "\n";
        std::cout << "r2 = " << r2 << "\n";
        std::cout << "r3 = " << r3 << "\n";
        std::cout << "r4 = " << r4 << "\n";

        std::cout << "r1 + r2 = " << (r1 + r2) << "\n";
        std::cout << "r1 - r2 = " << (r1 - r2) << "\n";
        std::cout << "r1 * r2 = " << (r1 * r2) << "\n";
        std::cout << "r1 / r2 = " << (r1 / r2) << "\n";

        Rational fail(5, 0); 

    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
