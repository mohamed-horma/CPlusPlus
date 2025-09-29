#include <iostream>
#include "../include/complex.h"
#include <cmath>

using namespace std;

int main(){
    //test default constructor
/*     cout << "Test default constructor: " << endl;
    Complex z1;
    z1.displayAlgebricForm();

    //test constructor with parameters
    cout << "Test constructor with parameters: " << endl;
    Complex z2(3.0,4.0);
    z2.displayAlgebricForm();
    Complex z3(1.0,-5.0);
    z3.displayAlgebricForm();
    Complex z4(-2.0,3.0);
    z4.displayAlgebricForm();

    //test copy constructor
    cout << "Test copy constructor: " << endl;
    Complex z5(z2);//equivalent to Complex z5 = z2;
    z5.displayAlgebricForm();

    //test operator of affectation
    cout << "Test operator of affectation: " << endl;
    Complex z6;
    z6 = z2;
    z6.displayAlgebricForm();

    //test getRealPart and getImaginaryPart
    cout << "Test getRealPart and getImaginaryPart: " << endl;
    cout << "Real part of z2: " << z2.getRealPart() << endl;
    cout << "Imaginary part of z2: " << z2.getImaginaryPart() << endl;

    //test modulus
    cout << "Test modulus: " << endl;
    cout << "Modulus of z2: " << z2.getModulus() << endl;
    cout << "Modulus of z3: " << z3.getModulus() << endl;
    cout << "Modulus of z4: " << z4.getModulus() << endl;
    
    //test permitRealAndImaginary
    cout << "Test permitRealAndImaginary: " << endl;
    cout << "Before permitRealAndImaginary: ";
    z2.displayAlgebricForm();
    z2.permitRealAndImaginary();
    cout << "After permitRealAndImaginary: ";
    z2.displayAlgebricForm();

    //test sum function
    cout << "Test sum function: " << endl;
    Complex z7 = sum(z3,z4);
    z7.displayAlgebricForm();

    //test product function
    cout << "Test product function: " << endl;
    Complex z8 = product(z3,z4);
    z8.displayAlgebricForm();   

    //test difference function
    cout << "Test difference function: " << endl;
    Complex z9 = difference(z3,z4);
    z9.displayAlgebricForm();

    //test constructor with modulus and argument
    /* cout << "Test constructor with modulus and argument: " << endl;
    Complex z10(5.0, M_PI/4); // modulus = 5, argument = π/4
    z10.displayAlgebricForm(); */

    //test constructor with real part only
 /* cout << "Test constructor with real part only: " << endl;
    Complex z10(7.0);
    z10.displayAlgebricForm();
    Complex z11 = sum(z10, z2);
    z11.displayAlgebricForm();
    Complex z12 = product(z10, z2);
    z12.displayAlgebricForm();
    Complex z13 = difference(z10, z2);
    z13.displayAlgebricForm(); 
 */

    /* cout << "Test normalized function: " << endl;
    Complex z14(3.0,4.0);
    z14.displayAlgebricForm();
    Complex z15 = normalized(z14);
    cout << "Normalized: " << endl;
    z15.displayAlgebricForm();
    */
    
    /* cout << "Test rotate function: " << endl;
    Complex z16(1.0, 1.0);
    z16.displayAlgebricForm();
    rotate(z16, M_PI/4); // rotate by 45 degrees
    z16.displayAlgebricForm(); */
/*
    cout << "Test heightModulus" << endl;
    Complex z17(1.0,2.0);
    z17.displayAlgebricForm();
    product(z17,z17).displayAlgebricForm();
    Complex z18 = heightedMoudulus(z17, product(z17,z17));
    z18.displayAlgebricForm();
*/

    cout << "Test racineUnity function" << endl;

    Complex Table[5];
    racineUnity(5, Table);
    for (int i=0; i<5; i++){
        Table[i].displayAlgebricForm();
    }
    return 0;
}