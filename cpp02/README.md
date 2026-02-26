# CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Form

## Overview

This module introduces **fixed-point arithmetic** as a vehicle for exploring operator overloading and the Orthodox Canonical Class Form (OCF). It demonstrates how C++ enables creation of custom types that behave like built-in primitives, bridging the gap between abstract data types and natural mathematical syntax.

## Core Concepts Explored

### 1. **Orthodox Canonical Form (Coplien's Form)**
The four essential member functions every well-behaved class should have:

```cpp
class Fixed {
public:
    Fixed();                              // Default constructor
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                             // Destructor
};
```

**Why This Matters**:
- **Copy Safety**: Ensures objects can be safely duplicated
- **Assignment Safety**: Manages resource transfer between existing objects
- **Resource Management**: Prevents leaks through proper cleanup
- **Rule of Three**: If you define one, define all three (copy ctor, copy assignment, destructor)

### 2. **Fixed-Point Arithmetic**
Alternative to floating-point for systems requiring:
- Deterministic precision
- Performance (no FPU)
- Embedded systems constraints

**Representation**:
```
32-bit integer: [24 bits for integer][8 bits for fractional]
Example: 42.42 = 10858 (in fixed-point with 8 fractional bits)

Conversion:
    Float to Fixed: value * 2^fractionalBits
    Fixed to Float: value / 2^fractionalBits
```

### 3. **Operator Overloading**
Making custom types behave like native types:

```cpp
Fixed a(5.05f);
Fixed b(2);
Fixed c = a + b;     // Uses overloaded operator+
if (a > b) { ... }   // Uses overloaded operator>
std::cout << c;      // Uses overloaded operator<<
```

**Philosophy**: Overload operators only when the operation is **intuitive and unambiguous**.

### 4. **Ad-hoc Polymorphism**
Function overloading and operator overloading enable:
- Same operation name for different types
- Compile-time resolution (static polymorphism)
- Type-safe operations without manual type checking

## Problem-Solving Architecture

### Exercise 00: Fixed-Point Number Class (Basic OCF)
**Concept**: Implement Orthodox Canonical Form with debug output

#### Implementation Strategy:
```cpp
class Fixed {
private:
    int _value;                    // Fixed-point value storage
    static const int _fractionalBits = 8;  // Precision constant
    
public:
    Fixed() : _value(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    Fixed(const Fixed& other) {
        std::cout << "Copy constructor called" << std::endl;
        *this = other;  // Leverage assignment operator
    }
    
    Fixed& operator=(const Fixed& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {  // Self-assignment check
            _value = other._value;
        }
        return *this;
    }
    
    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }
};
```

**Critical Details**:
1. **Self-Assignment Check**: `if (this != &other)` prevents issues with `a = a;`
2. **Return `*this`**: Enables chaining: `a = b = c;`
3. **Const References**: Parameters avoid unnecessary copies

**Debug Output Teaches**:
- When copy constructor is called vs copy assignment
- Temporary object creation and destruction
- Compiler optimizations (RVO - Return Value Optimization)

### Exercise 01: Towards a More Useful Fixed-Point Class
**Concept**: Add conversion constructors and type conversion functions

#### New Functionality:
```cpp
class Fixed {
public:
    // Conversion constructors
    Fixed(const int value) {
        _value = value << _fractionalBits;  // Shift left to add fractional bits
    }
    
    Fixed(const float value) {
        _value = roundf(value * (1 << _fractionalBits));  // Scale and round
    }
    
    // Conversion functions
    float toFloat() const {
        return (float)_value / (1 << _fractionalBits);
    }
    
    int toInt() const {
        return _value >> _fractionalBits;  // Shift right to remove fractional bits
    }
};
```

**Bit-Shifting Logic**:
```
Integer 42 → Fixed-Point:
    42 << 8 = 10752
    Binary: 42 * 256 = 10752

Fixed-Point 10752 → Integer:
    10752 >> 8 = 42
    Binary: 10752 / 256 = 42
```

**Stream Insertion Overload**:
```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;  // Enable chaining: cout << a << b << c;
}
```

**Design Pattern**: This overload must be a **free function** (not member) because `std::ostream` is on the left side.

### Exercise 02: Now We're Talking (Full Operator Overloading)
**Concept**: Complete arithmetic and comparison operator suite

#### Comparison Operators:
```cpp
bool operator>(const Fixed& rhs) const {
    return _value > rhs._value;
}

bool operator<(const Fixed& rhs) const {
    return _value < rhs._value;
}

bool operator>=(const Fixed& rhs) const {
    return _value >= rhs._value;
}

bool operator<=(const Fixed& rhs) const {
    return _value <= rhs._value;
}

bool operator==(const Fixed& rhs) const {
    return _value == rhs._value;
}

bool operator!=(const Fixed& rhs) const {
    return _value != rhs._value;
}
```

**Key Insight**: Compare raw `_value` integers, not floats (avoids precision issues).

#### Arithmetic Operators:
```cpp
Fixed operator+(const Fixed& rhs) const {
    Fixed result;
    result._value = _value + rhs._value;
    return result;
}

Fixed operator-(const Fixed& rhs) const {
    Fixed result;
    result._value = _value - rhs._value;
    return result;
}

Fixed operator*(const Fixed& rhs) const {
    Fixed result;
    result._value = (_value * rhs._value) >> _fractionalBits;  // Remove extra fractional bits
    return result;
}

Fixed operator/(const Fixed& rhs) const {
    Fixed result;
    result._value = (_value << _fractionalBits) / rhs._value;  // Add fractional bits back
    return result;
}
```

**Multiplication/Division Nuance**:
- Multiplication creates **double the fractional bits** → shift right to normalize
- Division loses fractional bits → shift left **before** dividing to preserve precision

#### Increment/Decrement Operators:
```cpp
// Pre-increment: ++a (returns reference, increments first)
Fixed& operator++() {
    _value++;
    return *this;
}

// Post-increment: a++ (returns copy, increments after)
Fixed operator++(int) {  // Dummy int parameter distinguishes post-increment
    Fixed temp(*this);
    _value++;
    return temp;
}

// Pre-decrement: --a
Fixed& operator--() {
    _value--;
    return *this;
}

// Post-decrement: a--
Fixed operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}
```

**Performance Note**: Pre-increment is more efficient (no copy), prefer `++a` over `a++` when return value isn't used.

#### Static Min/Max Functions:
```cpp
static Fixed& min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

static const Fixed& min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

static Fixed& max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

static const Fixed& max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
```

**Overload Reason**: Const overloads prevent modifying const objects through returned reference.

### Exercise 03: BSP (Binary Space Partitioning - Point Class)
**Concept**: Apply fixed-point numbers to geometric problem

#### Problem Statement:
Determine if a point P lies inside triangle ABC.

#### Geometric Solution - Barycentric Coordinates:
A point P is inside triangle ABC if:
```
P = u*A + v*B + w*C
where u + v + w = 1 and u, v, w ≥ 0
```

**Alternative: Cross-Product Method**:
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const p) {
    // Calculate vectors
    Fixed v0x = c.getX() - a.getX();
    Fixed v0y = c.getY() - a.getY();
    Fixed v1x = b.getX() - a.getX();
    Fixed v1y = b.getY() - a.getY();
    Fixed v2x = p.getX() - a.getX();
    Fixed v2y = p.getY() - a.getY();
    
    // Calculate cross products (determine which side of edges P is on)
    Fixed cross1 = (v1x * v2y - v1y * v2x);
    Fixed cross2 = (v0x * v2y - v0y * v2x);
    Fixed cross3 = ((b.getX() - p.getX()) * (c.getY() - p.getY()) 
                  - (b.getY() - p.getY()) * (c.getX() - p.getX()));
    
    // If all cross products have same sign, point is inside
    return (cross1 > 0 && cross2 > 0 && cross3 > 0) 
        || (cross1 < 0 && cross2 < 0 && cross3 < 0);
}
```

**Point Class Design**:
```cpp
class Point {
private:
    const Fixed _x;  // Immutable coordinates
    const Fixed _y;
    
public:
    Point() : _x(0), _y(0) {}
    Point(const float x, const float y) : _x(x), _y(y) {}
    Point(const Point& other) : _x(other._x), _y(other._y) {}
    
    // No assignment operator (const members can't be reassigned)
    
    Fixed getX() const { return _x; }
    Fixed getY() const { return _y; }
};
```

**Design Decision**: `const` members make Points immutable (geometric points don't change once created).

## Key Principles Demonstrated

1. **Type Abstraction**: Custom types indistinguishable from built-in types (syntax-wise)
2. **Const Correctness**: `const` methods, parameters, and return types prevent accidental modification
3. **Operator Semantics**: Overloaded operators maintain expected behavior (associativity, precedence)
4. **Efficiency**: Return references when possible, avoid unnecessary copies
5. **Self-Assignment Safety**: Always check `this != &other` in assignment operators

## Technical Challenges & Solutions

### Challenge 1: Precision in Multiplication/Division
**Problem**: Fixed-point multiplication doubles fractional bits
**Solution**: 
```cpp
result = (a * b) >> fractionalBits;  // Normalize after multiply
```

### Challenge 2: Pre vs Post Increment
**Problem**: Distinguishing `++a` from `a++` in overloaded functions
**Solution**: Dummy `int` parameter for post-increment
```cpp
Fixed& operator++();      // Pre-increment
Fixed operator++(int);    // Post-increment
```

### Challenge 3: Const Member Initialization
**Problem**: Const members can't be assigned in constructor body
**Solution**: Member initializer list
```cpp
Point(float x, float y) : _x(x), _y(y) {}  // Only way to initialize const members
```

## Lessons Learned

### Software Engineering
- **Intuitive Interfaces**: Overload operators only when operation is obvious
- **Consistency**: If you overload `<`, also overload `>`, `<=`, `>=`, `==`, `!=`
- **Efficiency**: Return by const reference when returning existing objects
- **Immutability**: Use `const` for geometric/mathematical values that shouldn't change

### C++ Specifics
- **OCF is Non-Negotiable**: Even simple classes need proper copy semantics
- **Bit Manipulation**: Essential for fixed-point and low-level optimizations
- **Friend Functions**: Sometimes necessary for symmetric operators (stream insertion)
- **Static Members**: Utility functions that don't depend on instance state

### Mathematical Programming
- **Fixed-Point Trade-offs**: Speed vs precision vs range
- **Geometric Algorithms**: Cross products, dot products for spatial reasoning
- **Numerical Stability**: Avoid float comparisons, use integer comparisons when possible

## Practical Applications

- **Embedded Systems**: Fixed-point math in microcontrollers without FPU
- **Game Engines**: Deterministic physics simulations (networked games)
- **Financial Software**: Exact decimal arithmetic (currency calculations)
- **Graphics**: Early 3D engines used fixed-point for performance
- **Audio Processing**: Sample manipulation without floating-point overhead

## Common Pitfalls

1. **Forgetting to Shift**: Multiplication/division require bit-shift adjustments
2. **Self-Assignment**: Not checking `this != &other` causes issues
3. **Const Incorrectness**: Missing `const` on methods that don't modify state
4. **Wrong Return Types**: Returning value instead of reference (or vice versa)
5. **Operator Inconsistency**: Overloading `<` but not `>`

---

*This module establishes operator overloading patterns used throughout C++. Understanding when and how to overload operators is crucial for creating intuitive, maintainable APIs. The Orthodox Canonical Form introduced here remains relevant even in modern C++ with move semantics (Rule of Five).*
