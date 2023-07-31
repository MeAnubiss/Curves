#include "Helix.h"

void Helix::setter(int x_c, int y_c, int z_c, int rad, int stp)
{
	x = x_c;
	y = y_c;
	z = z_c;
	r = rad;
	step = stp;
}
string Helix::get_type()
{
	return name;
}
point Helix::get_point(double t)
{
	point ex_point;
	ex_point.x = x + r * cos(t);
	ex_point.y = y + r * sin(t);
	ex_point.z = z + ((step / (2 * M_PI)) * t);
	return ex_point;
}
threed_vector Helix::get_vector(double t)
{
	threed_vector ex_vector;
	ex_vector.dx = -r * sin(t);
	ex_vector.dy = r * cos(t);
	ex_vector.dz = step / (2 * M_PI);
	return ex_vector;
}
par Helix::get_par()
{
	par ex_par;
	ex_par.x = x;
	ex_par.y = y;
	ex_par.z = z;
	ex_par.r1 = r;
	ex_par.step = step;
	return ex_par;
}
