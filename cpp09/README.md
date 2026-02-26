# CPP Module 09: STL Advanced Containers & Algorithms

## Overview

This module represents the culmination of the C++ journey, exploring **advanced STL usage**, **algorithmic complexity**, and **real-world problem-solving** with containers. It demonstrates practical applications: financial data processing, mathematical expression evaluation, and high-performance sorting algorithms. The emphasis is on choosing appropriate data structures and analyzing algorithmic efficiency.

## Core Concepts Explored

### 1. **std::map (Associative Container)**
Ordered key-value pairs implemented as Red-Black Tree:

```cpp
#include <map>

std::map<std::string, int> ages;
ages["Alice"] = 30;
ages["Bob"] = 25;

// Ordered iteration (sorted by key):
for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```

**Characteristics**:
- **Sorted**: Keys automatically ordered (default: `operator<`)
- **Unique Keys**: Each key appears once
- **Logarithmic Operations**: Insert/Find/Delete in O(log N)
- **Bidirectional Iterators**: Forward and backward traversal

**When to Use**:
- Need sorted key access
- Frequent lookups by key
- Range queries (lower_bound, upper_bound)

### 2. **std::stack (LIFO Container Adapter)**
Last-In-First-Out structure:

```cpp
#include <stack>

std::stack<int> s;
s.push(10);
s.push(20);
s.push(30);

std::cout << s.top() << std::endl;  // 30
s.pop();
std::cout << s.top() << std::endl;  // 20
```

**Use Cases**:
- Expression evaluation (postfix, prefix)
- Function call stack simulation
- Undo/redo functionality
- Depth-first search (DFS)

### 3. **std::deque (Double-Ended Queue)**
Efficient insertion/deletion at both ends:

```cpp
#include <deque>

std::deque<int> dq;
dq.push_back(1);   // Add to back
dq.push_front(2);  // Add to front
dq.pop_back();     // Remove from back
dq.pop_front();    // Remove from front
```

**Characteristics**:
- **Random Access**: O(1) indexing like vector
- **Efficient Ends**: O(1) push/pop at both ends
- **Non-Contiguous Memory**: Implemented as array of arrays
- **No Reallocation**: Unlike vector, doesn't move elements

**When to Use**:
- Need both stack and queue operations
- Sliding window algorithms
- BFS (Breadth-First Search)

### 4. **Merge-Insert Sort (Ford-Johnson Algorithm)**
Hybrid sorting algorithm minimizing comparisons:

**Algorithm Overview**:
1. **Pairing**: Group elements into pairs
2. **Sorting Pairs**: Sort within each pair (larger first)
3. **Recursive Sort**: Recursively sort larger elements
4. **Binary Insertion**: Insert smaller elements using binary search

**Complexity**:
- **Comparisons**: ≈ N log N (fewer than standard merge sort)
- **Time**: O(N log N)
- **Space**: O(N)

**Advantage**: Minimizes comparison count (important for expensive comparisons).

## Problem-Solving Architecture

### Exercise 00: Bitcoin Exchange (CSV Parsing & Data Lookup)
**Concept**: Parse historical Bitcoin prices and calculate portfolio values

#### Problem Statement:
Given:
1. **Database**: `data.csv` with `date,exchange_rate` pairs
2. **Input**: File with `date | value` (BTC amount owned on that date)

Calculate: Value in USD for each date using closest earlier exchange rate.

#### Data Structure Choice: `std::map<date, rate>`
**Why map?**
- Automatic sorting by date
- `lower_bound()` finds closest earlier date efficiently (O(log N))
- Easy iteration in chronological order

#### Implementation Strategy:

**Date Validation**:
```cpp
bool Bitcoin::checkDate(std::string& date) {
    // Format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2022)  // Bitcoin started 2009
        return false;
    if (month < 1 || month > 12)
        return false;
    
    // Days per month (simplified, ignoring leap years):
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    
    // Leap year check for February:
    if (month == 2 && day == 29) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        return false;
    }
    
    return true;
}
```

**Value Validation**:
```cpp
bool Bitcoin::checkValue(std::string& value) {
    float val = std::strtof(value.c_str(), nullptr);
    
    if (val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}
```

**Database Loading**:
```cpp
std::map<std::string, float> loadDatabase(const std::string& filename) {
    std::map<std::string, float> database;
    std::ifstream file(filename);
    
    if (!file.is_open())
        throw std::runtime_error("Could not open database file");
    
    std::string line;
    std::getline(file, line);  // Skip header
    
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        float rate = std::strtof(rateStr.c_str(), nullptr);
        
        database[date] = rate;
    }
    
    file.close();
    return database;
}
```

**Processing Input**:
```cpp
void processInput(const std::string& inputFile, std::map<std::string, float>& db) {
    std::ifstream file(inputFile);
    if (!file.is_open())
        throw std::runtime_error("Could not open input file");
    
    std::string line;
    std::getline(file, line);  // Skip header
    
    while (std::getline(file, line)) {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos - 1);  // Trim spaces
        std::string valueStr = line.substr(pipePos + 2);
        
        // Validate:
        if (!checkDate(date)) {
            std::cerr << "Error: invalid date => " << date << std::endl;
            continue;
        }
        if (!checkValue(valueStr))
            continue;
        
        float btcAmount = std::strtof(valueStr.c_str(), nullptr);
        
        // Find closest earlier or equal date:
        std::map<std::string, float>::iterator it = db.lower_bound(date);
        if (it == db.end() || it->first != date) {
            if (it == db.begin()) {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue;
            }
            --it;  // Get previous entry
        }
        
        float rate = it->second;
        float value = btcAmount * rate;
        
        std::cout << date << " => " << btcAmount << " = " << value << std::endl;
    }
    
    file.close();
}
```

#### Example:
**data.csv**:
```
date,exchange_rate
2009-01-02,0.15
2011-01-01,0.3
2012-01-01,5.2
2013-01-01,13.5
```

**input.txt**:
```
date | value
2011-06-15 | 0.5
2012-03-01 | 1.2
2013-01-01 | 2.0
2008-01-01 | 1.0
```

**Output**:
```
2011-06-15 => 0.5 = 0.15
2012-03-01 => 1.2 = 6.24
2013-01-01 => 2.0 = 27.0
Error: date too early => 2008-01-01
```

### Exercise 01: RPN Calculator (Reverse Polish Notation)
**Concept**: Evaluate mathematical expressions in postfix notation

#### RPN Background:
**Infix**: `3 + 4 * 2` (ambiguous without parentheses/precedence)  
**RPN**: `3 4 2 * +` (no ambiguity, no parentheses needed)

**Evaluation Algorithm**:
1. Scan left to right
2. If **operand**: Push to stack
3. If **operator**: Pop two operands, apply operator, push result
4. Final stack has one value: the result

#### Implementation:
```cpp
class RPN {
private:
    std::stack<double> _stack;
    
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    double applyOperator(double a, double b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        }
        throw std::runtime_error("Error: invalid operator");
    }
    
public:
    double evaluate(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        
        while (iss >> token) {
            if (isOperator(token)) {
                if (_stack.size() < 2)
                    throw std::runtime_error("Error: insufficient operands");
                
                double b = _stack.top(); _stack.pop();
                double a = _stack.top(); _stack.pop();
                
                double result = applyOperator(a, b, token);
                _stack.push(result);
            }
            else {
                // Parse number:
                char* end;
                double num = std::strtod(token.c_str(), &end);
                
                if (*end != '\0')  // Not a valid number
                    throw std::runtime_error("Error: invalid token => " + token);
                
                _stack.push(num);
            }
        }
        
        if (_stack.size() != 1)
            throw std::runtime_error("Error: invalid expression");
        
        return _stack.top();
    }
};
```

#### Usage Examples:

**Basic Arithmetic**:
```cpp
int main() {
    RPN calculator;
    
    try {
        std::cout << calculator.evaluate("3 4 +") << std::endl;       // 7
        std::cout << calculator.evaluate("5 1 2 + 4 * + 3 -") << std::endl;  // 14
        std::cout << calculator.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +") << std::endl;  // 42
        
        std::cout << calculator.evaluate("7 7 * 7 -") << std::endl;   // 42
        std::cout << calculator.evaluate("1 2 * 2 / 2 * 2 4 - +") << std::endl;  // 0
        
        // Error cases:
        calculator.evaluate("1 2 * 2 /");  // Not enough results
        calculator.evaluate("1 +");        // Not enough operands
        calculator.evaluate("1 2 3 +");    // Too many results
        calculator.evaluate("1 a +");      // Invalid token
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```

**Step-by-Step Evaluation**:
```
Expression: "3 4 2 * 1 5 - + *"

Token | Action           | Stack
------|------------------|-------------
3     | Push 3           | [3]
4     | Push 4           | [3, 4]
2     | Push 2           | [3, 4, 2]
*     | Pop 2,4 → 8      | [3, 8]
1     | Push 1           | [3, 8, 1]
5     | Push 5           | [3, 8, 1, 5]
-     | Pop 5,1 → -4     | [3, 8, -4]
+     | Pop -4,8 → 4     | [3, 4]
*     | Pop 4,3 → 12     | [12]

Result: 12
```

### Exercise 02: PmergeMe (Merge-Insert Sort with Containers)
**Concept**: Implement Ford-Johnson algorithm with both vector and deque, compare performance

#### Algorithm Implementation (Simplified):

**Vector Version**:
```cpp
class PmergeMe {
private:
    std::vector<int> _vec;
    clock_t _vecTime;
    
    void mergeSortInsert(std::vector<int>& arr) {
        if (arr.size() <= 1)
            return;
        
        // Pair and sort:
        std::vector<std::pair<int, int>> pairs;
        for (size_t i = 0; i + 1 < arr.size(); i += 2) {
            if (arr[i] > arr[i + 1])
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            else
                pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
        
        // Extract larger elements:
        std::vector<int> main;
        for (size_t i = 0; i < pairs.size(); i++)
            main.push_back(pairs[i].first);
        
        // Recursively sort main:
        mergeSortInsert(main);
        
        // Binary insert smaller elements:
        for (size_t i = 0; i < pairs.size(); i++) {
            std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pairs[i].second);
            main.insert(pos, pairs[i].second);
        }
        
        // Handle odd element:
        if (arr.size() % 2 == 1) {
            std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), arr.back());
            main.insert(pos, arr.back());
        }
        
        arr = main;
    }
    
public:
    void sort(int argc, char** argv) {
        // Load data:
        for (int i = 1; i < argc; i++) {
            int num = std::atoi(argv[i]);
            if (num < 0)
                throw std::runtime_error("Error: negative number");
            _vec.push_back(num);
        }
        
        std::cout << "Before: ";
        for (size_t i = 0; i < _vec.size(); i++)
            std::cout << _vec[i] << " ";
        std::cout << std::endl;
        
        // Sort with timing:
        clock_t start = clock();
        mergeSortInsert(_vec);
        _vecTime = clock() - start;
        
        std::cout << "After:  ";
        for (size_t i = 0; i < _vec.size(); i++)
            std::cout << _vec[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Time to process with std::vector: " 
                  << (double)_vecTime / CLOCKS_PER_SEC * 1000000 << " μs" << std::endl;
    }
};
```

**Deque Version**: (Nearly identical, replace `std::vector` with `std::deque`)

#### Performance Comparison:
```cpp
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
        return 1;
    }
    
    try {
        PmergeMe sorter;
        sorter.sortVector(argc, argv);
        sorter.sortDeque(argc, argv);
        
        // Compare times:
        std::cout << "\nPerformance comparison:" << std::endl;
        std::cout << "Vector: " << sorter.getVectorTime() << " μs" << std::endl;
        std::cout << "Deque:  " << sorter.getDequeTime() << " μs" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

#### Example Output:
```bash
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process with std::vector: 42 μs
Time to process with std::deque:  48 μs
```

**Why Different Times?**
- **Vector**: Contiguous memory → better cache locality
- **Deque**: Segmented memory → more cache misses
- **Trade-off**: Deque better for insertions at ends, vector better for sorting

## Key Principles Demonstrated

1. **Data Structure Selection**: Choose container based on operation patterns
2. **Algorithmic Complexity**: Analyze time/space trade-offs
3. **Real-World Applications**: Financial data, expression parsing, sorting
4. **Performance Measurement**: Empirical timing comparisons
5. **Error Handling**: Robust input validation and graceful failure

## Technical Challenges & Solutions

### Challenge 1: Date Range Lookup in Map
**Problem**: Find exchange rate for date that may not exist in database
**Solution**: `lower_bound()` finds closest earlier date
```cpp
std::map<std::string, float>::iterator it = db.lower_bound(date);
if (it->first != date && it != db.begin())
    --it;  // Get previous date
```

### Challenge 2: RPN Stack Underflow
**Problem**: Expression like `"1 +"` has too few operands
**Solution**: Check stack size before popping
```cpp
if (_stack.size() < 2)
    throw std::runtime_error("Insufficient operands");
```

### Challenge 3: Container Performance Comparison
**Problem**: Need precise timing for microsecond differences
**Solution**: Use `clock()` or `<chrono>` (C++11)
```cpp
#include <ctime>
clock_t start = clock();
// ... operation ...
clock_t elapsed = clock() - start;
double microseconds = (double)elapsed / CLOCKS_PER_SEC * 1000000;
```

## Lessons Learned

### Algorithm Design
- **Choose Right Structure**: Map for lookups, stack for LIFO, deque for both ends
- **Measure, Don't Assume**: Theoretical complexity ≠ real performance
- **Edge Cases Matter**: Empty input, single element, duplicates
- **Validate Early**: Check input before processing

### C++ STL Mastery
- **Associative Containers**: Sorted access with logarithmic operations
- **Adapters**: Stack/queue built on deque/vector
- **Algorithms**: `lower_bound`, `upper_bound` for range queries
- **Performance**: Cache locality matters more than Big-O sometimes

### Software Engineering
- **Separation of Concerns**: Parsing, validation, processing in separate functions
- **Error Messages**: Clear, actionable feedback for users
- **Testing**: Test edge cases, invalid input, performance benchmarks

## Practical Applications

- **Financial Analysis**: Time-series data lookup (stock prices, exchange rates)
- **Compilers**: Expression evaluation (RPN for intermediate representation)
- **Database Systems**: B-trees (similar to std::map) for indexing
- **Operating Systems**: Scheduling algorithms (priority queues)
- **Machine Learning**: Efficient data structures for large datasets

## Common Pitfalls

1. **Map Iterator Invalidation**: Erasing elements invalidates iterators
2. **Empty Stack Pop**: Always check size before `top()` or `pop()`
3. **Floating-Point Comparison**: Use epsilon for equality checks
4. **CSV Parsing**: Handle malformed data, extra whitespace
5. **Performance Measurement**: Don't include I/O in timing, use multiple runs

## Performance Considerations

### Container Overhead:
| Container | Memory Overhead | Cache Performance | Typical Use |
|-----------|----------------|-------------------|-------------|
| `std::vector` | Low (capacity + size) | Excellent (contiguous) | Default choice |
| `std::deque` | Medium (block pointers) | Good (mostly contiguous) | Queue/stack operations |
| `std::map` | High (tree nodes) | Poor (pointer chasing) | Sorted associative |
| `std::stack` | Same as underlying | Same as underlying | LIFO only |

### Algorithm Complexity:
- **Bitcoin Lookup**: O(log N) per query (map search)
- **RPN Evaluation**: O(N) where N = tokens (single stack pass)
- **Merge-Insert Sort**: O(N log N) time, O(N) space

---

*This module represents the culmination of C++ fundamentals: OOP, templates, STL, and algorithms converge to solve real-world problems. The exercises demonstrate that choosing the right data structure is as important as algorithmic efficiency. Understanding STL containers deeply—their strengths, weaknesses, and performance characteristics—is essential for writing production-quality C++ code. These patterns and techniques form the foundation for systems programming, game development, financial software, and high-performance computing.*
