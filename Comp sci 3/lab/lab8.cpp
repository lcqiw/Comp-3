#include <iostream>
#include <string>

using namespace std;

class UMLPerson 
{
protected:
string _first, _last, _address;
int _id;
public:
UMLPerson() : _first("NoName"), _last("NoName"), _address("NoAddress"), _id(0) 
{}
UMLPerson(string f, string l, string a, int id) : _first(f), _last(l), _address(a), _id(id) 
{}
UMLPerson(const UMLPerson& other) : _first(other._first), _last(other._last),
_address(other._address), _id(other._id) 
{
cout << "UMLPerson copy constructor called for \"" << _first << " " << _last << "\"" << endl;
}
virtual ~UMLPerson() 
{
cout << "UMLPerson destructor called for \"" << _first << " " << _last << "\"" << endl;
}
virtual void display() 
const {
cout << "First Name: " << _first << "\nLast Name: " << _last
<< "\nAddress: " << _address << "\nID Number: " << _id << endl;
}
};


class Student : public UMLPerson 
{
protected:
double _gpa;
string _major, _advisor;
public:
Student() : UMLPerson(), _gpa(0), _major("Undeclared"), _advisor("NoName") 
{}
Student(string f, string l, string a, int id, double gpa, string major, string adv) : UMLPerson(f, l, a, id), _gpa(gpa), _major(major), _advisor(adv) 
{}
Student(const Student& other) : UMLPerson(other), _gpa(other._gpa), _major(other._major), _advisor(other._advisor) 
{
cout << "Student copy constructor called for \"" << _first << " " << _last << "\"" << endl;
}
~Student() override {
cout << "Student destructor called for \"" << _first << " " << _last << "\"" << endl;
}
void display() const override {
UMLPerson::display();
cout << "GPA: " << _gpa << "\nMajor: " << _major << "\nAdvisor Name: " << _advisor << endl;
}
};

class Undergrad : public Student {
protected:
string _rank;
public:
Undergrad() : Student(), _rank("NoRank")
{

}
Undergrad(string f, string l, string a, int id, double gpa, string major, string adv, string rank) : Student(f, l, a, id, gpa, major, adv), _rank(rank) 
{

}
Undergrad(const Undergrad& other) : Student(other), _rank(other._rank) 
{
cout << "Undergrad copy constructor called for \"" << _first << " " << _last << "\"" << endl;
}
~Undergrad() 
override {
cout << "Undergrad destructor called for \"" << _first << " " << _last << "\"" << endl;
}
void display() 
const override {
Student::display();
cout << "Class Rank: " << _rank << endl;
}
};


class EmployeeKind 
{
public:
EmployeeKind() = default;
virtual ~EmployeeKind() 
{
cout << "Employee destructor called" << endl;
}
};

class Faculty : public UMLPerson 
{
protected:
string _ssn, _dept, _rank;
public:
Faculty(string f, string l, string a, int id, string ssn, string dept, string rank) : UMLPerson(f, l, a, id), _ssn(ssn), _dept(dept), _rank(rank) {}
virtual ~Faculty() 
{
cout << "Faculty destructor called for " << _first << " " << _last << endl;
}
void display() 
const override {
UMLPerson::display();
cout << "SSN: " << _ssn << "\nDepartment: " << _dept << "\nRank: " << _rank << endl;
}
};

class PayKind 
{
public:
virtual ~PayKind() 
{}
};

class PerCourse : public PayKind 
{
protected:
unsigned _feePerCourse;
public:
PerCourse() : _feePerCourse(0) 
{}
PerCourse(unsigned fee) : _feePerCourse(fee)
 {}
virtual ~PerCourse() 
{
cout << "PerCourse destructor called" << endl;
}
};

class PartTime : public EmployeeKind {
protected:
unsigned _maxHours;
public:
PartTime() : _maxHours(0) 
{}
PartTime(unsigned h) : _maxHours(h) 
{}
virtual ~PartTime() 
{
cout << "PartTime destructor called" << endl;
}
};

class Adjunct : public Faculty, public PerCourse, public PartTime 
{
protected:
unsigned _maxCourses;
public:
Adjunct(string f, string l, string a, int id, string ssn, string dept,
unsigned maxCourses, unsigned fee, unsigned hours)
: Faculty(f, l, a, id, ssn, dept, "Adjunct"), 
PerCourse(fee), PartTime(hours), _maxCourses(maxCourses)
{}

~Adjunct() 
override {
cout << "Adjunct destructor called for " << _first << " " << _last << endl;
}

void display() 
const override {
Faculty::display();
cout << "Max Courses: " << _maxCourses
<< "\nFee Per Course: " << _feePerCourse
<< "\nMax Hours: " << _maxHours << endl;
}
};

class Hourly 
{
protected:
unsigned _rate;
public:
Hourly() : _rate(0) 
{}
Hourly(unsigned r) : _rate(r) 
{}
virtual ~Hourly() 
{
cout << "Hourly destructor called" << endl;
}
};

class Grader : public Undergrad, public Hourly, public PartTime {
protected:
string _classNumber;
public:
Grader() : Undergrad(), Hourly(), PartTime(), _classNumber("NoClassNumber")
{
}
Grader(string f, string l, string a, int id, double gpa, string major, string adv, string rank, string classNum, unsigned rate, unsigned hours)
: Undergrad(f, l, a, id, gpa, major, adv, rank), Hourly(rate), PartTime(hours),
_classNumber(classNum) 
{}
Grader(const Grader& other) : Undergrad(other), Hourly(other._rate), PartTime(other._maxHours), _classNumber(other._classNumber)
{
cout << "Grader copy constructor called for \"" << _first << " " << _last << "\"" << endl;
}

~Grader() override {
cout << "Grader destructor called for \"" << _first << " " << _last << "\"" << endl;
}

void display() const override {
Undergrad::display();
cout << "Class Number: " << _classNumber
<< "\nHourly Rate: " << _rate
<< "\nMax Hours: " << _maxHours << endl;
}
};


int main(int argc, char* argv[]) 
{
cout << "UMLPerson():\n";
UMLPerson p;
p.display();
cout << endl;

cout << "Student():\n";
Student st;
st.display();
cout << endl;

cout << "Undergrad():\n";
Undergrad ug;
ug.display();
cout << endl;

cout << "Grader():\n";
Grader g;
g.display();
cout << endl;

cout << "Undergrad s1(Sally...):\n";
Undergrad s1("Sally", "Brown", "110 Canal Street", 12345678, 4.0, "CS", "Tom Wilkes", "senior");
s1.display();
cout << endl;

cout << "Undergrad s2(Jimmy...):\n";
Undergrad s2("Jimmy", "Smith", "99 Canal Street", 87654321, 3.0, "CS", "Tom Wilkes", "freshman");
s2.display();
cout << endl;

cout << "Grader g1(John...):\n";
Grader g1("John", "Doe", "89 Canal Street", 54329876, 3.5, "CS", "Tom Wilkes", "junior",
"COMP.2010", 25, 12);
g1.display();
cout << endl;

cout << "Grader g2(copy of g1 - John...):\n";
Grader g2(g1);
g2.display();
cout << endl;

cout << "NTT Faculty n1(Tom...):\n";
Faculty n1("Tom", "Wilkes", "Foo Street", 52901256, "123-45-6789", "Computer Science", "Assistant Teaching Professor");
n1.display();
cout << endl;

cout << "Adjunct Faculty a1(Bjarne...):\n";
Adjunct a1("Bjarne", "Stroustrup", "AT&T Bell Labs", 41018938, "987-65-4321", "Computer Science", 2, 54321, 12);
a1.display();
cout << endl;

return 0;
}