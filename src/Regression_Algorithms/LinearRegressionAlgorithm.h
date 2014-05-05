/*
 * LinearRegressionAlgorithm.h
 *
 *  Created on: May 5, 2014
 *      Author: mostafa
 */

#ifndef LINEARREGRESSIONALGORITHM_H_
#define LINEARREGRESSIONALGORITHM_H_

#include "IRegressionAlgorithm.h"

class Linear_Regression_Algorithm: public IRegression_Algorithm {
public:
	Linear_Regression_Algorithm();
	virtual std::vector<Point > solve(std::vector<Point> data,int start,int end,float step);

	virtual ~Linear_Regression_Algorithm();
};

#endif /* LINEARREGRESSIONALGORITHM_H_ */
