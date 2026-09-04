#include<iostream>
#include "dataTypes.h"

using namespace std;

int main()
{
	nameType me("Matt", "Welz");
	me.print();
	dateType today(4, 9, 2026);
	today.print();
	cout << endl;

	personalInfo somebody("Spider", "Man", 5, 5, 2001, 72893749);
	somebody.print();
	somebody.setPersonalInfo("Black", "Widow", 14, 2, 1997, 837489);
	somebody.print();
		
	return 0;
}