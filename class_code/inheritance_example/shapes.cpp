#include "shapes.h"
#include <iostream>

using namespace std;


rectangleType::rectangleType(double l, double w) //constructor with default params
{
	length = l;
	width = w;
}
double rectangleType::getArea() const
{
	return length * width;
}
double rectangleType::getPerim() const
{
	return 2 * (length + width);
}
void rectangleType::print() const
{
	cout << "*********Rectangle Attributes: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
}

boxType::boxType(double l, double w, double h) // constructor w/default params
	:rectangleType(l, w)   // calls the rectangleType constructor
{
	height = h;
}
double boxType::getVolume() const
{
	return getArea() * height;
}

void boxType::print() const //override of the print from rectangleType
{
	cout << "*********Box Attributes: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}