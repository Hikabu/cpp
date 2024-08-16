template <typename T>
Array<T>::Array (unsigned int n) : _size(n) 
{
    if (_size < 0)
        throw OutOfBounds();
    if (_size == 0)
        _fillOut = (NULL);
    else
        _fillOut = new T[n];
}

template <typename T>
Array<T>::Array (const Array &copy) : _size( copy._size), _fillOut(new T[copy._size])
{
    for (unsigned int i = 0; i < _size; i++)
        _fillOut[i] = copy._fillOut[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete [] _fillOut;
        _size = copy._size;
        _fillOut = copy._fillOut;
        for (unsigned int i = 0; i < _size; i++)
            _fillOut[i] = copy._fillOut[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    if (_fillOut)
        delete [] _fillOut;
}


template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size || i < 0 || _fillOut == NULL)
        throw OutOfBounds();
    return (_fillOut[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size || i < 0 || _fillOut == NULL)
        throw OutOfBounds();
    return (_fillOut[i]);
}
