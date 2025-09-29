#include <iostream>
#include <cmath>
#include "../include/complex.h"
using namespace std;

//default constructor
Complex::Complex(){
    cout << "+++Complex()" << endl;
    cout << "Address of current object: " << this << endl;
    real= 0.0;
    imaginary = 0.0;   
}        

//constructor with parameters 
Complex::Complex(double real, double imaginary){
    cout << "+++Complex(a, b)" << endl;
    cout << "Address of current object: " << this << endl;

    Complex::real = real; 
    Complex::imaginary = imaginary;
}        

//constructor for copy
Complex::Complex(const Complex& other) {
    cout << "rrrComplex(a+i.b)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &other << endl;
    real = other.real;
    imaginary = other.imaginary;
}        

//Operator of affectation
Complex& Complex::operator = (const Complex& z){
    cout << "op=Complex(a+i.b)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &z << endl;
    if (this == &z) // self-assignment check
        return *this; 

    real = z.real;
    imaginary = z.imaginary;

    return *this; // Return the current object by reference

    //We can do also:using COPY AND SWAP idiom
    /* Complex copy(z);
    swap(real, copy.real);
    swap(imaginary, copy.imaginary);
     */
}

//constructor with real part only
Complex::Complex(double r): real(r), imaginary(0.0) {}

/* Complex::Complex(double modulus, double argument){
    real = modulus * cos(argument);
    imaginary = modulus * sin(argument);
}
 */

double Complex::getRealPart() const {
    return real;
}        

double Complex::getImaginaryPart() const {
    return imaginary;
}

double Complex::getModulus() const {
    return std::sqrt( real*real + imaginary*imaginary);
}
        
void Complex::displayAlgebricForm() const {
    cout << real;
    if(imaginary >0){
        cout << "+" << "i." <<imaginary;
    } else if(imaginary == 0){
        cout << endl;
    } else{
        cout << "-" <<"i."<<imaginary * -1;
    }
    cout << endl;
}

void Complex::permitRealAndImaginary(){
    double tmp = real;
    real = imaginary; 
    imaginary = tmp; 
}


Complex sum(Complex& z1, Complex& z2 ){
    double real = z1.getRealPart() + z2.getRealPart();
    double imaginary = z1.getImaginaryPart() + z2.getImaginaryPart();
    Complex z(real, imaginary);

    return z;
}

Complex product(Complex& z1, Complex& z2){
    double real  = z1.getRealPart()* z2.getRealPart() - z1.getImaginaryPart() * z2.getImaginaryPart();
    double imaginary = z1.getRealPart() * z2.getImaginaryPart() + z1.getImaginaryPart() * z2.getRealPart();

    Complex z(real, imaginary);
    return z;
}

Complex difference(Complex& z1, Complex& z2 ){
    double real = z1.getRealPart() - z2.getRealPart();
    double imaginary = z1.getImaginaryPart() - z2.getImaginaryPart();
    Complex z(real, imaginary);

    return z;
}

Complex operator+(const Complex& z1, const Complex& z2){
    double real = z1.getRealPart() + z2.getRealPart();
    double imaginary = z1.getImaginaryPart() + z2.getImaginaryPart();
    Complex z(real, imaginary);

    return z;
}

Complex operator-(const Complex& z1, const Complex& z2){
    double real = z1.getRealPart() - z2.getRealPart();
    double imaginary = z1.getImaginaryPart() - z2.getImaginaryPart();
    Complex z(real, imaginary);

    return z;
}

Complex operator*(const Complex& z1, const Complex& z2){
    double real  = z1.getRealPart()* z2.getRealPart() - z1.getImaginaryPart() * z2.getImaginaryPart();
    double imaginary = z1.getRealPart() * z2.getImaginaryPart() + z1.getImaginaryPart() * z2.getRealPart();

    Complex z(real, imaginary);
    return z;
}

Complex normalized(Complex& z){
    double modulus = z.getModulus();
    if(modulus == 0){
        return z;
    }
    double real = z.getRealPart() / modulus;
    double imaginary = z.getImaginaryPart() / modulus;

    Complex norm(real, imaginary);
    return norm;
}

void rotate(Complex& z, double angle){
    double real = z.getRealPart() * cos(angle) - z.getImaginaryPart() * sin(angle);
    double imaginary = z.getRealPart() * sin(angle) + z.getImaginaryPart() * cos(angle);

    z = Complex(real, imaginary);
}

Complex heightedMoudulus(Complex const &z1, Complex const &z2){
    double modulus1 = z1.getModulus();
    double modulus2 = z2.getModulus();
    
    
    if(modulus1 >= modulus2){
        return z1;
    } else {
        return z2;  
    }
}



void racineUnity(int n, Complex* table){
    for (int i=0; i<n; i++){
        table[i] = Complex(cos(2*i*M_PI / n), sin(2*i*M_PI / n));
    }
}




