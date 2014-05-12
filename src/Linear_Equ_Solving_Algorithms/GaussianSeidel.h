/*
 * GaussianSeidel.h
 *
 *  Created on: May 12, 2014
 *      Author: mostafa
 */

#ifndef GAUSSIANSEIDEL_H_
#define GAUSSIANSEIDEL_H_

#include "ISolver.h"
#include <vector>

using namespace std;

class GaussianSeidel: public ISolver {
public:
	double specified_tolerance;
	GaussianSeidel(double specified_tolerance);
	vector<double> solve(vector<vector<double> > A,int N);//n is the number of  variables A must be N*N+1

	virtual ~GaussianSeidel();
};

#endif /* GAUSSIANSEIDEL_H_ */
