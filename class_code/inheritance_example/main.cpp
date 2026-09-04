#include "shapes.h"
#include <iostream>

using namespace std;

int main()
{

	rectangleType rectangle1;
	rectangleType rectangle2(12, 8);
	rectangle1.print();
	rectangle2.print();
	cout << "The area of rectangle 2 is " << rectangle2.getArea() << " square units." << endl;
	cout << "The perimeter of rectange 2 is " << rectangle2.getPerim() << " units." << endl;

	boxType myBox(3, 4, 5);
	myBox.print(); //to call the base class print, use myBox.rectangleType::print();
	cout << "The volume of myBox is " << myBox.getVolume() << " cubic units." << endl;

	return 0;
}