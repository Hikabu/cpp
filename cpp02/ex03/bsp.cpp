#include "Fixed.hpp"
#include "Point.hpp"

//by concept of half-polygon 

Fixed dotProduct(const Point &a, const Point &b, const Point &p)
{
    return (a.getX() - p.getX()) * (b.getY() - a.getY()) -
        ((b.getX() - a.getX()) * (a.getY() - p.getY()));
}

 bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed const fixedZero;

    Fixed ab(dotProduct(a, b, point));
    Fixed bc(dotProduct(b, c, point));
    Fixed ca(dotProduct(c, a, point));

    if (((ab > fixedZero) && (bc > fixedZero) && (ca > fixedZero)) ||
        ((ab < fixedZero) && (bc < fixedZero) && (ca < fixedZero))) // pos neg right left
            return true;
        return false;
}
 
