/*
 * CubicSpline.h
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#ifndef CUBICSPLINE_H_
#define CUBICSPLINE_H_

#include "IinterpolationAlgorithm.h"

class CubicSpline: public IinterpolationAlgorithm {
public:
	CubicSpline();
	std::vector<Point > solve(std::vector<Point> data,int start,int end,int step);
	virtual ~CubicSpline();
};

#endif /* CUBICSPLINE_H_ */
