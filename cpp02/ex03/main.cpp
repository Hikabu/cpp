#include "Fixed.hpp"
#include "Point.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_EMPTY "\x1b[0m"

 bool bsp( Point const a, Point const b, Point const c, Point const point);

 int main(){
	Point a(-2, -2), b(0, 2), c(5, 0);
	Point p(0, 0);

	// inside triangle

	if (bsp(a, b, c, p))
		std::cout << COLOR_GREEN "Point" << p << " is inside the triangle with vertexes: " << 
					a << b << c << COLOR_EMPTY << std::endl;
	else
		std::cout << COLOR_RED "Point" << p << " noo, it is not in triangle with vertexes:" <<
					a << b << c << COLOR_EMPTY << std::endl;

	//on vertex
	p.setX(-1);
	p.setY(0);

	if (bsp(a, b, c, p))
		std::cout << COLOR_GREEN "Point" << p << " is inside the triangle with vertexes: " << 
					a << b << c << COLOR_EMPTY << std::endl;
	else
		std::cout << COLOR_RED "Point" << p << " noo, it is not in triangle with vertexes:" <<
					a << b << c << COLOR_EMPTY << std::endl;

	//inside 
	p.setX(0);
	p.setY(-1);

	if (bsp(a, b, c, p))
		std::cout << COLOR_GREEN "Point" << p << " is inside the triangle with vertexes: " << 
					a << b << c << COLOR_EMPTY << std::endl;
	else
		std::cout << COLOR_RED "Point" << p << " noo, it is not in triangle with vertexes:" <<
					a << b << c << COLOR_EMPTY << std::endl;

	//outside triangle

	p.setX(10);
	p.setY(10);

	if (bsp(a, b, c, p))
		std::cout << COLOR_GREEN "Point" << p << " is inside the triangle with vertexes: " << 
					a << b << c << COLOR_EMPTY << std::endl;
	else
		std::cout << COLOR_RED "Point" << p << " noo, it is not in triangle with vertexes:" <<
					a << b << c << COLOR_EMPTY << std::endl;
	//on edge 

	p.setX(0);
	p.setY(2);

	if (bsp(a, b, c, p))
		std::cout << COLOR_GREEN "Point" << p << " is inside the triangle with vertexes: " << 
					a << b << c << COLOR_EMPTY << std::endl;
	else
		std::cout << COLOR_RED "Point" << p << " noo, it is not in triangle with vertexes:" <<
					a << b << c << COLOR_EMPTY << std::endl;

 }