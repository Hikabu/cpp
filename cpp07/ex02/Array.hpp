#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T> 

class Array 
{
    private:
        T* Array;
        unsigned int _size;
        unsigned int n;

    public:
    //CONSTRUCTING 
    Array() : Array(NULL), _size(0), n(0) {};
    Array(unsigned int n) : _size(n)
    {
        if (_size < 0)
            throuw(OutOfBounds());
        this->n = n;
        if (n == 0)
            Array = NULL;
        else
            Array = new T[n];
    };

    Array(const Array &copy){
        this->Array = new T[copy.n];
        n = copy.n;
        size = copy._size;
        for (unsigned int i = 0; i < n; i++)
            Array[i] = copy.Array[i];
    };

    Array &operator=(const array &copy){
        if (this == &copy)
            return (*this);
        if (Array)
            delete[]Array;
        size = copy._size;
        this->Array = new T[n];
        for (unsigned int i = 0; i < n, i++;)
            Array[i] = copy.Array[i];
        return (*this);
    };

    ~Array()
    {
        if (Array)
            delete [] Array;
    };

    //FUNCTIONS

    int size()
    {
        return (n);
    }

    class OutOfBounds() : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Index out of bounds");
            }
    }
    

    T &opreator[](unsigned int idx)
    {
        if (idx >= n || idx < 0 || Array == NULL)
            throw (OutOfBounds());
        return (Array[idx]);
    }

    const T &operator[](unsigned int idx)const
    {
        if (idx >= n || idx < 0 || Array == NULL)
            throw (OutOfBounds());
        return (Array[idx]);
    }

};


#endif
