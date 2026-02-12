#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point const a;
	Point const b(10, 0);
	Point const c (5, 10);
	Point const point(1, 1);
	Point const point1(11, 0);
	Point const point2(0, 8);
	Point const point3(0.1, 0.1);
	Point const point4(1, 10);
	Point const point5(5, 7);


	if (bsp(a, b, c, point))
		std::cout << "Point is inside of triangle" << std::endl;
	else	
		std::cout << "Point is outside of triangle" << std::endl;
	
	if (bsp(a, b, c, point1))
		std::cout << "Point1 is inside of triangle" << std::endl;
	else	
		std::cout << "Point1 is outside of triangle" << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << "Point2 is inside of triangle" << std::endl;
	else	
		std::cout << "Point2 is outside of triangle" << std::endl;

	if (bsp(a, b, c, point3))
		std::cout << "Point3 is inside of triangle" << std::endl;
	else	
		std::cout << "Point3 is outside of triangle" << std::endl;

	if (bsp(a, b, c, point4))
		std::cout << "Point4 is inside of triangle" << std::endl;
	else	
		std::cout << "Point4 is outside of triangle" << std::endl;
	
	if (bsp(a, b, c, point5))
		std::cout << "Point5 is inside of triangle" << std::endl;
	else	
		std::cout << "Point5 is outside of triangle" << std::endl;

return 0;
}
