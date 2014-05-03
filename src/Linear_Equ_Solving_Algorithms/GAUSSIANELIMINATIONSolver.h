/*
 * GAUSSIANELIMINATIONSolver.h
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#ifndef GAUSSIANELIMINATIONSOLVER_H_
#define GAUSSIANELIMINATIONSOLVER_H_

#include "ISolver.h"
using namespace std;
class GAUSSIAN_ELIMINATION_Solver: public ISolver{
public:

	GAUSSIAN_ELIMINATION_Solver();
	vector<double> solve(vector<vector<double> > A,int N);//n is the number of  variables A must be N*N+1
	virtual ~GAUSSIAN_ELIMINATION_Solver();
};

#endif /* GAUSSIANELIMINATIONSOLVER_H_ */
