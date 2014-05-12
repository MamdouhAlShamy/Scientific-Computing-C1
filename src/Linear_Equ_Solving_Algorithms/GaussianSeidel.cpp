/*
 * GaussianSeidel.cpp
 *
 *  Created on: May 12, 2014
 *      Author: mostafa
 */

#include "GaussianSeidel.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
GaussianSeidel::GaussianSeidel(double s) {
	// TODO Auto-generated constructor stub
	specified_tolerance=s;

}
vector<double> GaussianSeidel::solve(vector<vector<double> > A,int N)//n is the number of  variables A must be N*N+1
{
	//pivoting step
	vector<int> row_index(N);
	for(int i=0;i<N;i++)
		row_index[i]=i;

	bool good=true;
	do{
		good=true;
		for(int l=0;l<N;l++)
		{
			int i=row_index[l];
			if(A[i][i]<0.0000000000000001)
			{
				good=false;
			}
			if(good)
				break;
		}
	}while(next_permutation(row_index.begin(),row_index.end()));
	if(!good)
	{
		cerr<<"Warning Zero Exists in the diagonal "<<endl;
	}
	vector<double> res(N,0.000001);
	vector<double> diff(N,specified_tolerance+1);
	bool more_calculations=true;
	while(more_calculations)
	{
		for(int l=0;l<N;l++)
		{
			int i=row_index[l];
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

