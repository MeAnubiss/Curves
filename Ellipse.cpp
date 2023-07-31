#include "Ellipse.h"

void Ellipse::setter(int x_c, int y_c, int rad1, int rad2)
{
	x = x_c;
	y = y_c;
	r1 = rad1;
	r2 = rad2;
}
string Ellipse::get_type()
{
	return name;
}
point Ellipse::get_point(double t)
{
	point ex_point;
	ex_point.x = x + r1 * cos(t);
	ex_point.y = y + r2 * sin(t);
	return ex_point;
}
threed_vector Ellipse::get_vector(double t)
{
	threed_vector ex_vector;
	ex_vector.dx = -r1 * sin(t);
	ex_vector.dy = r2 * cos(t);
	return ex_vector;
}
par Ellipse::get_par()
{
	par ex_par;
	ex_par.x = x;
	ex_par.y = y;
	ex_par.r1 = r1;
	ex_par.r2 = r2;
	return ex_par;
}