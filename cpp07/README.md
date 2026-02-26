# CPP Module 07: C++ Templates

## Overview

This module introduces **templates**, C++'s mechanism for generic programming. Templates enable writing code once that works with any type, achieving code reuse without sacrificing type safety or performance. Unlike runtime polymorphism (virtual functions), templates are resolved at **compile-time**, resulting in zero runtime overhead.

## Core Concepts Explored

### 1. **Function Templates**
Generic functions that work with any type:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage:
int maxInt = max<int>(5, 10);           // Explicit instantiation
double maxDouble = max(3.14, 2.71);     // Implicit (type deduced)
std::string maxStr = max(std::string("apple"), std::string("banana"));
```

**How It Works**:
- Compiler generates separate function for each type used
- `max<int>`, `max<double>`, `max<std::string>` are distinct compiled functions
- No runtime dispatch—all resolved at compile-time

**Template Parameter Syntax**:
```cpp
template <typename T>     // 'typename' keyword (preferred)
template <class T>        // 'class' keyword (equivalent, legacy)
```

**Multiple Template Parameters**:
```cpp
template <typename T1, typename T2>
void printPair(T1 first, T2 second) {
    std::cout << first << ", " << second << std::endl;
}
```

### 2. **Class Templates**
Generic classes that work with any type:

```cpp
template <typename T>
class Box {
private:
    T _content;
    
public:
    Box(T content) : _content(content) {}
    T get() const { return _content; }
    void set(T content) { _content = content); }
};

// Usage:
Box<int> intBox(42);
Box<std::string> strBox("hello");
```

**Template Specialization**:
```cpp
// General template:
template <typename T>
class Printer {
public:
    void print(T value) { std::cout << value << std::endl; }
};

// Full specialization for bool:
template <>
class Printer<bool> {
public:
    void print(bool value) {
        std::cout << (value ? "true" : "false") << std::endl;
    }
};
```

### 3. **Type Deduction**
Compiler automatically infers template types:

```cpp
template <typename T>
T add(T a, T b) { return a + b; }

add(5, 10);        // T deduced as int
add(3.14, 2.71);   // T deduced as double
add(5, 3.14);      // ❌ Error: T can't be both int and double
```

**Common Type Promotion** (doesn't apply to templates):
```cpp
void regularFunc(double x);
regularFunc(5);  // ✅ int promoted to double

template <typename T>
void templateFunc(T x);
templateFunc(5);  // T = int (no promotion)
```

### 4. **Template Compilation Model**
Templates are **compiled when instantiated**, not when defined:

```cpp
// header.hpp
template <typename T>
T square(T x) {
    return x * x;  // Only checked when instantiated
}

// main.cpp
square(5);         // Instantiates square<int>, checks if int has operator*
square("text");    // ❌ Compile error: const char* doesn't have operator*
```

**Implementation Location**:
- **Traditional**: Templates in `.cpp` files cause linker errors
- **Solution**: Implement in header files (`.hpp`) or use `.tpp` include files
- **Modern C++20**: Modules solve this, but not widely adopted yet

## Problem-Solving Architecture

### Exercise 00: Function Templates (swap, min, max)
**Concept**: Generic utility functions for any comparable type

#### swap Implementation:
```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

**Usage Examples**:
```cpp
int x = 2, y = 3;
swap(x, y);
std::cout << "x = " << x << ", y = " << y << std::endl;  // x = 3, y = 2

std::string s1 = "hello";
std::string s2 = "world";
swap(s1, s2);
std::cout << s1 << ", " << s2 << std::endl;  // world, hello
```

**Requirements**:
- Type `T` must be **copy-constructible**
- Type `T` must support **assignment operator**

#### min/max Implementation:
```cpp
template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
```

**Why const references?**
- Avoid copies (efficient for large objects like `std::string`)
- Still works with primitives
- Maintains const-correctness

**Requirements**:
- Type `T` must support **operator<** or **operator>**

**Edge Case**: What if `a == b`?
```cpp
int a = 5, b = 5;
int& result = min(a, b);  // Which one is returned?
// Implementation-defined: returns second argument if equal (per standard)
```

#### Testing:
```cpp
int main() {
    int a = 2;
    int b = 3;
    
    ::swap(a, b);  // :: to use our template, not std::swap
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    
    return 0;
}
```

**Output**:
```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### Exercise 01: iter (Applying Function to Array)
**Concept**: Generic array iteration with function application

#### Implementation:
```cpp
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}
```

**Template Parameters**:
- `T`: Array element type
- `Func`: Function (or functor) type

**What is `Func`?**
- Function pointer: `void (*)(T&)`
- Functor: Object with `operator()`
- Lambda (C++11+): `[](T& x) { ... }`

#### Usage Examples:

**With Function Pointer**:
```cpp
void printInt(int& x) {
    std::cout << x << " ";
}

void doubleInt(int& x) {
    x *= 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    iter(arr, 5, printInt);   // Output: 1 2 3 4 5
    std::cout << std::endl;
    
    iter(arr, 5, doubleInt);
    iter(arr, 5, printInt);   // Output: 2 4 6 8 10
    
    return 0;
}
```

**With Template Function**:
```cpp
template <typename T>
void print(T& x) {
    std::cout << x << " ";
}

int main() {
    int intArr[] = {1, 2, 3};
    iter(intArr, 3, print<int>);  // Explicit instantiation
    
    std::string strArr[] = {"one", "two", "three"};
    iter(strArr, 3, print<std::string>);
    
    return 0;
}
```

**With Functor (C++)**:
```cpp
template <typename T>
struct Printer {
    void operator()(T& x) const {
        std::cout << x << " ";
    }
};

int main() {
    int arr[] = {1, 2, 3};
    iter(arr, 3, Printer<int>());  // Functor instance
    return 0;
}
```

**With Lambda (C++11)**:
```cpp
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    iter(arr, 5, [](int& x) {
        std::cout << x * x << " ";  // Print squares
    });
    // Output: 1 4 9 16 25
    
    return 0;
}
```

**Advanced: Const-Correct Version**:
```cpp
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

template <typename T, typename Func>
void iter(const T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}
```

### Exercise 02: Array Template Class
**Concept**: Type-safe, bounds-checked dynamic array

#### Class Design:
```cpp
template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;
    
public:
    // Default constructor (empty array)
    Array() : _array(nullptr), _size(0) {}
    
    // Parameterized constructor
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}
    
    // Copy constructor (deep copy)
    Array(const Array& copy) : _array(nullptr), _size(0) {
        *this = copy;
    }
    
    // Assignment operator (deep copy)
    Array& operator=(const Array& copy) {
        if (this != &copy) {
            delete[] _array;
            _size = copy._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = copy._array[i];
            }
        }
        return *this;
    }
    
    // Destructor
    ~Array() {
        delete[] _array;
    }
    
    // Subscript operator (bounds-checked)
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }
    
    // Size getter
    unsigned int size() const {
        return _size;
    }
};
```

**Key Features**:
1. **Default Initialization**: `new T[n]()` value-initializes elements
   - Primitives: Zero-initialized (`int` → 0, `float` → 0.0)
   - Objects: Default constructor called
2. **Deep Copy**: Assignment and copy constructor duplicate array content
3. **Bounds Checking**: `operator[]` throws exception on invalid index
4. **Exception Safety**: Copy-and-swap or proper cleanup in assignment operator

#### Usage Examples:

**Basic Operations**:
```cpp
int main() {
    Array<int> numbers(5);
    
    // Default initialized to 0:
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";  // Output: 0 0 0 0 0
    }
    std::cout << std::endl;
    
    // Modify elements:
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";  // Output: 0 10 20 30 40
    }
    
    return 0;
}
```

**Copy Testing**:
```cpp
int main() {
    Array<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    Array<int> copy = original;  // Deep copy
    copy[0] = 99;
    
    std::cout << "Original[0]: " << original[0] << std::endl;  // 1 (unchanged)
    std::cout << "Copy[0]: " << copy[0] << std::endl;          // 99
    
    return 0;
}
```

**Bounds Checking**:
```cpp
int main() {
    Array<int> arr(5);
    
    try {
        arr[10] = 42;  // Out of bounds
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Output: Error: Index out of bounds
    }
    
    return 0;
}
```

**With Complex Types**:
```cpp
int main() {
    Array<std::string> strings(3);
    strings[0] = "hello";
    strings[1] = "world";
    strings[2] = "!";
    
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << strings[i] << " ";
    }
    // Output: hello world !
    
    return 0;
}
```

**Advanced: Const-Correctness Testing**:
```cpp
void print(const Array<int>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";  // Uses const operator[]
    }
}

int main() {
    Array<int> numbers(3);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    
    print(numbers);  // Can pass to const reference
    
    return 0;
}
```

## Key Principles Demonstrated

1. **Generic Programming**: Write once, use with any type
2. **Zero-Cost Abstraction**: Templates have no runtime overhead
3. **Type Safety**: Compile-time checking prevents type errors
4. **Code Reuse**: One implementation works for all types
5. **Duck Typing (C++ style)**: If type supports required operations, it works

## Technical Challenges & Solutions

### Challenge 1: Template Definition in Headers
**Problem**: Templates must be visible at instantiation point
**Solution**: Implement in `.hpp` files or use included `.tpp` files
```cpp
// Array.hpp
template <typename T>
class Array { ... };

#include "Array.tpp"  // Implementation
```

### Challenge 2: Type Requirements Not Explicit
**Problem**: Hard to know what operations type `T` must support
**Solution**: Document requirements (C++20 Concepts formalize this)
```cpp
// Requires: T must have operator<
template <typename T>
T min(T a, T b) { return (a < b) ? a : b; }
```

### Challenge 3: Deep Copy in Templates
**Problem**: Template copy constructor must copy dynamic resources
**Solution**: Implement proper copy constructor and assignment operator
```cpp
Array(const Array& copy) {
    _array = new T[copy._size];
    for (unsigned int i = 0; i < copy._size; i++)
        _array[i] = copy._array[i];  // Uses T's copy assignment
}
```

### Challenge 4: Exception Safety
**Problem**: Exception during copy leaves object in invalid state
**Solution**: Copy-and-swap idiom or proper cleanup
```cpp
Array& operator=(const Array& copy) {
    if (this != &copy) {
        T* newArray = new T[copy._size];  // Allocate first
        for (unsigned int i = 0; i < copy._size; i++)
            newArray[i] = copy._array[i];
        
        delete[] _array;  // Clean up old (after success)
        _array = newArray;
        _size = copy._size;
    }
    return *this;
}
```

## Lessons Learned

### Template Best Practices
- **Document Type Requirements**: What operations must `T` support?
- **Prefer `typename` over `class`**: More accurate for non-class types
- **Use Const References**: Avoid unnecessary copies in parameters
- **Provide Const Overloads**: `operator[]` should have const and non-const versions
- **Test with Multiple Types**: Verify template works with int, string, custom classes

### Compilation Model
- **Templates Are Not Code**: They're blueprints for generating code
- **Instantiation Is Compilation**: Each use generates a new function/class
- **Header-Only Libraries**: Templates naturally live in headers
- **Slow Compilation**: Many instantiations increase compile time

### Modern C++ Enhancements
- **C++11 Variadic Templates**: `template <typename... Args>`
- **C++14 Variable Templates**: `template <typename T> T pi = 3.14159;`
- **C++17 Fold Expressions**: Simplify variadic template operations
- **C++20 Concepts**: Explicit template constraints

## Practical Applications

- **Standard Library**: `std::vector<T>`, `std::map<K,V>`, `std::array<T, N>`
- **Mathematical Libraries**: Generic matrix/vector operations
- **Algorithms**: `std::sort`, `std::find`, etc. work with any type
- **Smart Pointers**: `std::unique_ptr<T>`, `std::shared_ptr<T>`
- **Serialization**: Generic serializers for any type

## Common Pitfalls

1. **Template Code in `.cpp` Files**: Causes linker errors
2. **Missing Type Requirements**: Cryptic compiler errors when type doesn't support operation
3. **Bloat**: Each instantiation generates separate code (executable size)
4. **Two-Phase Lookup**: Name resolution differs for dependent/non-dependent names
5. **SFINAE**: Substitution Failure Is Not An Error (advanced, can be confusing)

## Performance Considerations

| Aspect | Templates | Runtime Polymorphism (Virtual) |
|--------|-----------|-------------------------------|
| Dispatch | Compile-time | Runtime (vtable lookup) |
| Overhead | Zero (after compilation) | ~1-2 ns per call |
| Code Size | Larger (one copy per type) | Smaller (one function) |
| Flexibility | Type must be known at compile-time | Works with unknown types at runtime |
| Optimization | Fully inlineable | Limited (virtual calls) |

---

*Templates are the foundation of generic programming in C++. While they have a steeper learning curve than runtime polymorphism, they enable highly efficient, reusable code. The Standard Template Library (STL) demonstrates their power—containers, algorithms, and iterators all leverage templates to provide type-safe, zero-overhead abstractions. Modern C++ features like concepts and fold expressions further enhance template usability.*
