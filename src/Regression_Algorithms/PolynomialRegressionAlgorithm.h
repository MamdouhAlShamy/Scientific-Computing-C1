/*
 * PolynomialRegressionAlgorithm.h
 *
 *  Created on: May 5, 2014
 *      Author: mostafa
 */

#ifndef POLYNOMIALREGRESSIONALGORITHM_H_
#define POLYNOMIALREGRESSIONALGORITHM_H_

#include "../utils.h"

#include "IRegressionAlgorithm.h"
#include <vector>

class Polynomial_Regression_Algorithm: public IRegression_Algorithm {
private:
	int order;
public:
	Polynomial_Regression_Algorithm(int order);
	virtual std::vector<Point > solve(std::vector<Point> data,int start,int end,float step);

	virtual ~Polynomial_Regression_Algorithm();
};

#endif /* POLYNOMIALREGRESSIONALGORITHM_H_ */
