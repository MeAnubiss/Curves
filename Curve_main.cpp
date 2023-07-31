#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>
#define M_PI_4 0.785398163397448309616
#include <vector>
#include "Circle.h"
#include "Circle.cpp"
#include "Ellipse.h"
#include "Helix.h"
#include "Ellipse.cpp"
#include "Helix.cpp"
#include <algorithm>
using namespace std;
bool rad_sorting(Base* rd1, Base* rd2)
{
    if (rd1->get_par().r1 < rd2->get_par().r1)
    {
        return true;
    }
    else { return false; }
}

int main()
{
    srand(time(NULL));
    int x = 0, y = 0, z = 0, radius = 0;   // x,y,z - coordinates of the centre; radius - radius of a circle or a helix
    int r1 = 0, step = 0;          // r1, r2 - radii of an ellipse; step - step of a helix 
    int r2 = 0;
    Circle Circle_Arr[5];
    Ellipse Ellipse_Arr[2];
    Helix Helix_Arr[2];
    
    for (int i = 0; i < 5; i++)
    {
        x= rand() % 15;
        y = rand() % 15;
        while (radius == 0)
        {
            radius = rand() % 20;
        }     
        Circle_Arr[i].setter(x,y,radius);
        radius = 0;
    }
    x = 0; y = 0; 
    int j = 0;
    for (int i = 0; i < 2; i++)
    {
        x = rand() % 15;
        y = rand() % 15;
        while (r1 == 0)
        {
            r1 = rand() % 20;
        }
        
        while (j == 0)
        {
            j=rand() % 5;
        }
        r2 = r1 / j;
        Ellipse_Arr[i].setter(x, y, r1, r2);
        r1 = 0;  j = 0;
    }
    x = 0; y = 0;  r2 = 0;
    for (int i = 0; i < 2; i++)
    {
        x = rand() % 15;
        y = rand() % 15;
        z= rand() % 15;
        while (radius == 0)
        {
            radius = rand() % 10;
        }
        while (step == 0)
        {
            step = rand() % 10;
        }
        Helix_Arr[i].setter(x, y, z, radius, step);
        radius = 0;  step = 0;
    }
    x = 0; y = 0; z = 0; 

    vector<Base*>v;
    int choice = 0;
    int c_i = 0, e_i = 0, h_i = 0;
    while (true)
    {
        choice = rand() % 4;
        switch (choice)
        {
        case 0: 
            if (c_i < 5)
            {
                v.push_back(&Circle_Arr[c_i]);
                c_i++;
            }
            break;
        case 1:
            if (c_i < 5)
            {
                v.push_back(&Circle_Arr[c_i]);
                c_i++;
            }
            break;
        case 2:
            if (e_i < 2)
            {
                v.push_back(&Ellipse_Arr[e_i]);
                e_i++;
            }
            break;
        case 3:
            if (h_i < 2)
            {
                v.push_back(&Helix_Arr[h_i]);
                h_i++;
            }
            break;
        default:
            break;
        }
        if (v.size()==9){break;}
    }

    double t = M_PI_4;            // t=PI/4
    par param;
    point ex_point;
    threed_vector ex_vector;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->get_type() == "circle")
        {
            param = v[i]->get_par();
            ex_point = v[i]->get_point(t);
            ex_vector = v[i]->get_vector(t);
            cout << "Circle: "<< "x="<<param.x<< " y=" << param.y << " radius=" << param.r1 <<endl;
            cout << "  Point at Pi/4: " << "x=" << ex_point.x << " y=" << ex_point.y << endl;
            cout << "  3D Vector: " << "dx=" << ex_vector.dx << " dy=" << ex_vector.dx << " dz=" << ex_vector.dz<<endl;
            cout << endl;
        }
        if (v[i]->get_type() == "ellipse")
        {
            param = v[i]->get_par();
            ex_point = v[i]->get_point(t);
            ex_vector = v[i]->get_vector(t);
            cout << "Ellipse: " << "x=" << param.x << " y=" << param.y << " radius 1=" << param.r1 <<" radius 2=" << param.r2 << endl;
            cout << "  Point at Pi/4: " << "x=" << ex_point.x << " y=" << ex_point.y << endl;
            cout << "  3D Vector: " << "dx=" << ex_vector.dx << " dy=" << ex_vector.dx << " dz=" << ex_vector.dz << endl;
            cout << endl;
        }
        if (v[i]->get_type() == "helix")
        {
            param = v[i]->get_par();
            ex_point = v[i]->get_point(t);
            ex_vector = v[i]->get_vector(t);
            cout << "Helix: " << "x=" << param.x << " y=" << param.y << " z=" << param.z << " radius=" << param.r1 << " step=" << param.step<< endl;
            cout << "  Point at Pi/4: " << "x=" << ex_point.x << " y=" << ex_point.y << " z=" << ex_point.z<<endl;
            cout << "  3D Vector: " << "dx=" << ex_vector.dx << " dy=" << ex_vector.dx << " dz=" << ex_vector.dz << endl;
            cout << endl;
        }
    }
    
    Base* new_v[5];
    j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (v[i]->get_type() == "circle")
        {
            new_v[j]=v[i];
            j++;
        }
    }
    cout << endl << "Container of circles" << endl;
    for (int i = 0; i < 5; i++)
    {
        param = new_v[i]->get_par();
        cout << "Circle: " << "x=" << param.x << " y=" << param.y << " radius=" << param.r1 << endl;
    }
    sort(new_v, new_v+5, rad_sorting);
    cout << endl << "After sorting" << endl;
    int rad_sum = 0;
    for (int i = 0; i < 5; i++)
    {
        param = new_v[i]->get_par();
        rad_sum += param.r1;
        cout << "Circle: " << "x=" << param.x << " y=" << param.y << " radius=" << param.r1 << endl;
    }
    cout << endl << "Total sum of the radii in the second container: " << rad_sum << endl;

    return 0;
}



