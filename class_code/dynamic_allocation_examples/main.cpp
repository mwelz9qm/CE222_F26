#include<iostream>
#include <iomanip>

using namespace std;


void printArray(const int a[], int n) //print a static or dynamic array
{
	for (int i = 0; i < n;++i)
		cout << a[i] << " ";
	cout << endl;
}

void printDynamic2D(int **arr,int r, int c)
{
	for (int i = 0; i <r;++i)
	{
		for (int j = 0; j < c;++j)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
}

int main()
{
	int size;
	cout << "What's the size of the array??" << endl;
	cin >> size;
	int arr[5]; //statically allocate memory for array
	int* dArr = new int[size]; //dynamically allocate memory for our array

	for (int i = 0; i < 5; ++i)  //fills the static array
	{
		arr[i] = 2 * i + 1;
	}

	printArray(arr,5);
	cout << "Printing the array variable (which is a pointer): " << arr << endl;
	cout << "The value of: arr + 2 is " << arr + 2 << endl;
	cout << "The value of *arr is " << *arr << endl;
	cout << "The value of *(arr + 2) is " << *(arr + 2) << endl;

	for (int i = 0; i < size; ++i) //fills the dynamic array
	{
		dArr[i] = 2 * i;
	}

	printArray(dArr, size);

	delete[]dArr; //deallocate memory

	//dynamically allocate 2D array
	int rows,cols;
	cout << "Enter the rows and columns for your 2d array: ";
	cin >> rows >> cols;

	int ** arr2D = new int*[rows];
	for (int i = 0; i < rows; ++i) //allocate individual rows
		arr2D[i] = new int[cols];
	
	//fill the array with something
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			arr2D[i][j] = i*j + 2*i + 4;
	
	//print the 2D array
	printDynamic2D(arr2D,rows,cols);
	//deallocate the array -- rows first!
	for (int i = 0; i < rows; ++i)
		delete []arr2D[i];
	
	delete []arr2D;







	return 0;
}