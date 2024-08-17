#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

//copying

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_fillOut; //we lost info about arr.size

	public:
		Array () : _size(0){};
		Array (unsigned int n);
		Array (const Array &copy);
		Array &operator=(const Array &copy);
		~Array();

		//finctions
		unsigned int size() const 
		{
			return (_size);
		}

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index is out of bounds\n");
				}
		};

		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
};

# include "Array.tpp"
#endif
