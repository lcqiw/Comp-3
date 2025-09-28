#include <iostream>
#include <string>
using namespace std;

// Month class as required by the lab
class Month {
private:
    int monthNumber;
    string monthName;
    string monthAbbrev;

public:
    // Default constructor
    Month() : monthNumber(1), monthName("January"), monthAbbrev("Jan") {}

    // Constructor with month number
    Month(int num) {
        setMonthNumber(num);
    }

    // Constructor with month abbreviation
    Month(string abbrev) {
        if (abbrev == "Jan") {
            monthNumber = 1;
            monthName = "January";
            monthAbbrev = "Jan";
        } else if (abbrev == "Feb") {
            monthNumber = 2;
            monthName = "February";
            monthAbbrev = "Feb";
        } else if (abbrev == "Mar") {
            monthNumber = 3;
            monthName = "March";
            monthAbbrev = "Mar";
        } else if (abbrev == "Apr") {
            monthNumber = 4;
            monthName = "April";
            monthAbbrev = "Apr";
        } else if (abbrev == "May") {
            monthNumber = 5;
            monthName = "May";
            monthAbbrev = "May";
        } else if (abbrev == "Jun") {
            monthNumber = 6;
            monthName = "June";
            monthAbbrev = "Jun";
        } else if (abbrev == "Jul") {
            monthNumber = 7;
            monthName = "July";
            monthAbbrev = "Jul";
        } else if (abbrev == "Aug") {
            monthNumber = 8;
            monthName = "August";
            monthAbbrev = "Aug";
        } else if (abbrev == "Sep") {
            monthNumber = 9;
            monthName = "September";
            monthAbbrev = "Sep";
        } else if (abbrev == "Oct") {
            monthNumber = 10;
            monthName = "October";
            monthAbbrev = "Oct";
        } else if (abbrev == "Nov") {
            monthNumber = 11;
            monthName = "November";
            monthAbbrev = "Nov";
        } else if (abbrev == "Dec") {
            monthNumber = 12;
            monthName = "December";
            monthAbbrev = "Dec";
        } else {
            // Default to January if invalid
            monthNumber = 1;
            monthName = "January";
            monthAbbrev = "Jan";
        }
    }

    // Setter for month number
    void setMonthNumber(int num) {
        if (num >= 1 && num <= 12) {
            monthNumber = num;
            switch (num) {
                case 1:
                    monthName = "January";
                    monthAbbrev = "Jan";
                    break;
                case 2:
                    monthName = "February";
                    monthAbbrev = "Feb";
                    break;
                case 3:
                    monthName = "March";
                    monthAbbrev = "Mar";
                    break;
                case 4:
                    monthName = "April";
                    monthAbbrev = "Apr";
                    break;
                case 5:
                    monthName = "May";
                    monthAbbrev = "May";
                    break;
                case 6:
                    monthName = "June";
                    monthAbbrev = "Jun";
                    break;
                case 7:
                    monthName = "July";
                    monthAbbrev = "Jul";
                    break;
                case 8:
                    monthName = "August";
                    monthAbbrev = "Aug";
                    break;
                case 9:
                    monthName = "September";
                    monthAbbrev = "Sep";
                    break;
                case 10:
                    monthName = "October";
                    monthAbbrev = "Oct";
                    break;
                case 11:
                    monthName = "November";
                    monthAbbrev = "Nov";
                    break;
                case 12:
                    monthName = "December";
                    monthAbbrev = "Dec";
                    break;
            }
        } else {
            // Default to January if invalid
            monthNumber = 1;
            monthName = "January";
            monthAbbrev = "Jan";
        }
    }

    // Getters
    int getMonthNumber() const { return monthNumber; }
    string getMonthName() const { return monthName; }
    string getMonthAbbrev() const { return monthAbbrev; }
};

class Date
{
public:
    // Default constructor
    Date() : month(1), day(1), year(2022) {}
 
    // Value constructor with month as integer and optional day and year
    Date(int iMonth, int iDay = 1, int iYear = 2022) : month(iMonth), day(iDay), year(iYear) {}
 
    // Value constructor with month as string and optional day and year
    Date(string newMonth, int iDay = 1, int iYear = 2022) : month(newMonth), day(iDay), year(iYear) {}
 
    // Setter for month
    void setMonth(int newMonth) 
    {
        month.setMonthNumber(newMonth);
    }
 
    // Output date as integer format (e.g., 12/31/2022)
    void outputDateAsInt(ostream& out) const
    {
        out << month.getMonthNumber() << "/" << day << "/" << year;
    }
 
    // Output date as string format (e.g., Dec 31, 2022)
    void outputDateAsString(ostream& out) const
    {
        out << month.getMonthAbbrev() << " " << day << ", " << year;
    }
 
    // Pre-increment operator (++date) - increments the year
    Date& operator++()
    {
        ++year;
        return *this;
    }
 
    // Friend function for insertion operator
    friend ostream& operator<<(ostream& out, const Date& myDate);

private:
    Month month; // Using Month class as required
    int day;
    int year;
};

// Implementation of insertion operator overload
ostream& operator<<(ostream& out, const Date& myDate)
{
    out << myDate.month.getMonthName() << " " << myDate.day << ", " << myDate.year;
    return out;
}

int main()
{
    cout << "With the following declarations:" << endl;
    cout << "     Date d1, d2(5, 26, 2022), d3(\"May\", 30, 2022);" << endl << endl;
    
    Date d1, d2(5, 26, 2022), d3("May", 30, 2022);
    
    cout << "...and using operator<< :" << endl;
    cout << "d1 == " << d1 << endl;
    cout << "d2 == " << d2 << endl;
    cout << "d3 == " << d3 << endl << endl;
    
    cout << "After d3.setMonth(4):" << endl;
    d3.setMonth(4);
    cout << "d3 == " << d3 << endl << endl;
    
    cout << "With the following declaration:" << endl;
    cout << "     Date d4(12, 31, 2022);" << endl << endl;
    
    Date d4(12, 31, 2022);
    
    cout << "d4.outputDateAsInt(cout) outputs ";
    d4.outputDateAsInt(cout);
    cout << endl;
    
    cout << "d4.outputDateAsString(cout) outputs ";
    d4.outputDateAsString(cout);
    cout << endl;
    
    ++d4;
    cout << "++d4 == " << d4 << endl;
    
    return 0;
}