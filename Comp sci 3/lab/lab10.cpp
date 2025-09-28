#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

const int IGNORE_SIZE = 256;
const double MAX_DOUBLE = numeric_limits<double>::max();


class input_exception
 {
private:
    string msg;
public:
    input_exception(const string& m) : msg(m) {}

    string getMessage() 
    const {
        return msg;
    }
};

template<typename T>
T checkInput(T lower, T upper, const string& message)
{
    T in;
    if (!(cin >> in) || in < lower || in > upper)
     {
        cin.clear();
        cin.ignore(IGNORE_SIZE, '\n');
        throw input_exception(message);
    }
    return in;
}

class Mass
 {
public:
    Mass()
        : drams(0.0),
          dramGrams(1.7718451953125),
          dramAvoirdupois(1.0 / 256.0),
          dramTroy(1.0 / 96.0) 
          {}

    void setMassAvoirdupoisPounds(double value) 
    {
        drams = value / dramAvoirdupois;
    }

    void setMassTroyPounds(double value) 
    {
        drams = value / dramTroy;
    }

    void setMassMetricGrams(double value) 
    {
        drams = value / dramGrams;
    }

    double getMassAvoirdupoisPounds()
     const {
        return drams * dramAvoirdupois;
    }

    double getMassTroyPounds() 
    const {
        return drams * dramTroy;
    }

    double getMassMetricGrams() 
    const {
        return drams * dramGrams;
    }

private:
    double drams;
    const double dramGrams;
    const double dramAvoirdupois;
    const double dramTroy;
};


int main(int argc, char* argv[])
{
    int choice;
    double inputMass;
    Mass m;

    while (true) 
    {
        while (true)
         {
            try {
                cout << "Enter 1 for Avoirdupois 2 for Troy, 3 for grams or 0 to exit: ";
                choice = checkInput(0, 3, "Error enter a number between 0 and 3.");
                break;
            } catch (const input_exception& e)
            {
    cout << e.getMessage() << "\n";

            }
        }

        if (choice == 0) {
            cout << "Finished!\n";
            break;
        }

        while (true) 
        {
            try {
                if (choice == 1) 
                {
                    cout << "Enter mass in Avoirdupois pounds: ";
                    inputMass = checkInput(0.0, MAX_DOUBLE, "Mass must be >= 0.");
                    m.setMassAvoirdupoisPounds(inputMass);
                }
                 else if (choice == 2) 
                {
                    cout << "Enter mass in Troy pounds: ";
                    inputMass = checkInput(1.0, MAX_DOUBLE, "Troy mass must be >= 1.");
                    m.setMassTroyPounds(inputMass);
                } 
                else if (choice == 3) 
                {
                    cout << "Enter mass in grams: ";
                    inputMass = checkInput(1.0, MAX_DOUBLE, "Grams must be >= 1.");
                    m.setMassMetricGrams(inputMass);
                }
                break;
            } 
            catch (const input_exception& e)
             {
            cout << e.getMessage() << "\n";
            }
        }

        cout << "Mass in Avoirdupois pounds: " << m.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds: " << m.getMassTroyPounds() << endl;
        cout << "Mass in grams: " << m.getMassMetricGrams() << endl << endl;
    }

    return 0;
}
