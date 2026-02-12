#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (sameSide(a, b, point, c)
		&& sameSide(b, c, point, a)
		&& sameSide(c, a, point, b))
		return true;
	else
		return false;
}

bool sameSide(Point const a, Point const b, Point const point, Point const c)
{
	Fixed dx = b.getX() - a.getX();
	Fixed dy = b.getY() - a.getY();

	Fixed dx1 = point.getX() - a.getX();
	Fixed dy1 = point.getY() - a.getY();

	Fixed dx2 = c.getX() - a.getX();
	Fixed dy2 = c.getY() - a.getY();

	Fixed cross1 = (dx * dy1) - (dy * dx1);
	Fixed cross2 = (dx * dy2) - (dy * dx2);

	if ((cross1 * cross2) > 0)
		return true;
	else
		return false;
}