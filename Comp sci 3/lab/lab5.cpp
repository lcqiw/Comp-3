#include <iostream>
#include <vector>
#include <iomanip>

class ComplexNumber
 {
private:
    int real;
    int imag;

public:

    ComplexNumber() : real(0), imag(0)  
    {

    }

    ComplexNumber(int r, int i) : real(r), imag(i) 
    {

    }

    int getReal() const 
    { 
        return real; 
    }
    int getImag() const 
    { 
        return imag; 
    }

    void setReal(double r) 
    { 
        real = r; 
    }
    void setImag(double i) 
    { 
        imag = i; 
    }

    // Friend functions for operator overloading
    friend ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);
    friend ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2);
    friend ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2);
    friend ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2);
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& c);

    // complex conjugate
    ComplexNumber operator!() const 
    {
        return ComplexNumber(real, -imag); 
    }
};

// Overloaded + operator
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) 
{
    return ComplexNumber(c1.real + c2.real, c1.imag + c2.imag);
}

// Overloaded - operator
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2) 
{
    return ComplexNumber(c1.real - c2.real, c1.imag - c2.imag);
}

// Overloaded * operator
ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2) 
{
    return ComplexNumber(c1.real * c2.real - c1.imag * c2.imag,
    c1.real * c2.imag + c1.imag * c2.real);
}

// Overloaded / operator
ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2) 
{
    int denominator = c2.real * c2.real + c2.imag * c2.imag;
    return ComplexNumber(std::round((c1.real * c2.real + c1.imag * c2.imag) / denominator * 100) / 100,
 std::round((c1.imag * c2.real - c1.real * c2.imag) / denominator * 100) / 100);
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& out, const ComplexNumber& c) 
{
    out << std::fixed << std::setprecision(2) << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return out;
}

int main(int argc, char* argv[]) 
{
    // Test  ComplexNumber class
    ComplexNumber c1;
    ComplexNumber c2(1, 2);
    ComplexNumber c3(3, 4);
    
    std::cout << "Value of c1 (default constructor):\n";
    std::cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImag() << "\n";
    
    std::cout << "Value of c2 (value constructor):\n";
    std::cout << "c2.Re() == " << c2.getReal() << ", c2.Im() == " << c2.getImag() << "\n";
    
    std::cout << "c2 + c3 (1+2i + 3+4i) == " << c2 + c3 << "\n";
    std::cout << "c2 - c3 (1+2i - 3+4i) == " << c2 - c3 << "\n";
    std::cout << "c2 * c3 (1+2i * 3+4i) == " << c2 * c3 << "\n";
    std::cout << "c2 / c3 (1+2i / 3+4i) == " << c2 / c3 << "\n";
    std::cout << "(c2/c3) + (c2*c3) == " << (c2 / c3) + (c2 * c3) << "\n";
    
    std::cout << "c2 is currently " << c2 << "; !c2 (complex conjugate of c2) == " << !c2 << "\n";
    
    // Create a vector of 10 complex numbers
    std::vector<ComplexNumber> vec;
    for (int n = 0; n < 10; ++n) {
        vec.push_back(ComplexNumber(n, 2 * n));  
    }

    std::cout << "\nVector output using indexed for-loop:" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        std::cout << vec[i] << "\n";
    }
    
    std::cout << "\nVector output using an iterator in for-loop:" << std::endl;
    for (std::vector<ComplexNumber>::iterator it = vec.begin(); it != vec.end(); ++it)
    {  
        std::cout << *it << "\n";
    }
    
    return 0;
}
