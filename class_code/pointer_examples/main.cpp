#include<iostream>

using namespace std;

struct color
{
	int red;
	int green;
	int blue;
};

void displayColor(const color& c)
{
	cout << "Color Components: " << endl;
	cout << "Red: " << c.red << endl;
	cout << "Green: " << c.green << endl;
	cout << "Blue: " << c.blue << endl;
}

void displayColorPoint(color * c)  //version where we pass a pointer
{
	cout << "Color Components: " << endl;
	cout << "Red: " << c->red << endl;
	cout << "Green: " << c->green << endl;
	cout << "Blue: " << c->blue << endl;
}


void addFive(int &a) //this actually adds 5 to the global variable since passed my reference
{
	a = a + 5;
}

void addFivePoint(int* a)
{
	*a = *a + 5;
}

int main()
{
	int x;
	x = 5;
	cout << "x's value is " << x << endl;
	cout << "x's address is " << &x << endl;
	int* xptr; //pointer to an integer
	xptr = &x;
	cout << "xptr's value is " << xptr << endl;

	color myColor = { 10,100,70 };
	cout << "Printing the green component: " << myColor.green << endl;
	color* cpoint;
	cpoint = &myColor;
	cout << "Printing the blue component two different ways with the pointer: ";
	cout << (*cpoint).blue << " and " << cpoint->blue << endl;
	cpoint->red = 55;
	cout << "The red component is now " << cpoint->red << endl;

	displayColor(*cpoint);
	displayColorPoint(cpoint);

	cout << "x before addFive " << x << endl;
	addFive(x);
	cout << "x after addFive " << x << endl;
	addFivePoint(xptr);
	cout << "x after addFivePoint " << x << endl;




	return 0;
}