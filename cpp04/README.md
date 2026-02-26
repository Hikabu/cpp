# CPP Module 04: Subtype Polymorphism, Abstract Classes, Interfaces

## Overview

This module introduces **runtime polymorphism**, the third pillar of object-oriented programming. Through virtual functions, abstract classes, and interfaces, it demonstrates how to write code that operates on base class pointers/references while executing derived class behavior—enabling extensibility without modifying existing code.

## Core Concepts Explored

### 1. **Polymorphism (Dynamic Binding)**
The ability for objects of different classes to be treated uniformly:

```cpp
Animal* animal = new Dog();
animal->makeSound();  // Calls Dog::makeSound(), not Animal::makeSound()
```

**Key Mechanism**: Virtual function table (vtable) enables runtime dispatch.

**Types of Polymorphism**:
- **Compile-Time (Static)**: Function/operator overloading, templates
- **Runtime (Dynamic)**: Virtual functions, inheritance hierarchies

### 2. **Virtual Functions**
```cpp
class Animal {
public:
    virtual void makeSound() const {  // 'virtual' enables override
        std::cout << "Generic animal sound" << std::endl;
    }
    virtual ~Animal() {}  // CRITICAL: Virtual destructor
};

class Dog : public Animal {
public:
    void makeSound() const override {  // 'override' is optional but recommended
        std::cout << "Woof!" << std::endl;
    }
};
```

**How it Works**:
- Each polymorphic class has a hidden **vtable pointer** (vptr)
- Vtable contains function pointers to virtual functions
- Runtime dispatch: `object->vptr->function_table[index]()`

### 3. **Abstract Classes & Pure Virtual Functions**
A class with at least one pure virtual function:

```cpp
class AAnimal {  // Abstract class (cannot instantiate)
public:
    virtual void makeSound() const = 0;  // Pure virtual (= 0)
    virtual ~AAnimal() {}
};

// Error: Cannot instantiate abstract class
// AAnimal a;  ❌

// OK: Pointer to abstract class
AAnimal* a = new Dog();  ✅
```

**Purpose**: Define interface contracts that derived classes must implement.

### 4. **Deep Copy vs Shallow Copy**
Critical when classes contain dynamically allocated resources:

```cpp
class Brain {
    std::string* _ideas;  // Dynamic array
public:
    Brain() { _ideas = new std::string[100]; }
    
    // Shallow copy (BAD - default behavior):
    // Brain(const Brain& other) : _ideas(other._ideas) {}  ❌ Both point to same array
    
    // Deep copy (GOOD):
    Brain(const Brain& other) {
        _ideas = new std::string[100];
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];  ✅ Separate copies
    }
};
```

**Rule**: If class manages resources (pointers, file handles), implement deep copy.

## Problem-Solving Architecture

### Exercise 00: Polymorphism Basics (Animal Hierarchy)
**Concept**: Virtual functions enable polymorphic behavior

#### Class Hierarchy:
```
    Animal (+ makeSound())
      /        \
    Dog        Cat
(Woof!)     (Meow!)

  WrongAnimal (- makeSound())  // Not virtual!
      |
  WrongCat
```

#### Implementation Strategy:
```cpp
class Animal {
protected:
    std::string _type;
    
public:
    Animal() : _type("Animal") {}
    Animal(const Animal& copy) : _type(copy._type) {}
    Animal& operator=(const Animal& copy) {
        _type = copy._type;
        return *this;
    }
    virtual ~Animal() {}  // MUST be virtual for polymorphic deletion
    
    std::string getType() const { return _type; }
    virtual void makeSound() const {
        std::cout << "Generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() { _type = "Dog"; }
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() { _type = "Cat"; }
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};
```

#### Testing Polymorphism:
```cpp
int main() {
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << std::endl;  // Output: Dog
    dog->makeSound();  // Output: Woof! Woof! (Dog's version)
    
    cat->makeSound();  // Output: Meow! Meow! (Cat's version)
    meta->makeSound(); // Output: Generic animal sound
    
    delete meta;
    delete dog;  // Calls ~Dog() then ~Animal() (virtual destructor chain)
    delete cat;
    
    return 0;
}
```

#### WrongAnimal (Demonstrating Non-Virtual Behavior):
```cpp
class WrongAnimal {
protected:
    std::string _type;
public:
    void makeSound() const {  // NOT virtual!
        std::cout << "Wrong animal sound" << std::endl;
    }
};

class WrongCat : public WrongAnimal {
public:
    void makeSound() const {  // Shadows base function, doesn't override
        std::cout << "Wrong meow!" << std::endl;
    }
};

// Testing:
WrongAnimal* wrongCat = new WrongCat();
wrongCat->makeSound();  // Output: Wrong animal sound (base version, NOT polymorphic!)
```

**Critical Lesson**: Without `virtual`, function calls are resolved at compile-time based on pointer type, not object type.

### Exercise 01: Brain Class & Deep Copy
**Concept**: Managing complex object composition with polymorphism

#### Brain Implementation:
```cpp
class Brain {
private:
    std::string _ideas[100];
    
public:
    Brain() {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = "💡 Idea " + std::to_string(i);
        }
    }
    
    // Deep copy constructor
    Brain(const Brain& copy) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = copy._ideas[i];
        }
    }
    
    // Deep copy assignment
    Brain& operator=(const Brain& copy) {
        if (this != &copy) {
            for (int i = 0; i < 100; i++) {
                _ideas[i] = copy._ideas[i];
            }
        }
        return *this;
    }
    
    ~Brain() {}
    
    void setIdea(int index, std::string idea) {
        if (index >= 0 && index < 100)
            _ideas[index] = idea;
    }
    
    std::string getIdea(int index) const {
        return (index >= 0 && index < 100) ? _ideas[index] : "";
    }
};
```

#### Dog/Cat with Brain:
```cpp
class Dog : public Animal {
private:
    Brain* _brain;  // Dynamically allocated
    
public:
    Dog() {
        _type = "Dog";
        _brain = new Brain();
    }
    
    // Deep copy constructor
    Dog(const Dog& copy) : Animal(copy) {
        _brain = new Brain(*copy._brain);  // Copy brain content, not pointer
    }
    
    // Deep copy assignment
    Dog& operator=(const Dog& copy) {
        if (this != &copy) {
            Animal::operator=(copy);
            delete _brain;  // Free old brain
            _brain = new Brain(*copy._brain);  // Allocate new brain with copied content
        }
        return *this;
    }
    
    ~Dog() {
        delete _brain;  // MUST free dynamically allocated memory
    }
    
    Brain* getBrain() const { return _brain; }
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};
```

#### Testing Deep Copy:
```cpp
int main() {
    Dog original;
    original.getBrain()->setIdea(0, "Chase squirrels!");
    
    Dog copy = original;  // Deep copy
    copy.getBrain()->setIdea(0, "Nap in the sun");
    
    // Verify they're independent:
    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
    // Output: Chase squirrels! (unchanged)
    
    std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;
    // Output: Nap in the sun
    
    return 0;
}
```

**Memory Leak Test**:
```cpp
Dog* dogs = new Dog[10];
delete[] dogs;  // Must properly deallocate 10 brains + 10 dogs

// Valgrind should show: all heap blocks were freed -- no leaks possible
```

### Exercise 02: Abstract Classes (AAnimal)
**Concept**: Prevent instantiation of base class, enforce interface implementation

#### Abstract Base Class:
```cpp
class AAnimal {  // "A" prefix convention for Abstract
protected:
    std::string _type;
    
public:
    AAnimal() : _type("AAnimal") {}
    AAnimal(const AAnimal& copy) : _type(copy._type) {}
    AAnimal& operator=(const AAnimal& copy) {
        _type = copy._type;
        return *this;
    }
    virtual ~AAnimal() {}
    
    std::string getType() const { return _type; }
    
    virtual void makeSound() const = 0;  // Pure virtual function
};

// Compilation error:
// AAnimal a;  ❌ Cannot instantiate abstract class

// OK:
AAnimal* a = new Dog();  ✅ Pointer to abstract class is fine
```

#### Derived Class MUST Implement Pure Virtual Functions:
```cpp
class Dog : public AAnimal {
private:
    Brain* _brain;
    
public:
    Dog() {
        _type = "Dog";
        _brain = new Brain();
    }
    
    // MUST implement makeSound() or Dog itself becomes abstract
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
    
    ~Dog() { delete _brain; }
};
```

**Design Pattern**: Abstract base classes define **interface contracts**. Derived classes provide **concrete implementations**.

### Exercise 03: Materia System (Interface Design)
**Concept**: Complex interface hierarchy with runtime type identification

#### Abstract Materia Interface:
```cpp
class AMateria {
protected:
    std::string _type;
    
public:
    AMateria(std::string const& type) : _type(type) {}
    AMateria(const AMateria& copy) : _type(copy._type) {}
    virtual ~AMateria() {}
    
    std::string const& getType() const { return _type; }
    
    virtual AMateria* clone() const = 0;  // Factory method pattern
    virtual void use(ICharacter& target) = 0;  // Polymorphic behavior
};
```

#### Concrete Materia Classes:
```cpp
class Ice : public AMateria {
public:
    Ice() : AMateria("ice") {}
    Ice(const Ice& copy) : AMateria(copy) {}
    
    AMateria* clone() const override {
        return new Ice(*this);  // Return copy of self
    }
    
    void use(ICharacter& target) override {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    }
};

class Cure : public AMateria {
public:
    Cure() : AMateria("cure") {}
    
    AMateria* clone() const override {
        return new Cure(*this);
    }
    
    void use(ICharacter& target) override {
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    }
};
```

#### Character Interface & Implementation:
```cpp
class ICharacter {  // "I" prefix convention for Interface
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inventory[4];  // Fixed size inventory
    
public:
    Character(std::string name) : _name(name) {
        for (int i = 0; i < 4; i++)
            _inventory[i] = nullptr;
    }
    
    ~Character() {
        for (int i = 0; i < 4; i++)
            delete _inventory[i];  // Clean up equipped materia
    }
    
    std::string const& getName() const override { return _name; }
    
    void equip(AMateria* m) override {
        if (!m) return;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] == nullptr) {
                _inventory[i] = m;
                return;
            }
        }
        // Inventory full, materia not equipped (should be deleted by caller)
    }
    
    void unequip(int idx) override {
        if (idx >= 0 && idx < 4)
            _inventory[idx] = nullptr;  // DON'T delete (caller's responsibility)
    }
    
    void use(int idx, ICharacter& target) override {
        if (idx >= 0 && idx < 4 && _inventory[idx])
            _inventory[idx]->use(target);
    }
};
```

#### Materia Source (Factory Pattern):
```cpp
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource {
private:
    AMateria* _learned[4];
    
public:
    MateriaSource() {
        for (int i = 0; i < 4; i++)
            _learned[i] = nullptr;
    }
    
    ~MateriaSource() {
        for (int i = 0; i < 4; i++)
            delete _learned[i];
    }
    
    void learnMateria(AMateria* m) override {
        if (!m) return;
        for (int i = 0; i < 4; i++) {
            if (_learned[i] == nullptr) {
                _learned[i] = m;
                return;
            }
        }
        delete m;  // Can't learn more, delete it
    }
    
    AMateria* createMateria(std::string const& type) override {
        for (int i = 0; i < 4; i++) {
            if (_learned[i] && _learned[i]->getType() == type)
                return _learned[i]->clone();  // Factory method
        }
        return nullptr;  // Type not learned
    }
};
```

#### Usage Example:
```cpp
int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);  // * shoots an ice bolt at bob *
    me->use(1, *bob);  // * heals bob's wounds *
    
    delete bob;
    delete me;
    delete src;
    
    return 0;
}
```

## Key Principles Demonstrated

1. **Open/Closed Principle**: Open for extension (new animals), closed for modification (Animal class unchanged)
2. **Liskov Substitution Principle**: Derived objects can replace base objects without breaking code
3. **Interface Segregation**: Classes implement only methods they need (ICharacter vs IMateriaSource)
4. **Dependency Inversion**: Depend on abstractions (ICharacter*), not concretions (Character*)
5. **Factory Pattern**: `clone()` and `createMateria()` create objects without specifying exact class

## Technical Challenges & Solutions

### Challenge 1: Virtual Destructor Memory Leaks
**Problem**: Without virtual destructor, derived class destructor not called
```cpp
Animal* dog = new Dog();
delete dog;  // Without virtual ~Animal(), only ~Animal() called, _brain leaked!
```
**Solution**: Always make destructor virtual in polymorphic base classes

### Challenge 2: Deep Copy with Inheritance
**Problem**: Base class copy constructor doesn't copy derived members
**Solution**: 
```cpp
Dog::Dog(const Dog& copy) : Animal(copy) {  // Call base copy constructor
    _brain = new Brain(*copy._brain);       // Copy derived members
}
```

### Challenge 3: Abstract Class Instantiation
**Problem**: Accidentally trying to create abstract class objects
**Solution**: Compiler error prevents this—feature, not bug!

### Challenge 4: Memory Management with Interfaces
**Problem**: Who owns/deletes heap-allocated objects?
**Solution**: Document ownership clearly (e.g., `unequip` doesn't delete, caller must)

## Lessons Learned

### Polymorphism Design
- **Virtual Destructor is Mandatory**: For any class used polymorphically
- **Abstract Classes Define Contracts**: Pure virtual functions enforce implementation
- **Clone Pattern**: Useful for copying polymorphic objects when exact type unknown
- **Interface Naming**: Prefix with "I" or "A" for clarity

### Memory Management
- **Deep Copy Essential**: When managing dynamic resources
- **Ownership Semantics**: Document who deletes what
- **RAII Saves Lives**: Destructors automatically clean up
- **Valgrind is Your Friend**: Use memory checkers to verify no leaks

### Object-Oriented Design
- **Prefer Interfaces**: Code against Abstract base classes, not concrete types
- **Factory Pattern**: Encapsulate object creation logic
- **Single Responsibility**: Each class has one reason to change

## Practical Applications

- **Plugin Systems**: Load derived classes at runtime (game mods, browser extensions)
- **Graphics Rendering**: Shape* polymorphism (draw different shapes uniformly)
- **Message Processing**: Handler* hierarchy for different message types
- **UI Frameworks**: Widget* base class with Button, Slider, TextBox derived classes
- **Strategy Pattern**: Algorithm* interface with different implementations

## Common Pitfalls

1. **Non-Virtual Destructor**: Leads to memory leaks with polymorphism
2. **Slicing**: Assigning derived to base by value copies only base parts
3. **Forgetting `override`**: Typos in signature create new function instead of overriding
4. **Virtual Function in Constructor**: Calls base version, not derived (object not fully constructed yet)
5. **Shallow Copy Default**: Compiler-generated copy constructor does shallow copy

## Performance Considerations

- **Virtual Function Call Overhead**: ~1-2 nanoseconds (usually negligible)
- **Vtable Space**: One pointer per object + one table per class (small)
- **Cache Effects**: Indirect function call can cause cache misses
- **When to Avoid**: Tight inner loops with performance requirements (rare)

---

*This module completes the OOP trilogy: encapsulation (cpp00), inheritance (cpp03), and polymorphism (cpp04). Together, these enable flexible, extensible architectures. Modern C++ extends these concepts with templates (cpp07) and smart pointers, but the principles remain unchanged. Understanding virtual functions deeply is essential for designing maintainable, scalable systems.*
