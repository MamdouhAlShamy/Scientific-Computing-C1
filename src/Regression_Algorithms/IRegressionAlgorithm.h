/*
 * IRegressionAlgorithm.h
 *
 *  Created on: May 5, 2014
 *      Author: mostafa
 */

#ifndef IREGRESSIONALGORITHM_H_
#define IREGRESSIONALGORITHM_H_
#include <vector>
#include "../utils.h"
class IRegression_Algorithm {
public:
	IRegression_Algorithm(){}
	virtual std::vector<Point > solve(std::vector<Point> data,int start,int end,float step)=0;
	virtual ~IRegression_Algorithm(){}
};

#endif /* IREGRESSIONALGORITHM_H_ */
