#include<iostream>
using namespace std;



class DynamicArray
{
private:
	int* arr;
	int size;
public:
	DynamicArray(int s = 100);
	void insert(int index, int val);
	void print() const;
	//stuff we need for dynamic variables
	~DynamicArray();  //deallocate dynamic memory
	DynamicArray(const DynamicArray& otherObj);  //create a new object and set equal to an existing one
	void operator=(const DynamicArray& otherObj); //set an existing object equal to another existing object
};



int main()
{
	cout << "How big an array do you want? ";
	int n;
	cin >> n;
	DynamicArray myArray(n);
	myArray.insert(0, 10);
	myArray.insert(1, 78);
	myArray.insert(2, 236);
	myArray.insert(3, 348979);
	myArray.insert(4, 34);
	cout << "First array: " << endl;
	myArray.print();
	
	DynamicArray myArray2(8);
	myArray2 = myArray;  //test overloaded =
	cout << "Second Array: " << endl;
	myArray2.print();

	DynamicArray myArray3(myArray); //test copy constructor
	cout << "Third Array: " << endl;
	myArray3.print();

	return 0;
}

//constructor
DynamicArray::DynamicArray(int s)
{
	size = s;
	arr = new int[size]; //allocates the memory
}
//destructor
DynamicArray::~DynamicArray()
{
	delete[]arr;
}

void DynamicArray::insert(int index, int val)
{ 
	if ((index < size) && (index >= 0))
		arr[index] = val;
	else
		cout << "Index Out of Bounds!" << endl;
}

void DynamicArray::print() const
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void DynamicArray::operator=(const DynamicArray& otherObj)
{
	delete[]arr; //deallocate in case if mismatched size
	size = otherObj.size; //reset size
	arr = new int[size]; //reallocate
	for (int i = 0; i < size; ++i) //set arrays equal
		arr[i] = otherObj.arr[i];
}

DynamicArray::DynamicArray(const DynamicArray& otherObj) //copy constructor
{
	//no deallocation step because the object is brand new and there is nothing to deallocate
	size = otherObj.size; //reset size
	arr = new int[size]; //reallocate
	for (int i = 0; i < size; ++i) //set arrays equal
		arr[i] = otherObj.arr[i];
}