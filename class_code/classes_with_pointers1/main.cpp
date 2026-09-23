#include<iostream>

using namespace std;

class exClass
{
private:
	int x;
	int* p;
public:
	exClass(int a = 0, int b = 0);
	~exClass();//destructor
	void operator=(const exClass& otherObj); //overloaded =
	exClass(const exClass& otherObj); //copy constructor which is almost same as operator=, but need to allocate memory
	void print() const;
};

int main()
{
	exClass obj(3, 5);
	obj.print();
	exClass obj2;
	obj2.print();
	obj2 = obj; //we need to overload the = operator to do a deep copy rather than default shallow
	obj2.print();

	//exClass obj3 = obj2; //equivalent to the bottom line
	exClass obj3(obj2);
	obj3.print();

	return 0;
}

exClass::exClass(int a, int b)
{
	x = a;
	p = new int;
	*p = b;
}

exClass::~exClass()
{
	delete p;
}

void exClass::print() const
{
	cout << "************************" << endl;
	cout << "Object Data" << endl;
	cout << " x = " << x << endl;
	cout << " p = " << p << " and *p = " << *p << endl;
	cout << "************************" << endl;
}

void exClass::operator=(const exClass& otherObj)
{
	x = otherObj.x;
	*p = *(otherObj.p);
}

exClass::exClass(const exClass& otherObj)
{
	x = otherObj.x;
	p = new int;
	*p = *(otherObj.p);
}