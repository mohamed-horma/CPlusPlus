# Compte rendue

## Questions Answer
### First part : Complex
*4*: I think that here we will have a confusion between the two constructor : 
<g++ -Wall -Wextra -O2 -std=c++11 -c src/complex.cpp -o src/complex.o
In file included from src/complex.cpp:3:
src/../include/complex.h:15:9: error: ‘Complex::Complex(double, double)’ cannot be overloaded with ‘Complex::Complex(double, double)’
   15 |         Complex(double modulus, double argument);
      |         ^~~~~~~
src/../include/complex.h:9:9: note: previous declaration ‘Complex::Complex(double, double)’
    9 |         Complex(double real, double imaginary);
      |         ^~~~~~~
src/complex.cpp:38:1: error: redefinition of ‘Complex::Complex(double, double)’
   38 | Complex::Complex(double modulus, double argument){
      | ^~~~~~~
src/complex.cpp:13:1: note: ‘Complex::Complex(double, double)’ previously defined here
   13 | Complex::Complex(double real, double imaginary){
      | ^~~~~~~
make: *** [Makefile:15: src/complex.o] Error 1> 
So, it is impossible to have those constructors at same time.

*5*: The best solution is to convert double into a complex element, by creating a *Constuctor of conversion* who  take as argument a double.


### Second Part: Traces
To indentify every constructor we gonna, know which kind of constructor and the complex addresse.

To return the current and object address:
```CPP
cout << "Address of current object: " << this << endl;
cout << "Address of parameter object: " << &other << endl;
```

### Third part: 

**Rotate** function: To do it we must give the argument *by reference*. Morever, *By value* we work on a copy, the orgin will not change.
*By address* is more complicated, reference is easy.
*By const ref* no, because we can't change a const.

**{comment}**: When I tested the *rotate* function, I comment that, the real part of z16 has to be null, but it is just tending to zero.
<Test rotate function:
before rotate
z=1+i.1
after rotate(z,M_PI/4)
z=1.11022e-16+i.1.41421 >



