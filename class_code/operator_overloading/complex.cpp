#include<iostream>
#include "complex.h"
using namespace std;

     
    ComplexType::ComplexType(double r, double i)
    {
        setParts(r,i);
    }
    void ComplexType::display() const
    {
        if (imag >=0 )
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -1*imag << "i";
    }
        bool ComplexType::operator==(const ComplexType & otherComplex) const //overload == operator
        {
            return (real == otherComplex.real) && (imag == otherComplex.imag);
        }
        ComplexType ComplexType::operator+(const ComplexType & otherComplex) const //overload + operator
        {
            ComplexType ans;
            ans.real = real + otherComplex.real;
            ans.imag = imag + otherComplex.imag;
            return ans;
        }
         ComplexType ComplexType::operator*(const ComplexType & otherComplex) const //overload * operator
         {
            ComplexType ans;
            ans.real = real * otherComplex.real - imag * otherComplex.imag;
            ans.imag = imag * otherComplex.real + real * otherComplex.imag;
            return ans;
         }

    void ComplexType::setParts(double r, double i)
    {
        real = r;
        imag = i;
    } 
