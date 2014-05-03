/*
 * IinterpolationAlgorithm.h
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#ifndef IINTERPOLATIONALGORITHM_H_
#define IINTERPOLATIONALGORITHM_H_
#include "../utils.h"
#include <vector>
class IinterpolationAlgorithm {
public:
	IinterpolationAlgorithm(){}
	//function take data and interpolate through range start and end with step
	//if you need another argument add it to the constructor of the implementor class
	virtual std::vector<Point > solve(std::vector<Point> data,int start,int end,int step)=0;
	virtual ~IinterpolationAlgorithm(){}
};

#endif /* IINTERPOLATIONALGORITHM_H_ */
