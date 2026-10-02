class ComplexType{
    private:
        double real;
        double imag;
    public:
        ComplexType(double r = 0, double i = 0);
        void display() const;
        bool operator==(const ComplexType & otherComplex) const; //overload == operator
        ComplexType operator+(const ComplexType & otherComplex) const; //overload + operator
         ComplexType operator*(const ComplexType & otherComplex) const; //overload * operator
        void setParts(double r, double i);
};