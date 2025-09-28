#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPSILON = 0.001;

string triangle(int a, int b, int c)
{
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);

    
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        return " not a triangle";
    }

    if (a + b <= c)
    {
        return "not a triangle";
    }

    bool isRight = (a * a + b * b == c * c);
    string prefix = isRight ? "Right " : "";

    if (a == b && b == c)
    {
        return prefix + "Equilateral triangle";
    }
    else if (a == b || b == c)
    {
        return prefix + "Isosceles triangle";
    }
    else
    {
        return prefix + "Scalene triangle";
    }
}

string triangle(double a, double b, double c)
{
   
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);

    
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        return "not a triangle";
    }

    if (a + b - EPSILON <= c)
    {
        return "not a triangle";
    }

    bool isRight = (fabs(a * a + b * b - c * c) < EPSILON);

    string prefix = isRight ? "Right " : "";

    if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON)
    {
        return prefix + "Equilateral triangle" ;
    }
    else if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON)
    {
        return  prefix + "Isosceles triangle";
    }
    else
    {
       return  prefix + "Scalene triangle";
    }
}

int main(int argc, char* argv[])
 {
    if (argc == 1) 
    {
        cout << "Please enter three side lengths: ";
        int a, b, c;
        if (cin >> a >> b >> c) 
        {
            int orig_a = a, orig_b = b, orig_c = c;
            string result = triangle(a, b, c);
            cout << orig_a << " " << orig_b << " " << orig_c << " " << result << endl;
        } 
        else 
        {
            cerr << "Invalid" << endl;
            return 1;
        }
    }
    else if (argc == 2 && string(argv[1]) == "-d")
     {
        double da, db, dc;
        cout << "Please enter three side lengths: ";
        if (cin >> da >> db >> dc) 
        {
            double orig_a = da, orig_b = db, orig_c = dc;
            string result = triangle(da, db, dc);
            cout << fixed << setprecision(5) << orig_a << " " << orig_b << " " << orig_c << " " 
             << result << endl;
        } 
        else 
        {
            cerr << "Invalid" << endl;
            return 1;
        }
    }
    else if (argc == 4) 
    {
        for (int i = 1; i < 4; i++) 
        {
            for (int j = 0; argv[i][j] != '\0'; j++) 
            {
                if (!isdigit(argv[i][j]) && argv[i][j] != '-')
                 {
                    cerr << "Error command line arguments" << endl;
                    return 1;
                }
            }
        }
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);
        string result = triangle(a, b, c);
        cout << a << " " << b << " " << c << " " << result << endl;
    }
    else 
    {
        cerr << argv[0] << " [-d] [side1 side2 side3]" << endl;
        return 1;
    }
    return 0;
}
