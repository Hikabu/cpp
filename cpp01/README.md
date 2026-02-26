# CPP Module 01: Memory Allocation, Pointers to Members, References, Switch Statement

## Overview

This module explores one of C++'s most critical and nuanced topics: **memory management**. It establishes the fundamental distinction between stack and heap allocation, introduces references as a safer alternative to pointers, and demonstrates the lifecycle implications of different memory allocation strategies.

## Core Concepts Explored

### 1. **Stack vs Heap Allocation**
Understanding where objects live in memory fundamentally shapes program architecture:

**Stack Allocation**:
- Automatic storage duration
- LIFO (Last In, First Out) deallocation
- Fast allocation/deallocation
- Limited size (typically 1-8 MB)
- Scope-bound lifetime

**Heap Allocation**:
- Dynamic storage duration
- Manual deallocation required
- Slower than stack (system calls involved)
- Large available space
- Persists beyond scope until explicitly freed

### 2. **Pointers vs References**
A pivotal distinction that affects API design and safety:

| Aspect | Pointer | Reference |
|--------|---------|-----------|
| Nullability | Can be `nullptr` | Cannot be null |
| Reassignment | Can point to different objects | Binds once, permanently |
| Syntax | Requires dereferencing (`*ptr`) | Direct access (transparent) |
| Initialization | Can be uninitialized | Must be initialized |
| Use Case | Optional parameters, dynamic arrays | Function parameters, cleaner syntax |

### 3. **Resource Acquisition Is Initialization (RAII) Foundations**
Though not explicitly named, this module introduces RAII principles:
- Constructors acquire resources
- Destructors release resources
- Automatic cleanup when objects go out of scope

## Problem-Solving Architecture

### Exercise 00: BraiiiiiiinnnzzzZ (Zombie - Heap Allocation)
**Concept**: Dynamic memory management and lifetime control

#### Problem Context:
How do you create objects that outlive the function where they're created?

#### Solution Architecture:
```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name);  // Heap allocation
}

void randomChump(std::string name) {
    Zombie zombie(name);      // Stack allocation
    zombie.announce();
}  // zombie automatically destroyed here
```

**Key Insight**: 
- `newZombie()` returns a pointer that must be manually deleted
- `randomChump()` creates a temporary zombie that self-destructs
- **Decision Factor**: Does the object need to outlive the function?

**Memory Management Strategy**:
```cpp
Zombie* heapZombie = newZombie("HeapWalker");
heapZombie->announce();
delete heapZombie;  // MUST manually free

randomChump("StackWalker");  // Automatic cleanup
```

### Exercise 01: Moar Brainz! (Zombie Horde - Array Allocation)
**Concept**: Dynamic array management and constructor behavior

#### Challenge:
Allocate multiple objects simultaneously with proper initialization.

#### Solution Strategy:
```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];  // Allocates N zombies
    
    for (int i = 0; i < N; i++) {
        // Initialization logic
        horde[i].setName(name);
    }
    
    return horde;
}
```

**Critical Observations**:
1. **Default Constructor Required**: Array allocation calls default constructor
2. **Post-Construction Initialization**: Can't pass parameters to constructor in array `new`
3. **Batch Deallocation**: Must use `delete[]` not `delete`

**Common Pitfall**:
```cpp
Zombie* horde = new Zombie[5];
delete horde;      // ❌ WRONG: Only deletes first element, leaks memory
delete[] horde;    // ✅ CORRECT: Deletes entire array
```

### Exercise 02: HI THIS IS BRAIN (References Deep Dive)
**Concept**: Understanding reference semantics and memory addressing

#### Educational Purpose:
Demonstrate that references are **aliases**, not copies:

```cpp
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;
std::string& stringREF = brain;

// All three print the SAME address:
std::cout << &brain;      // 0x7ffeefb42a30
std::cout << stringPTR;   // 0x7ffeefb42a30
std::cout << &stringREF;  // 0x7ffeefb42a30
```

**Key Lesson**: References are not separate objects; they're alternate names for existing objects.

### Exercise 03: Unnecessary Violence (Weapon Class - Reference Parameters)
**Concept**: Reference parameters for shared state management

#### Architecture:
```
HumanA (Has-a Weapon&)  ← Reference: MUST always have weapon
    └── Weapon& _weapon (Cannot be null)

HumanB (Has-a Weapon*)  ← Pointer: MAY have weapon
    └── Weapon* _weapon (Can be nullptr)
```

#### Design Decision:
**Why does HumanA use reference while HumanB uses pointer?**

```cpp
class HumanA {
    Weapon& _weapon;  // Reference: Set in constructor, never null
public:
    HumanA(std::string name, Weapon& weapon) 
        : _weapon(weapon) {}  // Must initialize in member initializer list
};

class HumanB {
    Weapon* _weapon;  // Pointer: Can be set later, can be null
public:
    HumanB(std::string name) : _weapon(nullptr) {}
    void setWeapon(Weapon& weapon) { _weapon = &weapon; }
};
```

**Design Pattern**: 
- Use **reference** when association is mandatory and permanent
- Use **pointer** when association is optional or changeable

### Exercise 04: Sed is for Losers (File I/O & String Manipulation)
**Concept**: File stream handling and string processing

#### Problem:
Replace all occurrences of a string in a file without using `sed`.

#### Solution Strategy:
```cpp
1. Open input file (std::ifstream)
2. Open output file (std::ofstream) with ".replace" suffix
3. Read line by line
4. For each line:
   a. Find substring position
   b. Replace with new string
   c. Continue until no more occurrences
5. Write modified content to output file
6. Close both files (RAII handles this automatically)
```

**Key Implementation Detail**:
```cpp
size_t pos = 0;
while ((pos = line.find(s1, pos)) != std::string::npos) {
    line.erase(pos, s1.length());
    line.insert(pos, s2);
    pos += s2.length();  // Critical: Skip past replacement to avoid infinite loop
}
```

**Edge Cases Handled**:
- Empty search string
- Search string not found
- Replacement string contains search string
- File I/O errors

### Exercise 05-06: Harl & HarlFilter (Switch Statement & Log Levels)
**Concept**: Polymorphic behavior based on enumeration/string matching

#### Problem:
Implement a logging system with different severity levels.

#### Architecture:
```cpp
class Harl {
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    void complain(std::string level);
};
```

#### Solution Strategy (Pointer to Member Functions):
```cpp
void Harl::complain(std::string level) {
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();  // Call member function through pointer
            return;
        }
    }
}
```

**Exercise 06 Extension (HarlFilter)**:
Use `switch` statement for cascading log levels:
```cpp
switch (levelCode) {
    case DEBUG:
        debug();
        // Fall through intentionally
    case INFO:
        info();
        // Fall through
    case WARNING:
        warning();
        // Fall through
    case ERROR:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]";
}
```

**Key Pattern**: Fall-through behavior enables "this level and above" semantics.

## Key Principles Demonstrated

1. **Memory Ownership**: Who is responsible for deallocation?
2. **Lifetime Management**: Stack cleanup is automatic, heap requires discipline
3. **Reference Safety**: References can't be null, reducing error potential
4. **Resource Management**: Files, memory, objects all follow acquisition/release patterns
5. **Function Pointers**: Indirection for polymorphic behavior without virtual functions

## Technical Challenges & Solutions

### Challenge 1: Memory Leaks
**Problem**: Forgetting to `delete` heap-allocated memory
**Solution**: 
- Immediate `delete` after use
- Consider smart pointers (introduced in later modules)
- RAII patterns (wrap resources in classes)

### Challenge 2: Dangling Pointers
**Problem**: Pointer to deleted memory still exists
**Solution**:
```cpp
delete ptr;
ptr = nullptr;  // Explicitly null out pointer
```

### Challenge 3: Reference Initialization
**Problem**: References must be initialized immediately
**Solution**: Use member initializer lists in constructors
```cpp
ClassName::ClassName(Type& ref) : _reference(ref) {
    // Reference is already bound
}
```

## Lessons Learned

### Memory Management Philosophy
- **Default to stack allocation** unless you need:
  - Persistence beyond scope
  - Large objects
  - Polymorphic behavior (virtual functions)
- **Prefer references** over pointers for function parameters
- **Document ownership** clearly (who deletes what?)

### API Design
- Use references for **required, non-null** parameters
- Use pointers for **optional or mutable** associations
- Use const references for read-only access to large objects

### Debugging Skills
- Valgrind for memory leak detection
- Address Sanitizer for use-after-free bugs
- Defensive null checks before dereferencing pointers

## Practical Applications

- **Game Development**: Entity lifecycle management (stack for temporary, heap for persistent)
- **Resource Management**: File handles, network connections (RAII pattern)
- **Data Structures**: Dynamic arrays, linked lists (heap allocation essential)
- **API Design**: Reference parameters for efficiency without copying

## Common Pitfalls

1. **Memory Leaks**: Not deleting heap allocations
2. **Double Free**: Deleting same memory twice
3. **Array Delete Mismatch**: Using `delete` instead of `delete[]`
4. **Dangling References**: Returning reference to local variable
5. **Uninitialized References**: Forgetting to initialize references

---

*This module is foundational for understanding C++'s manual memory management. While modern C++ favors smart pointers (std::unique_ptr, std::shared_ptr), understanding raw pointers and references is essential for comprehending legacy code, performance-critical sections, and the underlying mechanisms of higher-level abstractions.*
