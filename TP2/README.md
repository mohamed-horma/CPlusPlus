# Compte rendue
This is the second practical work on C++. Furthermore, it's contain class, constructors ... 
## Questions Answer
### First part : Complex
#### Question 4: 
I think that here we will have a confusion between the two constructor : 
```shell
g++ -Wall -Wextra -O2 -std=c++11 -c src/complex.cpp -o src/complex.o
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
make: *** [Makefile:15: src/complex.o] Error 1
```
So, it is impossible to have those constructors at same time.

#### Question 4: 
The best solution is to convert double into a complex element, by creating a *Constuctor of conversion* who  take as argument a double.


### Second Part: Traces
To indentify every constructor we gonna, know which kind of constructor and the complex addresse.

To return the current and object address:
```CPP
cout << "Address of current object: " << this << endl;
cout << "Address of parameter object: " << &other << endl;
```

### Third part: 

**Rotate** function: To do it we must give the argument **by reference**. Morever, **By value** we work on a copy, the orgin will not change.
**By address** is more complicated, reference is easy.
**By const ref** no, because we can't change a const.

**{comment}**: When I tested the **rotate** function, I comment that, the real part of z16 has to be null, but it is just tending to zero.
```shell
test rotate function:
before rotate
z=1+i.1
after rotate(z,M_PI/4)
z=1.11022e-16+i.1.41421 
```

### racineUnity function:
We comment that after creating table :
```cpp 
Complex Table[10]
```
the cpu use **+++Complex()** for 10 addresses.
Then when calling 
```cpp
racineUnity(10, Table);
```
The compilator fit all cases by using a **local addrese**.
Here is the result of compilation:
```bash
Test racineUnity function
+++Complex()
Address of current object: 0x7ffe6d9070a0
+++Complex()
Address of current object: 0x7ffe6d9070b0
+++Complex()
Address of current object: 0x7ffe6d9070c0
+++Complex()
Address of current object: 0x7ffe6d9070d0
+++Complex()
Address of current object: 0x7ffe6d9070e0
+++Complex(a, b)
Address of current object: 0x7ffe6d907040
op=Complex(a+i.b)
Address of current object: 0x7ffe6d9070a0
Address of parameter object: 0x7ffe6d907040
+++Complex(a, b)
Address of current object: 0x7ffe6d907040
op=Complex(a+i.b)
Address of current object: 0x7ffe6d9070b0
Address of parameter object: **0x7ffe6d907040**
+++Complex(a, b)
Address of current object: 0x7ffe6d907040
op=Complex(a+i.b)
Address of current object: 0x7ffe6d9070c0
Address of parameter object: 0x7ffe6d907040
+++Complex(a, b)
Address of current object: 0x7ffe6d907040
op=Complex(a+i.b)
Address of current object: 0x7ffe6d9070d0
Address of parameter object: 0x7ffe6d907040
+++Complex(a, b)
Address of current object: 0x7ffe6d907040
op=Complex(a+i.b)
Address of current object: 0x7ffe6d9070e0
Address of parameter object: 0x7ffe6d907040
1

0.309017+i.0.951057
-0.809017+i.0.587785
-0.809017-i.0.587785
0.309017-i.0.951057
```
The function in local use the same addresse: **0x7ffe6d907040**


#### SimpleTest function

Here is the result :

```bash
+++Complex(a, b)
Address of current object: 0x7fffcef47fc0 ** Complex z1 (0 ,0);**
+++Complex(a, b)
Address of current object: 0x7fffcef47fd0 **Complex z2 (1 ,1)**
+++Complex(a, b)
Address of current object: 0x7fffcef47fe0 **Complex z3 (2 ,2);**

Calling foo()  

**copy z1 inside a local variabl a**
rrrComplex(a+i.b) 
Address of current object: 0x7fffcef48000 // addresse of the local argument b 
Address of parameter object: 0x7fffcef47fd0 //z2 addresse
**copy z2 inside a local variabl b**

rrrComplex(a+i.b)
Address of current object: 0x7fffcef47ff0 // a ddresse 
Address of parameter object: 0x7fffcef47fc0 //z1 addresse
**copy z1 inside a local variabl b**


+++Complex(a, b)
Address of current object: 0x7fffcef47f70 // z addresse : Complex z (10 ,10);

//z = a ;
op=Complex(a+i.b)
Address of current object: 0x7fffcef47f70 // z address
Address of parameter object: 0x7fffcef47ff0 // a addresse

//z=b
op=Complex(a+i.b)
Address of current object: 0x7fffcef47f70 // z addresse
Address of parameter object: 0x7fffcef48000 // b addresse

//
rrrComplex(a+i.b)
Address of current object: 0x7fffcef48010 // the addresse how might return the z
Address of parameter object: 0x7fffcef47f70 // z addresse

//z3 = foo ( z1 , z2 );
op=Complex(a+i.b)
Address of current object: 0x7fffcef47fe0 // z3 addresse
Address of parameter object: 0x7fffcef48010  // the addresse how might return the z
 End of main ()

``` 
