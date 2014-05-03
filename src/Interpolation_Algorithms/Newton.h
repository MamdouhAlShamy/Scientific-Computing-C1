/*
 * Newton.h
 *
 *  Created on: Apr 30, 2014
 *      Author: mostafa
 */

#ifndef NEWTON_H_
#define NEWTON_H_

#include "IinterpolationAlgorithm.h"

class Newton: public IinterpolationAlgorithm {
public:
	Newton();
	std::vector<Point > solve(std::vector<Point> data,int start,int end,int step);
	virtual ~Newton();
};

#endif /* NEWTON_H_ */
