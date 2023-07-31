#pragma once
#include "Base.h"
#define _USE_MATH_DEFINES 
#include <cmath>

class Ellipse :public Base
{
private:
	int x = 0;
	int y = 0;
	int r1 = 0;
	int r2 = 0;
	string name = "ellipse";
public:
	void setter(int, int, int, int);
	string get_type();
	point get_point(double);
	threed_vector get_vector(double);
	par get_par();
};