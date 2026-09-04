#include "dataTypes.h"
#include <iostream>
#include <string>
using namespace std;

//implentation of nameType functions/methods
nameType::nameType(string f, string l) //constructor with defaults
{
	setName(f, l);
}
void nameType::setName(string f, string l)
{
	firstName = f;
	lastName = l;
}
string nameType::getFirstName() const
{
	return firstName;
}
string nameType::getLastName() const
{
	return lastName;
}
void nameType::print() const
{
	cout << "Name *************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
}


//implentation of dateType methods
dateType::dateType(int d, int m, int y) //constructor with defaults
{
	setDate(d, m, y);
}
void dateType::print() const
{
	cout << month << "/" << day << "/" << year;
}
void dateType::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}


//implemneting personalInfo methods

personalInfo::personalInfo(string f, string l, int d, int m, int y, int i)//constructor with defaults
	:name(f,l),bDay(d,m,y)
{
	id = i;
}
void personalInfo::print() const
{
	cout << "Personal Info: " << endl;
	name.print();
	cout << "Birthday: ";
	bDay.print();
	cout << " Id: " << id << endl;
}
void personalInfo::setPersonalInfo(string f, string l, int d, int m, int y, int i)
{
	name.setName(f, l);
	bDay.setDate(d, m, y);
	id = i;
}