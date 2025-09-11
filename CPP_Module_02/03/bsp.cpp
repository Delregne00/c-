#include "Point.hpp"
#include <cmath>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_one = point.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - point.getY()) +
					c.getX() * (point.getY() - b.getY());

	Fixed area_two = a.getX() * (point.getY() - c.getY()) +
					point.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - point.getY());

	Fixed area_three = a.getX() * (b.getY() - point.getY()) +
					b.getX() * (point.getY() - a.getY()) +
					point.getX() * (a.getY() - b.getY());

	return (area_one > 0  && area_two > 0 && area_three > 0)
		|| (area_one  < 0 && area_two < 0 && area_three < 0);
}
