#include "Fixed.hpp"
#include "Point.hpp"
//defoult constructor 
Point::Point() : _x(0), _y(0){}

//Constructor for init
Point::Point(const float &x, const float &y) : _x(x), _y(y){};

//copy constructor
Point::Point(const Point &point) { *this = point;}

//copy assignment
const Point &Point::operator=(const Point &point){
	if (this == &point) //compare addreses
		return (*this); // for chaining of assignments(=should support)
	_x = point.getX();
	_y = point.getY();
	return (*this); 
}

//destructor 
Point::~Point(){}

//get/set

const Fixed& Point::getX() const	{return _x;}
const Fixed& Point::getY() const	{return _y;}

void Point::setX(const Fixed &value) {_x = value;}
void Point::setY(const Fixed &value) {_y = value;}

std::ostream& operator << (std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << "," << point.getY() << ")";
	return out;
}