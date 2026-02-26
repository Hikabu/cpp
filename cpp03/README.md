# CPP Module 03: Inheritance

## Overview

This module introduces **inheritance**, one of the three pillars of object-oriented programming (alongside encapsulation and polymorphism). Through the ClapTrap hierarchy, it demonstrates how to build specialized classes from general base classes, manage access control in inheritance hierarchies, and handle resource initialization in derived classes.

## Core Concepts Explored

### 1. **Inheritance Fundamentals**
Inheritance models "is-a" relationships:

```cpp
class ScavTrap : public ClapTrap {
    // ScavTrap IS-A ClapTrap
    // Inherits all ClapTrap members
    // Can add new members
    // Can override inherited functions
};
```

**Three Types of Inheritance**:
- **Public**: Public members stay public, protected stay protected
- **Protected**: Public and protected members become protected
- **Private**: All inherited members become private

**Best Practice**: Almost always use `public` inheritance for "is-a" relationships.

### 2. **Access Control in Inheritance**

| Access Specifier | Same Class | Derived Class | Outside Class |
|-----------------|------------|---------------|---------------|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

**Key Insight**: `protected` exists specifically for inheritance—accessible to derived classes but not external code.

### 3. **Constructor/Destructor Chaining**
**Critical Rule**: Base class constructor executes **before** derived class constructor.

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // ClapTrap constructor already executed
    // Now customize for ScavTrap
    _energyPoints = 50;  // Override base value
}
```

**Destruction Order**: Reverse of construction (derived destructor → base destructor).

### 4. **Diamond Problem (Multiple Inheritance)**
Occurs when a class inherits from two classes that share a common base:

```
     ClapTrap
      /    \
ScavTrap  FragTrap
      \    /
    DiamondTrap  ← Two copies of ClapTrap? Ambiguity!
```

**Solution**: Virtual inheritance
```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
```

**Result**: Only **one** instance of ClapTrap in DiamondTrap.

## Problem-Solving Architecture

### Exercise 00: ClapTrap (Base Class)
**Concept**: Design a base class suitable for inheritance

#### Class Design:
```cpp
class ClapTrap {
protected:  // Not private! Allow derived class access
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
    
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);
    ~ClapTrap();
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
```

**Design Decisions**:
1. **Protected Members**: Derived classes need direct access to attributes
2. **Unsigned Integers**: HP/Energy/Damage can't be negative (conceptually)
3. **Virtual Destructor**: Not needed yet (no polymorphism), but good practice

**Behavior Logic**:
```cpp
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
```

**State Management**: Actions require energy and being alive (HP > 0).

### Exercise 01: ScavTrap (Single Inheritance)
**Concept**: Extend base class with modified attributes and new behavior

#### Inheritance Strategy:
```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);
    ~ScavTrap();
    
    void guardGate();  // New unique behavior
    void attack(const std::string& target); // Override base behavior
};
```

**Constructor Implementation**:
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;      // Override base value (10)
    _energyPoints = 50;    // Override base value (10)
    _attackDamage = 20;    // Override base value (0)
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}
```

**Construction Order Output**:
```
ClapTrap Scavvy constructed!  ← Base first
ScavTrap Scavvy constructed!  ← Derived second
```

**Overriding `attack()`**:
```cpp
void ScavTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " can't attack!" << std::endl;
        return;
    }
    // Same logic as ClapTrap but with "ScavTrap" label
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
```

**Design Question**: Why override if logic is identical?
**Answer**: Different message output ("ScavTrap" vs "ClapTrap"). In real applications, derived classes typically have genuinely different behavior.

**New Behavior**:
```cpp
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
```

### Exercise 02: FragTrap (Another Derived Class)
**Concept**: Multiple classes can inherit from the same base

#### Class Structure:
```cpp
class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap();
    
    void highFivesGuys();  // Unique behavior
};
```

**Constructor**:
```cpp
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;   // Different from ScavTrap (50)
    _attackDamage = 30;    // Different from ScavTrap (20)
    std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}
```

**Parallel Hierarchy**:
```
        ClapTrap
         /    \
    ScavTrap  FragTrap
```

Both derive from ClapTrap but are **siblings**, not parent-child.

### Exercise 03: DiamondTrap (Diamond Problem Resolution)
**Concept**: Multiple inheritance with common base class

#### The Challenge:
```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
    // Problem: DiamondTrap has TWO ClapTraps!
    // - One from ScavTrap inheritance path
    // - One from FragTrap inheritance path
};
```

**Solution: Virtual Inheritance**:
```cpp
// Modify base classes:
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };

// Now DiamondTrap has only ONE ClapTrap:
class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;  // Shadows ClapTrap::_name
    
public:
    DiamondTrap(std::string name);
    void whoAmI();
};
```

**Constructor Complexity**:
```cpp
DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"),  // Most derived class calls virtual base directly
      ScavTrap(name),
      FragTrap(name),
      _name(name) 
{
    // Attributes from multiple parents:
    _hitPoints = FragTrap::_hitPoints;        // 100 from FragTrap
    _energyPoints = ScavTrap::_energyPoints;  // 50 from ScavTrap
    _attackDamage = FragTrap::_attackDamage;  // 30 from FragTrap
}
```

**Critical Virtual Inheritance Rule**: 
When using virtual inheritance, the **most derived class** (DiamondTrap) is responsible for calling the virtual base (ClapTrap) constructor, NOT the intermediate classes (ScavTrap/FragTrap).

**Construction Order with Virtual Inheritance**:
```
1. ClapTrap (virtual base)
2. ScavTrap
3. FragTrap
4. DiamondTrap
```

**Member Function Resolution**:
```cpp
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);  // Explicitly use ScavTrap's version
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
```

**Name Disambiguation**:
- `_name` (no qualifier) → DiamondTrap's own member
- `ClapTrap::_name` → Base class member (ends with "_clap_name")

## Key Principles Demonstrated

1. **Code Reuse**: Derived classes inherit base functionality without duplication
2. **Specialization**: Derived classes customize or extend base behavior
3. **Access Control**: `protected` enables controlled sharing with derived classes
4. **Construction Order**: Base before derived (foundation before building)
5. **Virtual Inheritance**: Required for proper resolution of diamond inheritance

## Technical Challenges & Solutions

### Challenge 1: Member Access in Derived Classes
**Problem**: Can't access private base members
**Solution**: Use `protected` or provide public getters/setters

```cpp
// Base class:
protected:
    std::string _name;  // Accessible to derived classes
```

### Challenge 2: Constructor Initialization
**Problem**: Derived class constructor needs to initialize base class
**Solution**: Member initializer list with base class constructor

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Base initialization complete before entering body
}
```

### Challenge 3: Diamond Problem Ambiguity
**Problem**: `DiamondTrap::_name` is ambiguous (which ClapTrap?)
**Solution**: Virtual inheritance + explicit constructor call

```cpp
class ScavTrap : virtual public ClapTrap { ... };
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) { ... }
```

### Challenge 4: Method Name Collision
**Problem**: Multiple base classes have methods with same name
**Solution**: Explicit qualification

```cpp
ScavTrap::attack(target);  // Specify which base class method
```

## Lessons Learned

### Inheritance Design
- **Prefer Composition Over Inheritance**: Use inheritance for true "is-a" relationships
- **Protected Members**: Design base classes knowing derived classes will access internals
- **Virtual Destructors**: Always virtual if class is designed for inheritance with polymorphism
- **Shallow vs Deep Hierarchies**: Avoid deep inheritance trees (maintenance nightmare)

### Virtual Inheritance
- **Performance Cost**: Virtual inheritance has runtime overhead (virtual table)
- **Constructor Responsibility**: Most derived class calls virtual base constructor
- **When to Use**: Only when diamond inheritance is genuinely needed (rare)

### C++ Specifics
- **Friend Classes**: Can grant derived classes special access (advanced)
- **Private Inheritance**: Exists but rarely used (implementation detail, not "is-a")
- **Multiple Inheritance**: Powerful but complex (many languages avoid it entirely)

## Practical Applications

- **GUI Frameworks**: Widget → Button, Widget → Slider (common base)
- **Game Development**: Entity → Player, Entity → Enemy (shared behavior)
- **Network Protocol Stacks**: Transport → TCP, Transport → UDP
- **Shape Hierarchies**: Shape → Circle, Shape → Rectangle (polymorphic rendering)

## Common Pitfalls

1. **Private Base Members**: Derived classes can't access them—use `protected`
2. **Forgetting Base Constructor**: Compiler calls default, might not initialize properly
3. **Shadowing Members**: Derived class member hides base member (use scope resolution)
4. **Non-Virtual Destructors**: Leads to memory leaks in polymorphic scenarios (next module)
5. **Over-Engineering**: Not everything needs inheritance hierarchy

## Comparison: Inheritance vs Composition

| Aspect | Inheritance | Composition |
|--------|-------------|-------------|
| Relationship | "is-a" | "has-a" |
| Coupling | Tight (knows parent internals) | Loose (uses interface) |
| Flexibility | Hard to change hierarchy | Easy to swap components |
| Code Reuse | Automatic (inherited) | Manual (delegation) |
| When to Use | True specialization | Assemblage of components |

---

*This module bridges simple classes (cpp00-02) and polymorphism (cpp04). Understanding inheritance mechanics is crucial, but modern C++ emphasizes composition and interfaces over deep inheritance hierarchies. The diamond problem demonstrates why multiple inheritance requires careful design—and why languages like Java avoid it entirely.*
