#pragma once
#include "Base.h"
#define _USE_MATH_DEFINES 
#include <cmath>

class Circle:public Base
{
private:
	int x = 0;
	int y = 0;
	int r = 0;
	string name = "circle";
public:
	void setter(int, int, int);
	string get_type();
	point get_point(double);
	threed_vector get_vector(double);
	par get_par();
};

