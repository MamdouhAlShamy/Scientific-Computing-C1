/*
 * CubicSpline.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#include "CubicSpline.h"
#include <iostream>
using namespace std;
CubicSpline::CubicSpline() {
	// TODO Auto-generated constructor stub

}
vector<Point> CubicSpline::solve(vector<Point> data,int start,int end,int step)
{
	///replace this dummy code with Cubic Spline Algorithm
	vector<Point> res;
	while(start<end)
	{
		res.push_back(Point(start,0));
		start+=step;
	}
	return res;
}
CubicSpline::~CubicSpline() {
	// TODO Auto-generated destructor stub
}

