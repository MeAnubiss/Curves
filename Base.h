#pragma once
using namespace std;

struct par                    // все возможные параметры объектов
{
	int x = 0;
	int y = 0;
	int z = 0;
	int r1 = 0;
	int r2 = 0;
	int step = 0;
};
struct point                    
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};
struct threed_vector 
{
	double dx = 0.0;
	double dy = 0.0;
	double dz = 0.0;
};
class Base
{
public:
	
	virtual void setter(){}
	virtual string get_type() { return "0"; }
	virtual point get_point(double t) 
	{
		point ex_point;
		return ex_point;
	}
	virtual threed_vector get_vector(double t)
	{
		threed_vector ex_vector;
		return ex_vector;
	}
	virtual par get_par()
	{
		par ex_par;
		return ex_par;
	}
};
