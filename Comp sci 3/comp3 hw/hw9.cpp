#include <iostream>
#include <numeric>
using namespace std;

class Rational 
{
private:
    int numerator;
    int denominator;

int gcd(int a, int b)
 {
    return b == 0 ? a : gcd(b, a % b);
}

    void reduce() 
    {
        int gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
        if (denominator < 0) 
        { 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom)
     {
        if (denom == 0) throw invalid_argument("Denominator cannot be zero.");
        reduce();
    }

    int getNumerator() 
    const { 
        return numerator;
         }
    int getDenominator() 
    const { 
        return denominator; 
    }

    Rational operator+(const Rational& other) 
    const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator-(const Rational& other) 
    const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator*(const Rational& other)
     const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) 
    const {
        if (other.numerator == 0) throw invalid_argument("Division by zero.");
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    Rational operator-() 
    const {
        return Rational(-numerator, denominator);
    }

    friend ostream& operator<<(ostream& os, const Rational& r) 
    {
        if (r.denominator == 1) os << r.numerator;
        else os << r.numerator << '/' << r.denominator;
        return os;
    }
};


template<typename T>
class MyComplex 
{
private:
    T real;
    T imag;

public:
    MyComplex() : real(0), imag(0) {}
    MyComplex(T r) : real(r), imag(0) {}
    MyComplex(T r, T i) : real(r), imag(i) {}

    T getReal() const { return real; }
    T getImag() const { return imag; }

    void setReal(T r) { real = r; }
    void setImag(T i) { imag = i; }

    void conjugate() { imag = -imag; }

    MyComplex<T> conjugated() const {
        return MyComplex<T>(real, -imag);
    }

    MyComplex<T> operator+(const MyComplex<T>& other) const {
        return MyComplex<T>(real + other.real, imag + other.imag);
    }

    MyComplex<T> operator*(const MyComplex<T>& other) const {
        T r = (real * other.real) - (imag * other.imag);
        T i = (real * other.imag) + (imag * other.real);
        return MyComplex<T>(r, i);
    }

    friend ostream& operator<<(ostream& os, const MyComplex<T>& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

int main(int argc, char* argv[]) 
{
  

    // Test 1: Basic addition
    Rational a(1, 2); 
    Rational b(1, 3); 
    Rational c(1, 4); 
    Rational d(1, 6); 

    MyComplex<Rational> c1(a, b); 
    MyComplex<Rational> c2(c, d);

    cout << "Test 1: Addition\n";
    cout << "c1 = " << c1 << "\n";
    cout << "c2 = " << c2 << "\n";
    cout << "c1 + c2 = " << (c1 + c2) << "\n\n";

    // Test 2: Multiplication
    cout << "Test 2: Multiplication\n";
    cout << "c1 * c2 = " << (c1 * c2) << "\n\n";

    // Test 3: Conjugates
    cout << "Test 3: Conjugates\n";
    cout << "conj(c1) = " << c1.conjugated() << "\n";
    cout << "conj(c2) = " << c2.conjugated() << "\n\n";

    // Test 4: One zero component
    MyComplex<Rational> Real(Rational(2, 1), Rational(0));  
    MyComplex<Rational> Imag(Rational(0), Rational(3, 1)); 

    cout << "Test 4: real and imaginary\n";
    cout << "Real = " << Real << "\n";
    cout << "Imag = " << Imag << "\n";
    cout << "Sum = " << (Real + Imag) << "\n";
    cout << "Product = " << (Real * Imag) << "\n\n";

    return 0;
}
