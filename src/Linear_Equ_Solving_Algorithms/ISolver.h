/*
 * ISolver.h
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#ifndef ISOLVER_H_
#define ISOLVER_H_
#include <vector>

#define ZERO 1.0E-20
#define true 1
#define false 0


class ISolver {
public:
	ISolver(){

	}
	virtual  std::vector<double> solve(std::vector< std::vector<double> > a,int n) =0 ;//n is the number of variables
	virtual ~ISolver(){

	}
};

#endif /* ISOLVER_H_ */
