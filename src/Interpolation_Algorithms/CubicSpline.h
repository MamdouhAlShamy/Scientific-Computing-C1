/*
 * CubicSpline.h
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#ifndef CUBICSPLINE_H_
#define CUBICSPLINE_H_

#include <vector>

using namespace std;
#include "../utils.h"
#include "IinterpolationAlgorithm.h"
#include <iostream>
#include <cmath>
using namespace std;

class CubicSpline: public IinterpolationAlgorithm {
public:
	CubicSpline();
	std::vector<Point> solve(std::vector<Point> data, int start, int end,
			float step);
	virtual ~CubicSpline();
private:
	void tridiag(vector<Point> data, double * e, double* f, double* g,
			double* r);
	double interpolate(vector<Point> data, double * d2x, double xu);
	vector<double> subst(double * e, double * f, double * g, double * r,
			int numberOfInterval);
};

#endif /* CUBICSPLINE_H_ */
