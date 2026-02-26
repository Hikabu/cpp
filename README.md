# C++ Programming: From Fundamentals to Advanced Concepts
## A Comprehensive Journey Through Object-Oriented and Generic Programming

---

## Executive Summary

This repository documents a systematic exploration of C++ programming, progressing from basic syntax to advanced template metaprogramming and algorithm design. Through ten interconnected modules (cpp00-cpp09), it traces the evolution of a programmer's understanding from procedural thinking to sophisticated object-oriented and generic programming patterns.

**Scope**: 42 School C++ curriculum  
**Language Standard**: C++98/03 (foundation for modern C++)  
**Total Exercises**: 40+ hands-on projects  
**Core Competencies**: OOP, Memory Management, Templates, STL, Algorithms  

---

## Table of Contents

1. [Learning Trajectory](#learning-trajectory)
2. [Module Overview](#module-overview)
3. [Core Programming Paradigms](#core-programming-paradigms)
4. [Key Concepts Hierarchy](#key-concepts-hierarchy)
5. [Technical Skills Acquired](#technical-skills-acquired)
6. [Design Patterns Encountered](#design-patterns-encountered)
7. [Memory Management Mastery](#memory-management-mastery)
8. [STL Deep Dive](#stl-deep-dive)
9. [Performance Considerations](#performance-considerations)
10. [Evolution from C to C++](#evolution-from-c-to-c)
11. [Practical Applications](#practical-applications)
12. [Lessons Learned](#lessons-learned)
13. [Future Directions](#future-directions)

---

## Learning Trajectory

The curriculum follows a carefully designed progression:

```
┌─────────────┐
│   cpp00     │  Syntax, Classes, I/O
│  Foundation │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp01     │  Memory, Pointers, References
│   Memory    │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp02     │  Operator Overloading, Fixed-Point
│  Operators  │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp03     │  Inheritance, Diamond Problem
│ Inheritance │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp04     │  Virtual Functions, Polymorphism
│ Polymorphism│  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp05     │  Exceptions, Error Handling
│ Exceptions  │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp06     │  Type Casting, RTTI
│   Casts     │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp07     │  Function & Class Templates
│  Templates  │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp08     │  Containers, Iterators, Algorithms
│     STL     │  
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   cpp09     │  Advanced STL, Real-World Problems
│  Advanced   │  
└─────────────┘
```

---

## Module Overview

### **Module 00: Namespaces, Classes, Member Functions**
**Theme**: Transition from C to C++

Introduces fundamental object-oriented concepts:
- Class definition and instantiation
- Encapsulation with public/private access
- Stream I/O (`std::cout`, `std::cin`)
- String manipulation with `std::string`

**Key Project**: PhoneBook (contact management with formatted output)

**Paradigm Shift**: From function-centric C to object-centric C++

[📖 Read full cpp00 README](cpp00/README.md)

---

### **Module 01: Memory Allocation, Pointers, References**
**Theme**: Manual memory management

Explores the critical distinction between stack and heap:
- Stack vs heap allocation strategies
- `new` and `delete` operators
- Pointers vs references (when to use each)
- RAII (Resource Acquisition Is Initialization) foundations

**Key Projects**: 
- Zombie allocation (heap lifetime management)
- Weapon classes (reference parameters)
- File string replacement (stream I/O)

**Critical Lesson**: Memory ownership and lifetime management

[📖 Read full cpp01 README](cpp01/README.md)

---

### **Module 02: Ad-hoc Polymorphism, Operator Overloading**
**Theme**: Creating types that behave like primitives

Introduces the Orthodox Canonical Form and custom operators:
- Default constructor, copy constructor, assignment operator, destructor
- Operator overloading (`+`, `-`, `*`, `/`, `<<`, etc.)
- Fixed-point arithmetic as case study
- Comparison and increment operators

**Key Project**: Fixed-point number class (financial precision)

**Design Principle**: Make custom types indistinguishable from built-ins

[📖 Read full cpp02 README](cpp02/README.md)

---

### **Module 03: Inheritance**
**Theme**: Code reuse through specialization

Demonstrates class hierarchies:
- Single inheritance (base → derived)
- Multiple inheritance (diamond problem)
- Virtual inheritance (diamond resolution)
- Protected members and access control
- Constructor/destructor chaining

**Key Project**: ClapTrap hierarchy (game-style inheritance)

**Architectural Pattern**: "Is-a" relationships and specialization

[📖 Read full cpp03 README](cpp03/README.md)

---

### **Module 04: Subtype Polymorphism, Abstract Classes**
**Theme**: Runtime polymorphism through virtual functions

Explores dynamic dispatch and interfaces:
- Virtual functions and vtables
- Abstract classes (pure virtual functions)
- Deep copy with polymorphic objects
- Interface-based design
- Factory pattern

**Key Projects**:
- Animal hierarchy (polymorphic behavior)
- Materia system (interface design)

**Core Principle**: Program to interfaces, not implementations

[📖 Read full cpp04 README](cpp04/README.md)

---

### **Module 05: Repetition and Exceptions**
**Theme**: Structured error handling

Introduces exception mechanisms:
- Try-catch blocks
- Custom exception classes
- Exception safety guarantees
- RAII and automatic cleanup
- Template method pattern

**Key Project**: Bureaucrat/Form system (authorization checks)

**Design Philosophy**: Separate error handling from business logic

[📖 Read full cpp05 README](cpp05/README.md)

---

### **Module 06: C++ Casts**
**Theme**: Type safety and conversion

Explores explicit casting operators:
- `static_cast`: Compile-time conversions
- `dynamic_cast`: Runtime type checking (RTTI)
- `reinterpret_cast`: Low-level bit reinterpretation
- `const_cast`: Const removal (anti-pattern)

**Key Projects**:
- Scalar converter (type detection and conversion)
- Serialization (pointer ↔ integer)
- Type identification (runtime type discovery)

**Safety Principle**: Explicit casts reveal intent and enable checking

[📖 Read full cpp06 README](cpp06/README.md)

---

### **Module 07: C++ Templates**
**Theme**: Generic programming (compile-time polymorphism)

Introduces template mechanisms:
- Function templates (`swap`, `min`, `max`)
- Class templates (`Array<T>`)
- Template instantiation model
- Type deduction rules
- Zero-cost abstraction

**Key Project**: Generic array with bounds checking

**Performance Insight**: Templates = runtime polymorphism without overhead

[📖 Read full cpp07 README](cpp07/README.md)

---

### **Module 08: Templated Containers, Iterators, Algorithms**
**Theme**: Standard Template Library fundamentals

Explores STL architecture:
- Containers (`vector`, `list`, `deque`, `stack`)
- Iterators (abstraction over traversal)
- Algorithms (`find`, `sort`, `transform`)
- Container adapters
- Extending STL (MutantStack)

**Key Projects**:
- `easyfind` (generic container search)
- Span (range with statistics)
- MutantStack (iterable stack)

**STL Philosophy**: Algorithms + Containers + Iterators = Flexible Code

[📖 Read full cpp08 README](cpp08/README.md)

---

### **Module 09: Advanced STL & Algorithms**
**Theme**: Real-world problem solving with STL

Applies STL to practical problems:
- `std::map` (associative containers)
- CSV parsing and data lookup
- Stack-based expression evaluation (RPN)
- Custom sorting algorithms (merge-insert sort)
- Performance comparison (vector vs deque)

**Key Projects**:
- Bitcoin exchange rate calculator
- Reverse Polish Notation evaluator
- Ford-Johnson algorithm implementation

**Culmination**: All prior concepts converge to solve complex problems

[📖 Read full cpp09 README](cpp09/README.md)

---

## Core Programming Paradigms

### **1. Procedural Programming (C Background)**
- Functions operate on data
- Manual memory management
- Global state and side effects

### **2. Object-Oriented Programming (cpp00-04)**
- **Encapsulation**: Data hiding through access specifiers
- **Inheritance**: Code reuse through hierarchies
- **Polymorphism**: Runtime dispatch via virtual functions

**Three Pillars Demonstrated**:
```cpp
// Encapsulation (cpp00)
class Contact {
private:
    std::string _name;  // Hidden implementation
public:
    std::string getName() const { return _name; }  // Controlled access
};

// Inheritance (cpp03)
class ScavTrap : public ClapTrap {
    // ScavTrap inherits ClapTrap members
};

// Polymorphism (cpp04)
Animal* dog = new Dog();
dog->makeSound();  // Calls Dog::makeSound() at runtime
```

### **3. Generic Programming (cpp07-09)**
- Code written once, works with any type
- Compile-time instantiation
- Type safety without performance cost

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
// Works with int, double, string, custom classes
```

---

## Key Concepts Hierarchy

### **Foundational Layer (cpp00-01)**
```
Classes & Objects → Memory Management → Stack vs Heap → RAII Foundations
```

### **Type System Layer (cpp02-04)**
```
Operator Overloading → Inheritance → Virtual Functions → Abstract Interfaces
```

### **Error Handling Layer (cpp05-06)**
```
Exceptions → Custom Exception Classes → RTTI → Type Casting
```

### **Generic Programming Layer (cpp07-09)**
```
Function Templates → Class Templates → STL Containers → Algorithms
```

---

## Technical Skills Acquired

### **Memory Management**
- [x] Stack allocation (automatic lifetime)
- [x] Heap allocation (`new`/`delete`)
- [x] Array allocation (`new[]`/`delete[]`)
- [x] Deep copy vs shallow copy
- [x] RAII pattern (constructors acquire, destructors release)
- [x] Memory leak prevention (Valgrind validation)

### **Object-Oriented Design**
- [x] Class design (single responsibility principle)
- [x] Encapsulation (public/private/protected)
- [x] Inheritance hierarchies
- [x] Virtual function dispatch
- [x] Abstract classes and interfaces
- [x] Polymorphic destruction (virtual destructors)

### **Generic Programming**
- [x] Function templates
- [x] Class templates
- [x] Template specialization
- [x] Type deduction
- [x] Template instantiation model
- [x] Zero-cost abstractions

### **STL Mastery**
- [x] Sequence containers (vector, list, deque)
- [x] Associative containers (map, set)
- [x] Container adapters (stack, queue)
- [x] Iterators (categories and usage)
- [x] Algorithms (find, sort, transform)
- [x] Function objects (functors)

### **Error Handling**
- [x] Exception throwing and catching
- [x] Custom exception classes
- [x] Exception safety guarantees
- [x] Resource cleanup during unwinding
- [x] Exception hierarchies

### **Type System**
- [x] Four C++ cast operators
- [x] Runtime type information (RTTI)
- [x] Type traits and detection
- [x] Const-correctness
- [x] Type conversions (implicit vs explicit)

---

## Design Patterns Encountered

### **Creational Patterns**
1. **Factory Pattern** (cpp04, cpp05)
   - `Intern::makeForm()` creates forms dynamically
   - `AMateria::clone()` creates copies without knowing exact type

2. **Singleton Pattern** (implicit in static classes, cpp06)
   - ScalarConverter has no instances, only static methods

### **Structural Patterns**
1. **Adapter Pattern** (cpp08)
   - `std::stack` adapts `std::deque` to LIFO interface
   - MutantStack adapts stack to provide iterators

2. **Composite Pattern** (cpp04)
   - Character has-a array of AMateria objects

### **Behavioral Patterns**
1. **Template Method Pattern** (cpp05)
   - `AForm::execute()` defines algorithm, derived classes implement steps

2. **Strategy Pattern** (cpp04)
   - Different AMateria types = different `use()` strategies

3. **Iterator Pattern** (cpp08)
   - STL iterators abstract container traversal

---

## Memory Management Mastery

### **The Rule of Three** (cpp02)
If a class manages resources, define:
1. **Copy Constructor**: Create new object from existing
2. **Copy Assignment Operator**: Copy to existing object
3. **Destructor**: Free resources

```cpp
class Array {
    T* _data;
public:
    Array(const Array& copy) {  // Copy constructor
        _data = new T[copy._size];
        // Copy elements...
    }
    
    Array& operator=(const Array& copy) {  // Copy assignment
        if (this != &copy) {
            delete[] _data;
            _data = new T[copy._size];
            // Copy elements...
        }
        return *this;
    }
    
    ~Array() {  // Destructor
        delete[] _data;
    }
};
```

### **Modern Rule of Five** (C++11 Extension)
Add:
4. **Move Constructor**: Transfer ownership efficiently
5. **Move Assignment Operator**: Transfer ownership to existing object

### **RAII (Resource Acquisition Is Initialization)**
Core pattern throughout all modules:
```cpp
void function() {
    Resource r;  // Constructor acquires
    
    if (error)
        throw exception;  // Destructor called during unwinding
    
    // Normal exit: destructor called
}
```

**Benefits**:
- Automatic cleanup (no manual calls needed)
- Exception-safe (resources freed during stack unwinding)
- Scope-based lifetime management

---

## STL Deep Dive

### **Container Categories**

#### **Sequence Containers** (cpp08)
| Container | Underlying | Access | Insert | Use Case |
|-----------|-----------|---------|--------|----------|
| `vector` | Dynamic array | O(1) | O(N) | Default choice |
| `deque` | Array of arrays | O(1) | O(1) ends | Queue/Stack |
| `list` | Linked list | O(N) | O(1) | Frequent inserts |

#### **Associative Containers** (cpp09)
| Container | Underlying | Find | Insert | Sorted |
|-----------|-----------|------|--------|---------|
| `map` | Red-Black Tree | O(log N) | O(log N) | Yes |
| `set` | Red-Black Tree | O(log N) | O(log N) | Yes |
| `unordered_map` | Hash table | O(1)* | O(1)* | No |

\* Average case, O(N) worst case

### **Iterator Categories** (cpp08)
```
Input → Output
  ↓
Forward
  ↓
Bidirectional
  ↓
Random Access
```

**Capabilities**:
- **Input/Output**: Single-pass, read or write (not both)
- **Forward**: Multi-pass, read/write
- **Bidirectional**: Forward + backward (`--it`)
- **Random Access**: Jump to any position (`it + 5`)

### **Algorithm Complexity Guarantees**

| Algorithm | Complexity | Container Requirement |
|-----------|-----------|----------------------|
| `find` | O(N) | Input iterator |
| `sort` | O(N log N) | Random access iterator |
| `binary_search` | O(log N) | Sorted + bidirectional |
| `accumulate` | O(N) | Input iterator |
| `unique` | O(N) | Forward iterator |

---

## Performance Considerations

### **Compile-Time vs Runtime Polymorphism**

| Aspect | Templates | Virtual Functions |
|--------|-----------|------------------|
| Resolution | Compile-time | Runtime |
| Overhead | Zero | ~1-2ns per call |
| Code Size | Larger (one per type) | Smaller |
| Flexibility | Type must be known | Works with unknown types |

### **Container Performance**

**Memory**:
- `vector`: Contiguous → excellent cache locality
- `list`: Scattered → poor cache performance
- `map`: Tree nodes → moderate cache misses

**Operations**:
```cpp
std::vector<int> vec;  // Fast: reserve if size known
vec.reserve(1000);

std::list<int> lst;    // Fast: insertions anywhere
lst.insert(it, value); // O(1)

std::map<int, int> m;  // Fast: logarithmic lookup
m[key] = value;        // O(log N)
```

### **Optimization Techniques Learned**
1. **Reserve Capacity**: Pre-allocate for vectors
2. **Move Semantics**: Transfer ownership (C++11)
3. **Const References**: Avoid unnecessary copies
4. **Range-Based For Loops**: Cleaner, potentially faster (C++11)
5. **Algorithm Selection**: `std::find` vs manual loop

---

## Evolution from C to C++

### **C Approach** (Pre-cpp00)
```c
// C-style phonebook
struct Contact {
    char name[50];
    char phone[20];
};

struct Contact phonebook[8];
int count = 0;

void add_contact(const char* name, const char* phone) {
    if (count < 8) {
        strcpy(phonebook[count].name, name);
        strcpy(phonebook[count].phone, phone);
        count++;
    }
}
```

**Issues**:
- No encapsulation (global state)
- Manual memory management (error-prone)
- No type safety
- No extensibility

### **C++ Approach** (cpp00)
```cpp
// C++ phonebook
class Contact {
private:
    std::string _name;
    std::string _phone;
public:
    Contact() {}
    void setName(const std::string& name) { _name = name; }
    std::string getName() const { return _name; }
};

class PhoneBook {
private:
    Contact _contacts[8];
    int _count;
public:
    void addContact(const Contact& contact);
    Contact getContact(int index) const;
};
```

**Improvements**:
- Encapsulation (private data)
- Type safety (`std::string` vs `char*`)
- Automatic memory management
- Extensible (inheritance possible)

### **Advanced C++** (cpp04-09)
```cpp
// Polymorphic, generic phonebook
template <typename T>
class Container {
    std::vector<std::shared_ptr<T>> _items;
public:
    void add(std::shared_ptr<T> item) { _items.push_back(item); }
    
    template <typename Predicate>
    std::vector<std::shared_ptr<T>> find(Predicate pred) {
        std::vector<std::shared_ptr<T>> results;
        std::copy_if(_items.begin(), _items.end(), 
                     std::back_inserter(results), pred);
        return results;
    }
};
```

**Further Improvements**:
- Generic (works with any type)
- Smart pointers (automatic memory)
- STL algorithms (tested, optimized)
- Functional programming (predicates)

---

## Practical Applications

### **Game Development** (cpp03-04)
- Entity hierarchies (Player → Character → Entity)
- Component systems (Has-a relationships)
- Polymorphic behavior (virtual `update()`, `render()`)

### **Financial Software** (cpp02, cpp09)
- Fixed-point arithmetic (currency precision)
- Time-series data (map for historical prices)
- Statistical calculations (Span class patterns)

### **Systems Programming** (cpp01, cpp05)
- Manual memory management (embedded systems)
- Exception handling (error recovery)
- RAII for resource management (file handles, locks)

### **Generic Libraries** (cpp07-08)
- Reusable data structures (Array, Span)
- Algorithm abstraction (iter, easyfind)
- Container extensions (MutantStack)

### **Compiler Design** (cpp09)
- Expression evaluation (RPN calculator)
- Symbol tables (maps for identifiers)
- Syntax tree traversal (stack-based)

---

## Lessons Learned

### **Design Principles**
1. **SOLID Principles**:
   - **S**ingle Responsibility (each class has one purpose)
   - **O**pen/Closed (open for extension, closed for modification)
   - **L**iskov Substitution (derived classes replace base)
   - **I**nterface Segregation (specific interfaces better than general)
   - **D**ependency Inversion (depend on abstractions)

2. **Prefer Composition Over Inheritance**:
   - Inheritance = tight coupling
   - Composition = loose coupling, more flexible

3. **Program to Interfaces, Not Implementations**:
   - Use abstract base classes
   - Depend on contracts, not concrete types

### **Memory Management Philosophy**
- **Default to Stack**: Unless you need persistence, polymorphism, or large size
- **RAII Everywhere**: Wrap resources in classes
- **No Naked new/delete** (use smart pointers in modern C++)
- **Ownership Semantics**: Document who owns/frees memory

### **Template Best Practices**
- **Document Requirements**: What operations must type support?
- **Prefer `typename`**: More accurate than `class`
- **Compile-Time Checking**: Use static_assert, concepts (C++20)
- **Header-Only**: Templates naturally live in headers

### **STL Wisdom**
- **Don't Reinvent the Wheel**: Use existing containers/algorithms
- **Understand Complexity**: Know Big-O of operations
- **Measure Performance**: Profile before optimizing
- **Iterator Invalidation**: Be aware when modifying containers

---

## Future Directions

### **Modern C++ Features** (C++11/14/17/20)
Building on this foundation:

1. **C++11**:
   - Move semantics (`std::move`)
   - Smart pointers (`std::unique_ptr`, `std::shared_ptr`)
   - Lambda expressions
   - Range-based for loops
   - `auto` type deduction

2. **C++14**:
   - Generic lambdas
   - Variable templates
   - Relaxed constexpr

3. **C++17**:
   - `std::optional`, `std::variant`, `std::any`
   - Structured bindings
   - Fold expressions
   - Parallel algorithms

4. **C++20**:
   - Concepts (explicit template constraints)
   - Ranges library
   - Coroutines
   - Modules

### **Advanced Topics**
- **Metaprogramming**: Compile-time computation with templates
- **Concurrency**: `std::thread`, `std::async`, atomics
- **Move Semantics**: Rvalue references, perfect forwarding
- **Expression Templates**: Lazy evaluation for DSLs
- **Policy-Based Design**: Configurable behavior via templates

---

## Conclusion

This C++ journey represents a transformation from imperative, procedure-oriented thinking to declarative, object-oriented, and generic programming paradigms. Each module builds upon previous concepts, creating a comprehensive understanding of C++'s philosophy: **zero-cost abstractions with maximum expressiveness**.

**Key Takeaways**:
- **C++ is not just "C with classes"**: It's a multi-paradigm language
- **Memory management is fundamental**: Understanding ownership is crucial
- **Templates enable zero-cost abstraction**: Performance without compromise
- **STL is a masterclass in design**: Algorithms + Containers + Iterators
- **Modern C++ builds on these foundations**: But core principles remain

The skills acquired through these modules form the bedrock for professional C++ development, whether in systems programming, game development, financial software, or high-performance computing. The patterns, idioms, and techniques learned here are timeless—applicable across C++ versions and domain-specific applications.

---

## Repository Structure

```
cpp/
├── README.md (this file)
│
├── cpp00/ (Basics)
│   ├── README.md
│   ├── ex00/ (Megaphone)
│   └── ex01/ (PhoneBook)
│
├── cpp01/ (Memory)
│   ├── README.md
│   ├── ex00/ (Zombie)
│   ├── ex01/ (ZombieHorde)
│   ├── ex02/ (Brain)
│   ├── ex03/ (Weapon)
│   ├── ex04/ (Sed)
│   ├── ex05/ (Harl)
│   └── ex06/ (HarlFilter)
│
├── cpp02/ (Operators)
│   ├── README.md
│   ├── ex00/ (Fixed - Basic)
│   ├── ex01/ (Fixed - Conversions)
│   ├── ex02/ (Fixed - Operators)
│   └── ex03/ (BSP)
│
├── cpp03/ (Inheritance)
│   ├── README.md
│   ├── ex00/ (ClapTrap)
│   ├── ex01/ (ScavTrap)
│   ├── ex02/ (FragTrap)
│   └── ex03/ (DiamondTrap)
│
├── cpp04/ (Polymorphism)
│   ├── README.md
│   ├── ex00/ (Animal)
│   ├── ex01/ (Brain)
│   ├── ex02/ (Abstract)
│   └── ex03/ (Materia)
│
├── cpp05/ (Exceptions)
│   ├── README.md
│   ├── ex00/ (Bureaucrat)
│   ├── ex01/ (Form)
│   ├── ex02/ (Concrete Forms)
│   └── ex03/ (Intern)
│
├── cpp06/ (Casts)
│   ├── README.md
│   ├── ex00/ (ScalarConverter)
│   ├── ex01/ (Serialize)
│   └── ex02/ (Identify)
│
├── cpp07/ (Templates)
│   ├── README.md
│   ├── ex00/ (Function Templates)
│   ├── ex01/ (iter)
│   └── ex02/ (Array)
│
├── cpp08/ (STL)
│   ├── README.md
│   ├── ex00/ (easyfind)
│   ├── ex01/ (Span)
│   └── ex02/ (MutantStack)
│
└── cpp09/ (Advanced)
    ├── README.md
    ├── ex00/ (BitcoinExchange)
    ├── ex01/ (RPN)
    └── ex02/ (PmergeMe)
```

---

## Compilation & Testing

Each module compiles with:
```bash
make
```

Flags used (C++98 standard):
```
-Wall -Wextra -Werror -std=c++98
```

Memory leak checking:
```bash
valgrind --leak-check=full ./program
```

---

**Author**: Valeria Fedorova  
**Institution**: 42 School  
**Date**: 2024-2025  
**Language Standard**: C++98/03  

---

*"C++ is a multi-paradigm programming language that supports procedural, object-oriented, and generic programming. This journey through its foundations prepares you for mastery of one of the most powerful and widely-used languages in software engineering."*