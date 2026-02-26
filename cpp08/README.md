# CPP Module 08: Templated Containers, Iterators, Algorithms

## Overview

This module explores the **Standard Template Library (STL)**, C++'s powerful collection of containers, algorithms, and iterators. It demonstrates how generic programming principles (templates from cpp07) combine with data structures to create reusable, efficient code. The module emphasizes understanding STL internals and extending standard containers.

## Core Concepts Explored

### 1. **STL Containers**
Pre-built, template-based data structures:

**Sequence Containers**:
- `std::vector<T>`: Dynamic array (contiguous memory)
- `std::deque<T>`: Double-ended queue
- `std::list<T>`: Doubly-linked list
- `std::forward_list<T>`: Singly-linked list
- `std::array<T, N>`: Fixed-size array (C++11)

**Associative Containers**:
- `std::set<T>`: Sorted unique elements (Red-Black Tree)
- `std::map<K, V>`: Sorted key-value pairs
- `std::multiset<T>`, `std::multimap<K, V>`: Allow duplicates

**Unordered Containers (C++11)**:
- `std::unordered_set<T>`: Hash set
- `std::unordered_map<K, V>`: Hash map

**Container Adapters**:
- `std::stack<T>`: LIFO adapter (default: `deque`)
- `std::queue<T>`: FIFO adapter
- `std::priority_queue<T>`: Heap-based priority queue

### 2. **Iterators**
Generalized pointers for traversing containers:

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Iterator types:
std::vector<int>::iterator it = vec.begin();
std::vector<int>::const_iterator cit = vec.cbegin();
std::vector<int>::reverse_iterator rit = vec.rbegin();

// Iteration:
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";  // Dereference like pointer
}
```

**Iterator Categories**:
1. **Input Iterator**: Read-only, single-pass (e.g., `std::istream_iterator`)
2. **Output Iterator**: Write-only, single-pass (e.g., `std::ostream_iterator`)
3. **Forward Iterator**: Read/write, multi-pass (e.g., `std::forward_list::iterator`)
4. **Bidirectional Iterator**: Forward + backward (e.g., `std::list::iterator`)
5. **Random Access Iterator**: Jump to any position (e.g., `std::vector::iterator`)

### 3. **STL Algorithms**
Generic functions operating on iterator ranges:

```cpp
#include <algorithm>

std::vector<int> vec = {5, 2, 8, 1, 9};

// Find element:
auto it = std::find(vec.begin(), vec.end(), 8);

// Sort container:
std::sort(vec.begin(), vec.end());

// Count occurrences:
int count = std::count(vec.begin(), vec.end(), 5);

// Transform elements:
std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });
```

**Common Algorithm Categories**:
- **Non-modifying**: `find`, `count`, `equal`, `search`
- **Modifying**: `copy`, `fill`, `replace`, `transform`
- **Sorting**: `sort`, `stable_sort`, `partial_sort`
- **Set Operations**: `set_union`, `set_intersection`, `merge`
- **Numeric**: `accumulate`, `inner_product`, `partial_sum`

### 4. **Function Objects (Functors)**
Objects that can be called like functions:

```cpp
struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {}
    
    int operator()(int x) const {
        return x * factor;
    }
};

std::vector<int> vec = {1, 2, 3, 4, 5};
std::transform(vec.begin(), vec.end(), vec.begin(), Multiplier(10));
// Result: {10, 20, 30, 40, 50}
```

## Problem-Solving Architecture

### Exercise 00: easyfind (Generic Search in Containers)
**Concept**: Template function to find value in any STL container

#### Challenge:
Write a function that searches for an integer in any container (vector, list, deque, etc.).

#### Implementation:
```cpp
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    return it;
}
```

**Key Elements**:
1. **`typename T::iterator`**: Type depends on template parameter
   - `typename` keyword required (tells compiler it's a type, not a static member)
2. **`std::find`**: Generic algorithm from `<algorithm>`
3. **Exception on Failure**: Throws if value not found

**Alternative (Const Version)**:
```cpp
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found");
    
    return it;
}
```

#### Usage Examples:

**With std::vector**:
```cpp
int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;  // Found: 3
        std::cout << "Position: " << std::distance(vec.begin(), it) << std::endl;  // Position: 2
        
        easyfind(vec, 99);  // Throws exception
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

**With std::list**:
```cpp
int main() {
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```

**With std::deque**:
```cpp
int main() {
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
        deq.push_back(i);
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 7);
        std::cout << "Found at position: " << (it - deq.begin()) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```

### Exercise 01: Span (Range with Min/Max/Add)
**Concept**: Container wrapper managing a range of numbers with constraints

#### Class Design:
```cpp
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    
public:
    Span(unsigned int N) : _maxSize(N) {}
    
    void addNumber(int number) {
        if (_numbers.size() >= _maxSize)
            throw std::runtime_error("Span is full");
        _numbers.push_back(number);
    }
    
    int shortestSpan() const {
        if (_numbers.size() < 2)
            throw std::runtime_error("Not enough elements");
        
        std::vector<int> sorted = _numbers;
        std::sort(sorted.begin(), sorted.end());
        
        int minSpan = INT_MAX;
        for (size_t i = 1; i < sorted.size(); i++) {
            int span = sorted[i] - sorted[i - 1];
            if (span < minSpan)
                minSpan = span;
        }
        return minSpan;
    }
    
    int longestSpan() const {
        if (_numbers.size() < 2)
            throw std::runtime_error("Not enough elements");
        
        int min = *std::min_element(_numbers.begin(), _numbers.end());
        int max = *std::max_element(_numbers.begin(), _numbers.end());
        
        return max - min;
    }
    
    // Add range of numbers at once:
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
            throw std::runtime_error("Range too large");
        
        _numbers.insert(_numbers.end(), begin, end);
    }
};
```

**Key Algorithms Used**:
- `std::sort`: O(N log N) sorting
- `std::min_element`: O(N) minimum search
- `std::max_element`: O(N) maximum search
- `std::distance`: Calculate iterator distance

#### Usage Examples:

**Basic Operations**:
```cpp
int main() {
    Span sp(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // 2 (11-9)
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // 14 (17-3)
    
    return 0;
}
```

**Range Addition**:
```cpp
int main() {
    Span sp(10000);
    
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(i);
    
    sp.addRange(numbers.begin(), numbers.end());  // Add all at once
    
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;  // 1
    std::cout << "Longest: " << sp.longestSpan() << std::endl;    // 9999
    
    return 0;
}
```

**Error Handling**:
```cpp
int main() {
    Span sp(3);
    
    try {
        sp.addNumber(1);
        sp.shortestSpan();  // ❌ Throws: not enough elements
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);  // ❌ Throws: span is full
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```

### Exercise 02: MutantStack (STL-Compatible Stack with Iterators)
**Concept**: Extend `std::stack` to support iteration

#### Problem:
`std::stack` doesn't provide iterators (by design—stacks should only access top). But what if we need to iterate for debugging/testing?

#### Solution Strategy:
**Inherit from std::stack and expose underlying container's iterators**:

```cpp
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Inherit constructors:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
    MutantStack& operator=(const MutantStack& copy) {
        std::stack<T>::operator=(copy);
        return *this;
    }
    ~MutantStack() {}
    
    // Expose underlying container's iterators:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    iterator begin() {
        return this->c.begin();  // 'c' is protected member of std::stack
    }
    
    iterator end() {
        return this->c.end();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    
    reverse_iterator rend() {
        return this->c.rend();
    }
    
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};
```

**Key Insight**: `std::stack` is a **container adapter** wrapping an underlying container (default: `std::deque`). The member `c` holds the actual data.

#### Usage Examples:

**Basic Operations**:
```cpp
int main() {
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;  // 17
    
    mstack.pop();  // Remove 17
    
    std::cout << "Size: " << mstack.size() << std::endl;  // 1
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Iterate (possible with MutantStack, impossible with std::stack):
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Stack contents: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    return 0;
}
```

**Comparison with std::list**:
```cpp
int main() {
    // Same operations with std::list:
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "Size: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    std::cout << "List contents: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Output should match MutantStack output
    
    return 0;
}
```

**Advanced: Algorithm Compatibility**:
```cpp
int main() {
    MutantStack<int> mstack;
    for (int i = 0; i < 10; i++)
        mstack.push(i);
    
    // Use STL algorithms:
    std::cout << "Sum: " << std::accumulate(mstack.begin(), mstack.end(), 0) << std::endl;
    
    std::cout << "Max: " << *std::max_element(mstack.begin(), mstack.end()) << std::endl;
    
    std::cout << "Count of 5: " << std::count(mstack.begin(), mstack.end(), 5) << std::endl;
    
    return 0;
}
```

**Reverse Iteration**:
```cpp
int main() {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    
    std::cout << "Forward: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";  // 1 2 3
    std::cout << std::endl;
    
    std::cout << "Reverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";  // 3 2 1
    std::cout << std::endl;
    
    return 0;
}
```

## Key Principles Demonstrated

1. **Separation of Algorithms and Data**: Algorithms work on any container via iterators
2. **Iterator Abstraction**: Uniform interface for traversing different containers
3. **Container Adapters**: Build specialized interfaces on top of general containers
4. **Template Composition**: Combine templates to create flexible, reusable code
5. **Exception Safety**: STL containers provide strong exception guarantees

## Technical Challenges & Solutions

### Challenge 1: Dependent Type Names
**Problem**: `T::iterator` is a dependent type (depends on template parameter)
**Solution**: Use `typename` keyword
```cpp
template <typename T>
typename T::iterator easyfind(...) {  // typename required
    ...
}
```

### Challenge 2: Accessing Protected Members
**Problem**: `std::stack::c` is protected
**Solution**: Inherit from `std::stack` to access protected member
```cpp
class MutantStack : public std::stack<T> {
    iterator begin() { return this->c.begin(); }  // 'c' accessible via inheritance
};
```

### Challenge 3: Template Member Function Instantiation
**Problem**: Compiler doesn't instantiate template member functions until used
**Solution**: Ensure all template function definitions are in headers
```cpp
// Span.hpp
template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    // Implementation must be in header
}
```

## Lessons Learned

### STL Philosophy
- **Generic Programming**: Algorithms + Containers + Iterators = Flexible, Reusable Code
- **Zero-Cost Abstraction**: Templates eliminate runtime overhead
- **Orthogonal Design**: Components work together without tight coupling
- **Range-Based Thinking**: Operations on [begin, end) ranges

### Container Selection
- **std::vector**: Default choice (contiguous, cache-friendly)
- **std::list**: Frequent insertions/deletions in middle
- **std::deque**: Efficient push/pop at both ends
- **std::set/map**: Need sorted, unique elements
- **std::unordered_set/map**: Fast lookup, don't need ordering

### Iterator Safety
- **Invalidation**: Modifying container may invalidate iterators
- **Range Checking**: Dereferencing `end()` is undefined behavior
- **Const-Correctness**: Use `const_iterator` for read-only access

## Practical Applications

- **Data Processing**: STL algorithms for filtering, transforming data
- **Game Development**: Entity management with custom containers
- **Financial Software**: Time-series analysis with span calculations
- **Algorithm Implementation**: Custom data structures with STL interface
- **Generic Libraries**: Write code that works with any STL container

## Common Pitfalls

1. **Iterator Invalidation**: Modifying container during iteration
2. **Off-By-One Errors**: Forgetting `end()` is one-past-last
3. **Dereferencing end()**: Undefined behavior
4. **Expensive Copies**: Forgetting to use references in range-based for loops
5. **Wrong Container Choice**: Using `std::list` when `std::vector` is better

## Performance Considerations

| Container | Insert (front) | Insert (back) | Insert (middle) | Random Access | Find |
|-----------|---------------|---------------|-----------------|---------------|------|
| `vector` | O(N) | O(1)* | O(N) | O(1) | O(N) |
| `deque` | O(1) | O(1) | O(N) | O(1) | O(N) |
| `list` | O(1) | O(1) | O(1) | O(N) | O(N) |
| `set` | - | - | O(log N) | - | O(log N) |
| `unordered_set` | - | - | O(1)* | - | O(1)* |

\* Amortized time (occasional reallocation)

---

*This module bridges template programming (cpp07) with real-world data structure usage. The STL is perhaps C++'s greatest strength—a comprehensive, efficient, well-tested library that demonstrates the power of generic programming. Understanding containers, iterators, and algorithms is essential for productive C++ development. Modern C++ enhancements (ranges in C++20) build upon these foundations, but the core concepts remain unchanged.*
