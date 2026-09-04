#pragma once


//rectangle interface
class rectangleType
{
protected:
	double length;
	double width;
public:
	rectangleType(double l = 5, double w = 5); //constructor with default params
	double getArea() const;
	double getPerim() const;
	void print() const;
};

//boxType will inherit rectangleType 
class boxType : public rectangleType
{
private:
	double height; // inheriting length and width
public:
	boxType(double l = 5, double w = 5, double h = 5); // constructor w/default params
	double getVolume() const;
	void print() const;
};