#pragma once
#include "Base.h"
#define _USE_MATH_DEFINES 
#include <cmath>
# define M_PI  3.14159265358979323846 

class Helix :public Base
{
private:
	int x = 0;
	int y = 0;
	int z = 0;
	int r = 0;
	int step = 0;
	string name = "helix";
public:
	void setter(int, int, int, int, int);
	string get_type();
	point get_point(double);
	threed_vector get_vector(double);
	par get_par();
};