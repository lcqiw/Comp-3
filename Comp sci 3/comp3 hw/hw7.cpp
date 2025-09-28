#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>

template<typename T>
class MyComplex 
{
private:
    T real;
    T imag;

public:
    MyComplex() : real(0), imag(0) 
    {}
    MyComplex(T r) : real(r), imag(0) 
    {}
    MyComplex(T r, T i) : real(r), imag(i) 
    {}

    T getReal() 
    const { 
        return real; 
        }
    T getImag() 
    const { 
        return imag; 
        }

    void setReal(T r) 
    { 
        real = r; 
    }
    void setImag(T i) 
    { 
        imag = i; 
    }

    void conjugate() 
    {
         imag = -imag; 
    }

    MyComplex<T> conjugated() 
    const {
        return MyComplex<T>(real, -imag);
    }

    MyComplex<T> operator+(const MyComplex<T>& other) 
    const {
        return MyComplex<T>(real + other.real, imag + other.imag);
    }

    MyComplex<T> operator-(const MyComplex<T>& other)
     const {
        return MyComplex<T>(real - other.real, imag - other.imag);
    }

    MyComplex<T> operator*(const MyComplex<T>& other) 
    const {
        return MyComplex<T>(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    MyComplex<T> operator/(const MyComplex<T>& other) 
    const {
        MyComplex<T> conj = other.conjugated();
        MyComplex<T> num = (*this) * conj;
        T denom = other.real * other.real + other.imag * other.imag;
        return MyComplex<T>(num.real / denom, num.imag / denom);
    }

    MyComplex<T> operator+(T val) 
    const {
        return MyComplex<T>(real + val, imag);
    }

    MyComplex<T> operator-(T val) 
    const {
        return MyComplex<T>(real - val, imag);
    }

    MyComplex<T> operator*(T val) 
    const {
        return MyComplex<T>(real * val, imag * val);
    }

    MyComplex<T> operator/(T val) 
    const {
        return MyComplex<T>(real / val, imag / val);
    }

    friend MyComplex<T> operator+(T val, const MyComplex<T>& c)
     {
        return MyComplex<T>(val + c.real, c.imag);
    }

    friend MyComplex<T> operator-(T val, const MyComplex<T>& c) 
    {
        return MyComplex<T>(val - c.real, -c.imag);
    }

    friend MyComplex<T> operator*(T val, const MyComplex<T>& c)
     {
        return MyComplex<T>(val * c.real, val * c.imag);
    }

    friend std::ostream& operator<<(std::ostream& os, const MyComplex<T>& c) 
    {
        if (c.real == 0 && c.imag == 0)
            os << "0";
        else if (c.real == 0)
            os << c.imag << "i";
        else if (c.imag == 0)
            os << c.real;
        else
            os << c.real << (c.imag > 0 ? "+" : "") << c.imag << "i";
        return os;
    }


    friend std::istream& operator>>(std::istream& is, MyComplex<T>& c) 
    {
        std::string input;
        std::getline(is, input);
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        size_t i_pos = input.find('i');
        c.real = 0;
        c.imag = 0;

        if (i_pos != std::string::npos) 
        {
            input.erase(i_pos, 1);
            size_t plus = input.find('+', 1);
            size_t minus = input.find('-', 1);
            size_t sep = std::min(
                plus != std::string::npos ? plus : input.size(),
                minus != std::string::npos ? minus : input.size()
            );

            if (sep < input.size()) 
            {
                c.real = static_cast<T>(std::stod(input.substr(0, sep)));
                c.imag = static_cast<T>(std::stod(input.substr(sep)));
            } else {
                c.imag = static_cast<T>(std::stod(input));
            }
        } else {
            c.real = static_cast<T>(std::stod(input));
        }
        return is;
    }
};

int main(int argc, char* argv[]) 
{
    std::cout << "Testing MyComplex with DOUBLE \n";
    MyComplex<double> d1(2.5, 3.2), d2(1.1, -4.5);
    std::cout << "d1 = " << d1 << "\n";
    std::cout << "d2 = " << d2 << "\n";
    std::cout << "d1 + d2 = " << (d1 + d2) << "\n";
    std::cout << "d1 - d2 = " << (d1 - d2) << "\n";
    std::cout << "d1 * d2 = " << (d1 * d2) << "\n";
    std::cout << "d1 / d2 = " << (d1 / d2) << "\n";
    std::cout << "Conjugate of d1: ";
    d1.conjugate();
    std::cout << d1 << "\n\n";

    std::cout << "Testing MyComplex with INT \n";
    MyComplex<int> i1(3, 2), i2(1, -1);
    std::cout << "i1 = " << i1 << "\n";
    std::cout << "i2 = " << i2 << "\n";
    std::cout << "i1 + i2 = " << (i1 + i2) << "\n";
    std::cout << "i1 - i2 = " << (i1 - i2) << "\n";
    std::cout << "i1 * i2 = " << (i1 * i2) << "\n";
    std::cout << "i1 * 3 = " << (i1 * 3) << "\n";
    std::cout << "3 * i1 = " << (3 * i1) << "\n";
    std::cout << "i1 + 5 = " << (i1 + 5) << "\n";
    std::cout << "5 - i1 = " << (5 - i1) << "\n";

    return 0;
}
