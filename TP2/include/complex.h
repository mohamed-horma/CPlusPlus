#ifndef C_H
#define C_H
class Complex{
    private:
        double real, imaginary;
    
    public:
        Complex();

        Complex(double real, double imaginary);

        Complex(const Complex& other); 

        Complex& operator = (const Complex& z);
        
        Complex(double r);

        double getRealPart() const ;
        double getImaginaryPart() const ;
        double getModulus() const ;
        void displayAlgebricForm() const ;
        void permitRealAndImaginary();

};

Complex sum(Complex& z1, Complex& z2 );
Complex product(Complex& z1, Complex& z2 );
Complex difference(Complex& z1, Complex& z2 );
Complex normalized(Complex& z);
void rotate(Complex& z, double angle);
Complex heightedMoudulus(Complex const &z1, Complex const &z2);

#endif