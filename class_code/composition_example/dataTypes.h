#pragma once
#include <string>

using namespace std;

class nameType
{
private:
	string firstName;
	string lastName;
public:
	nameType(string f = "Jane", string l = "Doe"); //constructor with defaults
	void setName(string f, string l);
	string getFirstName() const;
	string getLastName() const;
	void print() const;
};

class dateType
{
private:
	int day;
	int month;
	int year;
public:
	dateType(int d = 1, int m = 1, int y = 2026); //constructor with defaults
	void print() const;
	void setDate(int d, int m, int y);
};

class personalInfo
{
private:
	nameType name;
	dateType bDay;
	int id;
public:
	personalInfo(string f = "Jane", string l = "Doe", int d = 1, int m = 1, int y = 2026, int i = 0);//constructor with defaults
	void print() const;
	void setPersonalInfo(string f, string l, int d, int m, int y, int i);
};