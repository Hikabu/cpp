#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"
class Point{
    private:

        Fixed _x; //nested class
        Fixed _y;
    public:
        Point();
        Point(const float &first, const float &second);
        Point (const Point &point);
        const Point &operator=(const Point &point);
        ~Point();
    
    const	Fixed &getX() const;
	const	Fixed &getY() const;

	void	setX(const Fixed &value);
	void	setY(const Fixed &value);

};
	std::ostream& operator<<(std::ostream &out, const Point &point);

#endif




//  Unlike pointers, references cannot be null.
//  They must be initialized when they are declared.