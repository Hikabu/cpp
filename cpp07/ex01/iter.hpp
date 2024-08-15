#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template <typename T>

void print(T &x)
{
    std::cout << x << ' ';
}

template <typename T>
void add(T &x)
{
    x +=1;
}

template <typename T>
void iter(T* array, size_t len, void(*f)(T&)){
    for (size_t i = 0; i < len; ++i)
    {
        f(array[i]);
    }
}

#endif
