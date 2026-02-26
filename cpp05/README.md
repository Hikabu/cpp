# CPP Module 05: Repetition and Exceptions

## Overview

This module introduces **exception handling**, C++'s mechanism for managing errors and exceptional conditions. Moving beyond error codes and return values, exceptions enable separation of error-handling logic from business logic, resulting in cleaner, more maintainable code. The Bureaucrat/Form system provides a rich context for exploring exception design patterns.

## Core Concepts Explored

### 1. **Exception Handling Fundamentals**
C++ provides a structured approach to error management:

```cpp
try {
    // Code that might throw
    riskyOperation();
} catch (const SpecificException& e) {
    // Handle specific error
    std::cerr << "Caught: " << e.what() << std::endl;
} catch (const std::exception& e) {
    // Catch any standard exception
    std::cerr << "Unknown error: " << e.what() << std::endl;
} catch (...) {
    // Catch anything else
    std::cerr << "Totally unknown error" << std::endl;
}
```

**Exception Flow**:
1. Throw exception → **unwind stack** (call destructors)
2. Search for matching catch block (type-based)
3. Execute handler
4. Continue after try-catch block (or rethrow)

### 2. **Custom Exception Classes**
Derive from `std::exception` for consistency:

```cpp
class MyException : public std::exception {
public:
    const char* what() const throw() override {  // throw() = noexcept (old syntax)
        return "My custom error message";
    }
};
```

**Best Practice**: Exception classes are typically nested within the class that throws them, providing namespace scoping.

### 3. **RAII and Exception Safety**
**Resource Acquisition Is Initialization** ensures cleanup even during exceptions:

```cpp
void function() {
    Resource r;  // Constructor acquires resource
    
    if (error)
        throw std::runtime_error("Error!");  // Stack unwinds, r's destructor called automatically
    
    // r's destructor called normally if no exception
}
```

**Exception Safety Levels**:
1. **No-throw guarantee**: Never throws (marked `noexcept`)
2. **Strong guarantee**: Operation succeeds completely or has no effect (rollback)
3. **Basic guarantee**: No resource leaks, but program state may change
4. **No guarantee**: Undefined behavior possible (avoid!)

### 4. **When to Use Exceptions**
**Use exceptions for**:
- Truly exceptional conditions (not normal control flow)
- Constructor failures (can't return error codes)
- Deep call stacks (avoid error code passing through many levels)

**Don't use exceptions for**:
- Expected conditions (e.g., empty collection)
- Performance-critical paths (exception throwing is expensive)
- Simple validation (return bool instead)

## Problem-Solving Architecture

### Exercise 00: Bureaucrat Class (Basic Exceptions)
**Concept**: Input validation with custom exception classes

#### Class Design:
```cpp
class Bureaucrat {
private:
    const std::string _name;  // Immutable
    int _grade;               // Mutable (1 = highest, 150 = lowest)
    
public:
    Bureaucrat(const std::string& name, int grade);
    
    // Getters
    std::string getName() const { return _name; }
    int getGrade() const { return _grade; }
    
    // Grade modification
    void incrementGrade();  // Increase rank (decrease number)
    void decrementGrade();  // Decrease rank (increase number)
    
    // Nested exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() override {
            return "Grade is too high! (minimum is 1)";
        }
    };
    
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() override {
            return "Grade is too low! (maximum is 150)";
        }
    };
};
```

#### Constructor Implementation:
```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}
```

**Key Decision**: Throw exception **before** initializing invalid state (maintain invariants).

#### Increment/Decrement Logic:
```cpp
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;  // Lower number = higher grade
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;  // Higher number = lower grade
}
```

**Counterintuitive**: "Incrementing" grade means **decreasing** the number (grade 2 → grade 1).

#### Stream Insertion Operator:
```cpp
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
```

#### Usage Example:
```cpp
try {
    Bureaucrat bob("Bob", 2);
    std::cout << bob << std::endl;  // Bob, bureaucrat grade 2
    
    bob.incrementGrade();
    std::cout << bob << std::endl;  // Bob, bureaucrat grade 1
    
    bob.incrementGrade();  // Will throw!
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

try {
    Bureaucrat invalid("Invalid", 200);  // Constructor throws immediately
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

### Exercise 01: Form to Sign (Object Interaction with Exceptions)
**Concept**: Authorization checks and state management with exceptions

#### Form Class:
```cpp
class Form {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;    // Required grade to sign
    const int _gradeToExecute;  // Required grade to execute
    
public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    
    // Getters
    std::string getName() const { return _name; }
    bool isSigned() const { return _signed; }
    int getGradeToSign() const { return _gradeToSign; }
    int getGradeToExecute() const { return _gradeToExecute; }
    
    // Business logic
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Exceptions
    class GradeTooHighException : public std::exception {
        const char* what() const throw() override {
            return "Grade too high for form!";
        }
    };
    
    class GradeTooLowException : public std::exception {
        const char* what() const throw() override {
            return "Grade too low for form!";
        }
    };
};
```

#### Form Constructor:
```cpp
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
```

#### Signing Logic:
```cpp
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}
```

**Design Pattern**: Form validates authorization, not Bureaucrat (Single Responsibility).

#### Bureaucrat Integration:
```cpp
class Bureaucrat {
    // ... previous members ...
    
    void signForm(Form& form) {
        try {
            form.beSigned(*this);
            std::cout << _name << " signed " << form.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cout << _name << " couldn't sign " << form.getName() 
                      << " because " << e.what() << std::endl;
        }
    }
};
```

**Exception Handling Strategy**: Bureaucrat catches Form's exceptions and provides user-friendly output.

#### Usage:
```cpp
try {
    Bureaucrat alice("Alice", 50);
    Form taxForm("Tax Form", 40, 30);
    
    alice.signForm(taxForm);  // Should succeed (50 < 40? No, fails!)
    // Output: Alice couldn't sign Tax Form because Grade too low for form!
    
    Bureaucrat boss("Boss", 30);
    boss.signForm(taxForm);  // Succeeds
    // Output: Boss signed Tax Form
    
} catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
}
```

### Exercise 02: Abstract Form Classes (Template Method Pattern)
**Concept**: Polymorphic forms with shared execution logic

#### Abstract Base Class:
```cpp
class AForm {  // Now abstract
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    
protected:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    
public:
    virtual ~AForm() {}
    
    // Getters (same as before)
    
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Template method
    void execute(const Bureaucrat& executor) const {
        if (!_signed)
            throw FormNotSignedException();
        if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        
        executeAction();  // Delegate to derived class
    }
    
    // Pure virtual - derived classes implement specific behavior
    virtual void executeAction() const = 0;
    
    // Additional exception
    class FormNotSignedException : public std::exception {
        const char* what() const throw() override {
            return "Form is not signed!";
        }
    };
    
    // Previous exceptions...
};
```

**Template Method Pattern**: Base class defines algorithm structure (`execute`), derived classes provide specific steps (`executeAction`).

#### Concrete Form: ShrubberyCreationForm:
```cpp
class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
    
public:
    ShrubberyCreationForm(const std::string& target)
        : AForm("Shrubbery Creation", 145, 137), _target(target) {}
    
    void executeAction() const override {
        std::ofstream file(_target + "_shrubbery");
        if (!file)
            throw std::runtime_error("Cannot create file");
        
        // Draw ASCII tree
        file << "       /\\      " << std::endl;
        file << "      /  \\     " << std::endl;
        file << "     /    \\    " << std::endl;
        file << "    /______\\   " << std::endl;
        file << "       ||      " << std::endl;
        file << "       ||      " << std::endl;
        
        file.close();
    }
};
```

#### RobotomyRequestForm (Random Behavior):
```cpp
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
    
public:
    RobotomyRequestForm(const std::string& target)
        : AForm("Robotomy Request", 72, 45), _target(target) {
        std::srand(std::time(nullptr));  // Seed random
    }
    
    void executeAction() const override {
        std::cout << "* drilling noises *" << std::endl;
        
        if (std::rand() % 2 == 0) {
            std::cout << _target << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy on " << _target << " failed!" << std::endl;
        }
    }
};
```

#### PresidentialPardonForm:
```cpp
class PresidentialPardonForm : public AForm {
private:
    std::string _target;
    
public:
    PresidentialPardonForm(const std::string& target)
        : AForm("Presidential Pardon", 25, 5), _target(target) {}
    
    void executeAction() const override {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
};
```

#### Usage with Polymorphism:
```cpp
int main() {
    try {
        Bureaucrat president("President", 1);
        Bureaucrat intern("Intern", 150);
        
        AForm* forms[] = {
            new ShrubberyCreationForm("home"),
            new RobotomyRequestForm("criminal"),
            new PresidentialPardonForm("someone")
        };
        
        for (int i = 0; i < 3; i++) {
            president.signForm(*forms[i]);
            president.executeForm(*forms[i]);  // Polymorphic execution
            delete forms[i];
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

### Exercise 03: Intern (Factory Pattern)
**Concept**: Dynamic form creation without knowing exact type

#### Intern Class:
```cpp
class Intern {
public:
    Intern() {}
    ~Intern() {}
    
    AForm* makeForm(const std::string& formName, const std::string& target);
    
    class FormNotFoundException : public std::exception {
        const char* what() const throw() override {
            return "Form type not found!";
        }
    };
};
```

#### Factory Implementation:
```cpp
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); },
        [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); },
        [](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }
    };
    
    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    
    throw FormNotFoundException();
}
```

**Alternative (simpler but more verbose)**:
```cpp
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    if (formName == "shrubbery creation") {
        std::cout << "Intern creates shrubbery creation" << std::endl;
        return new ShrubberyCreationForm(target);
    }
    if (formName == "robotomy request") {
        std::cout << "Intern creates robotomy request" << std::endl;
        return new RobotomyRequestForm(target);
    }
    if (formName == "presidential pardon") {
        std::cout << "Intern creates presidential pardon" << std::endl;
        return new PresidentialPardonForm(target);
    }
    
    throw FormNotFoundException();
}
```

#### Usage:
```cpp
int main() {
    Intern intern;
    AForm* form;
    
    try {
        form = intern.makeForm("robotomy request", "Bender");
        
        Bureaucrat b("Bureaucrat", 1);
        b.signForm(*form);
        b.executeForm(*form);
        
        delete form;
        
        // Try invalid form
        form = intern.makeForm("invalid form", "target");  // Throws!
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

## Key Principles Demonstrated

1. **Separation of Concerns**: Exception handling separated from business logic
2. **Template Method Pattern**: Base class orchestrates, derived classes specialize
3. **Factory Pattern**: Centralized object creation hides concrete types
4. **Exception Hierarchies**: Catch specific or general exceptions as needed
5. **RAII**: Automatic cleanup even during exceptional conditions

## Technical Challenges & Solutions

### Challenge 1: Exception Safety in Constructors
**Problem**: Constructor can't return error codes
**Solution**: Throw exceptions before object fully constructed
```cpp
Object::Object() {
    if (invalid_condition)
        throw std::runtime_error("Construction failed");
    // If we reach here, object is valid
}
```

### Challenge 2: Memory Leaks with Exceptions
**Problem**: `new` before exception → leaked memory
**Solution**: Use RAII (smart pointers or local objects)
```cpp
// BAD:
AForm* form = intern.makeForm(...);
riskyOperation();  // If this throws, form leaks
delete form;

// GOOD (modern C++):
std::unique_ptr<AForm> form(intern.makeForm(...));
riskyOperation();  // form automatically deleted during stack unwinding
```

### Challenge 3: Catching Right Exception Type
**Problem**: Catching by value slices derived exception info
**Solution**: Always catch by const reference
```cpp
try {
    // ...
} catch (const std::exception& e) {  // ✅ Reference preserves derived type
    std::cerr << e.what() << std::endl;
}
```

## Lessons Learned

### Exception Handling Philosophy
- **Exceptions for Exceptional Cases**: Not normal control flow
- **Let Exceptions Propagate**: Don't catch unless you can handle meaningfully
- **Catch Specific First**: Order catch blocks from specific to general
- **Document What Throws**: Function signatures should indicate possible exceptions

### Design Patterns
- **Template Method**: Reusable algorithm with customizable steps
- **Factory Method**: Object creation without specifying exact class
- **Strategy Pattern** (implicit): Different forms = different execution strategies

### Modern C++ Considerations
- **noexcept**: Preferred over `throw()` in C++11+
- **Smart Pointers**: `std::unique_ptr`, `std::shared_ptr` for exception safety
- **Move Semantics**: Efficient exception propagation without copies

## Practical Applications

- **File I/O**: Throw on file open failure
- **Network Programming**: Exception on connection loss
- **Parsing**: Exception on syntax errors
- **Resource Allocation**: Exception if allocation fails
- **Validation**: Exception for constraint violations

## Common Pitfalls

1. **Throwing by Pointer**: Don't `throw new Exception()` (memory leak risk)
2. **Catching by Value**: Slices derived class information
3. **Empty Catch Blocks**: Silently swallowing errors is dangerous
4. **Exceptions in Destructors**: Can cause `std::terminate()` (mark `noexcept`)
5. **Forgetting Cleanup**: Use RAII instead of manual cleanup

## Performance Considerations

- **Zero-Cost Abstraction**: If no exception thrown, negligible overhead
- **Throwing is Expensive**: Stack unwinding involves destructor calls
- **Don't Use for Flow Control**: Exceptions are for errors, not logic branching

---

*Exception handling is essential for robust C++ programs. While modern C++ introduces additional tools (std::optional, std::expected), exceptions remain the primary mechanism for constructor errors and deep call stacks. The patterns in this module—nested exceptions, template methods, and factories—form the foundation of professional C++ error handling.*
