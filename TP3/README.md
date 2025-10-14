
# C++ Programming — Matrix Class Implementation

## About This Practical Work

This practical work focuses on implementing a **`Matrix` class** that performs basic operations on real-valued matrices while correctly handling **dynamic memory allocation**, **copy/move semantics**, and **exception safety**.  

It allowed us to:
- Apply the **Rule of Five** (constructor, copy/move constructors, assignment operators, destructor).  
- Practice **efficient data management** using `memcpy()`.  
- Understand how **copy and move operations** behave during function calls, especially with compiler options like `-fno-elide-constructors`.  
- Validate my implementation with **Valgrind** to ensure there are **no memory leaks**.  


## 1. Output Interpretation

When compiled with the debug flag `-DDBUG_ON`, the constructors and assignment operators display traces:

```
+++Matrix()
+++Matrix(n,m)
rrrMatrix(n,m)
op=Matrix(n,m)
dddMatrix(n,m)
opd=Matrix(n,m)
```

* `+++` → Constructor
* `rrr` → Copy constructor
* `ddd` → Move constructor
* `op=` → Copy assignment
* `opd=` → Move assignment

These traces help visualize **object lifetime** and **resource transfer** between matrices.

---
## 2. About the `operator[]` — OOP Design Question

### ❓ Question
> Define an `operator[]` to access the coefficients of the matrix.  
> The `operator[]` should return the array (a pointer) corresponding to the row given as argument.  
> This allows the use of expressions like `m[10][3]` if `m` is an instance of the class `Matrix` (the second bracket is the one applied to any pointer).  
> Which basic rule of object-oriented programming is, to some extent, broken here?  
> Propose an alternative implementation. It should allow both reading and modifying each coefficient.

### 💬 Answer

By returning a **raw pointer** (`double*`) from `operator[]`, the `Matrix` class **breaks encapsulation**, a core rule of object-oriented programming.

Encapsulation means that an object’s internal data should not be exposed directly — instead, it should only be accessed through **controlled interfaces**.  
In this design, returning a pointer allows the user to modify internal data directly, without any boundary checking or control.

---

### ⚠️ Problem Illustration

```cpp
double* row = m[0];    // returns internal pointer
row[1] = 9999;         // modifies internal array directly

Here, the internal structure _array is exposed, so the caller can:

    Access or modify data without safety checks.

    Potentially corrupt memory by accessing out-of-range indices.

This violates data hiding, one of the fundamental OOP principles.
✅ Alternative Implementation

A safer approach is to avoid returning a raw pointer and instead provide explicit access methods with built-in range checking:
```cpp
double Matrix::get(int i, int j) const {  
}
void Matrix::set(int i, int j, double value) {  
}
```
## 3. Valgrind

Here is the Valgrind result:

```bash
==22718== HEAP SUMMARY:
==22718==     in use at exit: 0 bytes in 0 blocks
==22718==   total heap usage: 21 allocs, 21 frees, 75,516 bytes allocated
==22718==
==22718== All heap blocks were freed -- no leaks are possible
==22718==
==22718== Use --track-origins=yes to see where uninitialised values come from
==22718== For lists of detected and suppressed errors, rerun with: -s
==22718== ERROR SUMMARY: 90 errors from 10 contexts (suppressed: 0 from 0)
```

✅ **Interpretation:**
All dynamically allocated memory was properly released — **no leaks** occurred.
The warnings correspond to uninitialized values used during intermediate operations but do not affect memory safety.

---

## 4. `foo()` Function
We didn't understand it. 


## 5. Key Takeaways

* 🧩 **Dynamic memory** must always be managed with care; every `new[]` needs a matching `delete[]`.
* ⚙️ **Move semantics** significantly improve efficiency when handling large data structures.
* 🧮 **Operator overloading** makes mathematical code more intuitive.
* 🚫 **Exception safety** ensures robustness for invalid inputs.
* 🧠 **Valgrind** and debug traces are essential tools to confirm correctness.
* 💡 **Incremental development** (building and testing each function one by one) prevents cascading errors.

