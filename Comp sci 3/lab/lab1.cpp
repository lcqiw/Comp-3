#include <iostream>
#include <cstdlib>
#include <ctime>

double calculateTotalInterest(double interest, double amt, int period);
double calculateAmtRec(double faceValue, double totalInterest);
double calculateFaceValue(double amt, double interest, int period);
double calculateMonthly(double faceValue, int period);
double getValue(const std::string& str, int condition1);

void outputResults(double interest, double amount, double period);
int main(int argc, char*argv[])
{
   
    double interest = -1.0;
    double amount = -1.0;
    double period = -1.0;
    using namespace std;
   
    while(1)
    {
        interest = getValue("Please enter the annual interest rate as an INTEGER (e.g 15%% would be entered as 15) (enter 0 to exit)", 0);
        if (interest == 0.0)
        {
            exit(1);
        }
        
        amount = getValue("Please enter the amount you would like to receive: )", 0);
        period = getValue("Please enter your loan period in months: ", 0);
        
        outputResults(interest, amount, period);
        
        
    }
    
}
double calculateTotalInterest(double interest, double amt, int period)
{
    // face value * interest rate * duration (year)
    double year = static_cast<double>(period) / 12;
    return amt * (interest/100) * year;
}
double calculateAmtRec(double faceValue, double totalInterest)
{
    // face value - total interests
    return faceValue - totalInterest;
}
double calculateFaceValue(double amt, double interest, int period)
{
    // amount received / (1 - interest rate * duration(year))
    double year = static_cast<double>(period) / 12;
    return amt / (1 - (interest/100) * year);
}

double calculateMonthly(double faceValue, int period)
{
    // face value / duration(month)
    return faceValue / static_cast<double>(period);
}

double getValue(const std::string& str, int condition1)
{
    int variable = -1;
    using namespace std;
    
    do {
        cout << endl << str;
        cin >> variable;
        cin.clear();
        cin.ignore(1000, '\n');
        
    } while (variable < condition1);
    
    return static_cast<double>(variable);
}

void outputResults(double interest, double amount, double period)
{
    using namespace std;
    cout << endl << "The total amount of your loan (including interest at " << interest << " per annum) is $" << calculateFaceValue(amount, interest, period);
    cout << endl << "Your monthly payment for 12 months will be $" <<calculateMonthly(calculateFaceValue(amount, interest, period), period);
    
}