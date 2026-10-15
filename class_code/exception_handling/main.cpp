#include<iostream>
#include<assert.h>
#include<cmath>

using namespace std;

double geoMean(double x, double y) //version 1, aborts
{
	if (x < 0 || y < 0)
		abort();
	return sqrt(x * y);
}

bool geoMean2(double x, double y, double &m) //version 2, returns error code 0 = fail, 1= success
{
	if (x < 0 || y < 0)
		return false;
	m = sqrt(x * y); // by reference, so changing in main
	return true;
}

double geoMean3(double x, double y) //version 3, with exception throwing
{
	if (x < 0 || y < 0)
		throw string("At least one of the values is negative");
	return sqrt(x * y);
}

int main()
{

	double mean;
	cout << "The geometric mean of 3 and 5: " << geoMean(3, 5) << endl;
	// cout << "The geometric mean of -3 and 5: " << geoMean(-3, 5) << endl;
	if (geoMean2(4, 6, mean)) //returns true/false and possibly updates mean
	{
		cout << "Function ran successfully, new geometric mean is " << mean << endl;
	}
	else
		cout << "geoMean Function failed";

	//int x = 10;

	////a bunch of complicated code ... and then 
	////suppose we expect x to be 8 and it accidentally changed

	//assert(x == 8);  //this checks that expectation

	double a, b, c;
	cout << "Enter two numbers: ";
	while (cin >> a >> b)
	{
		try
		{
			c = geoMean3(a, b);
		}
		catch (string s)
		{
			cout << "Error: " << s << endl;
			cout << "Enter two more numbers: ";
			continue; 
		}
		cout << "The geo mean of a and b is " << c << endl;
		cout << "Enter two more numbers or q to quit." << endl;
	}

	return 0;
}
