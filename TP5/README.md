
## 🎯 **Goal of the Assignment TP5**

The purpose of this assignment is to implement a generic `Set<T>` type representing mathematical sets, using:

* a **class template**
* **function templates** for set operations
* a **singly linked list** as the internal structure
* no ordering constraint: the set is **not sorted**

Because this is a C++ template, the full implementation must appear **in the header file**.

The provided file `set_test.cpp` is used to validate the implementation.

---

## ⚙️ **Required Features**

The `Set<T>` template must offer:

### Core methods

* empty constructor
* constructor with a single element
* copy constructor
* assignment operator
* destructor + `clear()`

### Basic set operations

* `insert`, `remove`, `contains`
* `isSubsetOf`, `insertInto`, `removeFrom`

### Overloaded operators

* `==` (equality)
* `<`  (subset)
* `>`  (superset)
* `|`  (union)
* `&`  (intersection)
* `-`  (difference)
* `^`  (symmetric difference)

### External functions

* `singleton(x)`
* `emptySet()`

### Mapping a function over a set

* `image(set, f)`
  — implemented as a friend function template

All of this must work for any `T` that supports `==`, including `int`, `double`, `bool`, and `std::string`.

---

## 🧪 **Testing**

The file `set_test.cpp`:

* creates several sets (`e`, `f`, `g`, `h`)
* tests all operations and constructors
* checks assignment and comparisons
* uses `image` to apply `std::sin` to a set

The printed order of elements depends on how `insert` is implemented (here: **inserting at the head**).

---

## ❓ **Final Question: Why do we use `singleton(string("void"))` instead of `singleton("void")`?**

### ✔️ **Answer**

Because:

* `"void"` is a **string literal**, type `const char[5]`
* It decays to a **`const char*`**
* Therefore `singleton("void")` creates a `Set<const char*>`

But comparing `const char*` values compares **memory addresses**, not **text content**.

This would make the set behave incorrectly (e.g., different copies of `"void"` would be considered different elements).

By writing:

```cpp
singleton(string("void"))
```

we explicitly construct a `std::string`, and `std::string`’s `operator==` compares the **actual textual content**, which is what we want for sets of words.

---

## 📌 **Key Takeaways**

* Template implementations must be fully contained in the header file.
* The set uses a simple **unsorted linked list**.
* Duplicate avoidance depends purely on `T`’s `operator==`.
* Inserting at the head reverses the insertion order in the printed output.
* All operators and helper functions must also be **templates**.
* String literals (`"text"`) create `const char*`, not `std::string`.
* For correct string comparison, always use `std::string("text")`.


