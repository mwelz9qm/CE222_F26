#include<iostream>
#include "complex.h"

using namespace std;

int main()
{


ComplexType z1(3,4);
ComplexType z2(-2,-1);
ComplexType z3;

z3 = z2 + z1;
z3.display();
cout << endl;
z3 = z2 *z1;
z3.display();
cout << endl;

    return 0;
}