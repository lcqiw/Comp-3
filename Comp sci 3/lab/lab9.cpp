#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UMLPerson {
protected:
    string _first, _last, _address;
    int _id;
public:
    UMLPerson(string f = "NoFirst", string l = "NoLast", string a = "NoAddress", int id = 0)
        : _first(f), _last(l), _address(a), _id(id) {}

    virtual ~UMLPerson() 
    {}

    virtual void display() 
    const {
        cout << "First Name: " << _first << "\nLast Name: " << _last
             << "\nAddress: " << _address << "\nID: " << _id << endl;
    }
};

class PayKind {
public:
    virtual ~PayKind() 
    {}
    virtual double payAdvice() const = 0;
};

class Salaried : public PayKind 
{
protected:
    double _annualSalary;
public:
    Salaried(double salary = 0.0) : _annualSalary(salary) {}
    double payAdvice() 
    const override {
        return _annualSalary / 26.0;
    }
};

class Hourly : public PayKind {
protected:
    double _hourlyRate;
public:
    Hourly(double rate = 0.0) : _hourlyRate(rate) {}
    double payAdvice() 
    const override {
        return _hourlyRate * 40.0;
    }
};

class PerCourse : public PayKind {
protected:
    double _feePerCourse;
public:
    PerCourse(double fee = 0.0) : _feePerCourse(fee) {}
    double payAdvice() 
    const override {
        return _feePerCourse / 7.0;
    }
};

class PartTime {
protected:
    int _maxHours;
public:
    PartTime(int h = 0) : _maxHours(h) {}
};

class Adjunct : public UMLPerson, public PerCourse, public PartTime 
{
private:
    int _maxCourses;
public:
    Adjunct(string f, string l, string a, int id, double fee, int hours, int maxCourses)
        : UMLPerson(f, l, a, id), PerCourse(fee), PartTime(hours), _maxCourses(maxCourses) {}

    void display() 
    const override {
        UMLPerson::display();
        cout << "Fee Per Course: " << _feePerCourse << "\nMax Hours: " << _maxHours
             << "\nMax Courses: " << _maxCourses << endl;
    }
};

class Grader : public UMLPerson, public Hourly, public PartTime
 {
private:
    string _course;
public:
    Grader(string f, string l, string a, int id, double rate, int hours, string course)
        : UMLPerson(f, l, a, id), Hourly(rate), PartTime(hours), _course(course) {}

    void display() 
    const override {
        UMLPerson::display();
        cout << "Hourly Rate: " << _hourlyRate << "\nMax Hours: " << _maxHours
             << "\nCourse: " << _course << endl;
    }
};

int main(int argc, char* argv[])
 {
    Grader g1("smith", "john", "123 elm St", 1234, 25.0, 12, "COMP.2010");

    Salaried s1(78000);
    Salaried s2(65000);

    Adjunct a1("fred", "smith", "main street", 41018938, 54321, 12, 2);

    cout << "Pay Advice for g1: $" << g1.payAdvice() << endl;
    cout << "Pay Advice for a1: $" << a1.payAdvice() << endl;
    cout << "Pay Advice for s1: $" << s1.payAdvice() << endl;
    cout << "Pay Advice for s2: $" << s2.payAdvice() << endl << endl;

    vector<Adjunct*> nv;
    nv.push_back(&a1);
    cout << 0 << ":\n"; nv[0]->display();
    cout << "Pay Advice is $" << nv[0]->payAdvice() << endl << endl;

    vector<UMLPerson*> uv;
    uv.push_back(&g1);
    uv.push_back(&a1);

    for (int i = 0; i < uv.size(); ++i) {
        cout << i << ":\n";
        uv[i]->display();
        cout << endl;
    }

    return 0;
}
