#include "Circle.h"

void Circle::setter(int x_c, int y_c, int rad)
{
	x = x_c;
	y = y_c;
	r = rad;
}
string Circle::get_type()
{
	return name;
}
point Circle::get_point(double t)
{
	point ex_point;
	ex_point.x = x + r * cos(t);
	ex_point.y = y + r * sin(t);
	return ex_point;
}
threed_vector Circle::get_vector(double t)
{
	threed_vector ex_vector;
	ex_vector.dx = - r * sin(t);
	ex_vector.dy = r * cos(t);
	return ex_vector;
}
par Circle::get_par()
{
	par ex_par;
	ex_par.x = x;
	ex_par.y = y;
	ex_par.r1 = r;
	return ex_par;
}
