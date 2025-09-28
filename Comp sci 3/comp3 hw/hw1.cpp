#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int strToInt(const char* str)
{
    return stoi(string(str)); 
}

void triangle(int a, int b, int c)
{
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);

    cout << a << " " << b << " " << c << " ";


    if (a + b <= c) 
    {
        cout << "Incomplete triangle" << endl;
        return;
    }
    
    bool isRight = (a * a + b * b == c * c);
    
    if (a == b && b == c)
    {
        cout << "Equilateral triangle" << endl;

    } 
    else if (a == b || b == c)
     {
        cout << (isRight ? "Right Isosceles triangle" : "Isosceles triangle") << endl;
    } 
    else 
    {
        cout << (isRight ? "Right Scalene triangle" : "Scalene triangle") << endl;
    }
}

int main(int argc, char* argv[]) 
{
    int a, b, c;
    
    if (argc == 1) 
    { 
        cout << "Please enter three side lengths: ";
        cin >> a >> b >> c;
    }
    else if (argc != 4)
    { 
        cerr << "Error only 3 side lengths." << endl;
        return 1;
    } 
    else 
    { 
        a = strToInt(argv[1]);
        b = strToInt(argv[2]);
        c = strToInt(argv[3]);
    }
    
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        cerr << "Error all side lengths must be positive." << endl;
        return 1;
    }
    
    triangle(a, b, c);
    
    return 0;
}


