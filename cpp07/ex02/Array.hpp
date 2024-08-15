#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T> 

class Array 
{
	private:
		T *fillOut;
		unsigned int _size;
		unsigned int n;

	public:
		// CONSTRUCTING
		Array() : fillOut(NULL), _size(0), n(0) {};
		Array(unsigned int n) : _size(n)
		{
			if (_size < 0)
				throw(OutOfBounds());
			this->n = n;
			if (n == 0)
				fillOut = NULL;
			else
				fillOut = new T[n];
		};

		Array(const Array &copy)
		{
			this->fillOut = new T[copy.n];
			n = copy.n;
			_size = copy._size;
			for (unsigned int i = 0; i < n; i++)
				fillOut[i] = copy.fillOut[i];
		};

		Array &operator=(const Array &copy)
		{
			if (this != copy)
			{
				delete [] fillOut;
				_size = copy._size;
				fillOut = copy.fillOut;
				n = copy.n;
				for (unsigned int i = 0; i < _size; i++)
					fillOut[i] = copy.fillOut[i];
			}
			return (*this);
		}

		~Array()
		{
			if (fillOut)
				delete[] fillOut;
		};

		// FUNCTIONS

		int size()
		{
			return (n);
		}

		class OutOfBounds : public std::exception
		{
		public:
			const char *what() const throw()
			{
				return ("Index out of bounds");
			}
		};

		T &operator[](unsigned int idx)
		{
			if (idx >= n || idx < 0 || fillOut == NULL)
				throw(OutOfBounds());
			return (fillOut[idx]);
		}

		const T &operator[](unsigned int idx) const
		{
			if (idx >= n || idx < 0 || fillOut == NULL)
				throw(OutOfBounds());
			return (fillOut[idx]);
		}
};

#endif
