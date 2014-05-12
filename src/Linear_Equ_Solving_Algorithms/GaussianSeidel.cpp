/*
 * GaussianSeidel.cpp
 *
 *  Created on: May 12, 2014
 *      Author: mostafa
 */

#include "GaussianSeidel.h"
#include <vector>
using namespace std;
GaussianSeidel::GaussianSeidel(double s) {
	// TODO Auto-generated constructor stub
	specified_tolerance=s;

}
vector<double> GaussianSeidel::solve(vector<vector<double> > A,int N)//n is the number of  variables A must be N*N+1
{
	vector<double> res(N,0.000001);
	vector<double> diff(N,specified_tolerance+1);
	bool more_calculations=true;
	while(more_calculations)
	{
		for(int i=0;i<N;i++)
		{
			double old=res[i];
			res[i]=A[i][N];
			for(int j=0;j<N;j++)
			{
				if(j!=i){
					res[i]+=res[j]*A[i][j]*-1;
				}
			}
			res[i]/=A[i][i];
			diff[i]=((res[i]-old)/res[i])*100.0;
		}
		more_calculations=false;
		for(int i=0;i<N;i++)
		{
			if(diff[i]>specified_tolerance)
			{
				more_calculations=true;
				break;
			}
		}
	}
	return res;
}
GaussianSeidel::~GaussianSeidel() {
	// TODO Auto-generated destructor stub
}

