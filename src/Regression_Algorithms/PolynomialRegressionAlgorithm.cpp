/*
 * PolynomialRegressionAlgorithm.cpp
 *
 *  Created on: May 5, 2014
 *      Author: mostafa
 */

#include "PolynomialRegressionAlgorithm.h"
#include "../Linear_Equ_Solving_Algorithms/Solvers.h"
#include "iostream"
#include <math.h>

using namespace std;
Polynomial_Regression_Algorithm::Polynomial_Regression_Algorithm(int o):order(o) {
	// TODO Auto-generated constructor stub

}
std::vector<Point > Polynomial_Regression_Algorithm::solve(std::vector<Point> data,int start,int end,float step)
{
	std::vector<Point> result;
	if(data.size()<order+1)
	{
		std::cerr<<"Not Enough Points"<<std::endl;
		return result;
	}
	vector<vector<double> > augmented_matrix(order+1);
	vector<double> sum_x(order+4,0.0);
	vector<double> sum_x_y(order+4,0.0);
	for(int i=0;i<data.size();i++)
	{
		for(int j=0;j<order+4;j++)
		{
			sum_x[j]+=pow(data[i].x,j);
			sum_x_y[j]+=data[i].y*(pow(data[i].x,j));
		}
	}
	for(int i=0;i<order+1;i++)
	{
		augmented_matrix[i]=vector<double>(order+2);
		for(int j=0;j<order+1;j++)
		{
			augmented_matrix[i][j]=sum_x[j+i];
		}
		augmented_matrix[i][order+1]=sum_x_y[i];
	}
	bool debug=false;
	if(debug)
	{
		cerr<<"augmented matrix"<<endl;
		for(int i=0;i<augmented_matrix.size();i++)
		{
			for(int j=0;j<augmented_matrix[i].size();j++)
				cout<<augmented_matrix[i][j]<<"\t";
			cout<<endl;
		}
	}
	GAUSSIAN_ELIMINATION_Solver solver;
	//GaussianSeidel solver(0.00001);
	vector<double>as= solver.solve(augmented_matrix,order+1);
	for(double x=start;x<end;x+=step)
	{
		double y=0;
		for(int i=0;i<=order;i++)
		{
			y+=pow(x,i)*as[i];
		}
		result.push_back(Point(x,y));
	}
	  double sr =0;
	   for(int i=0;i<data.size();i++)
	   {
		   double y=0;
		   double x=data[i].x;
		   		for(int i=0;i<=order;i++)
		   		{
		   			y+=pow(x,i)*as[i];
		   		}
		   sr+=pow(data[i].y-y,2);
	   }
	   cout<<"Regression Error = "<<sr<<endl;
	return result;
}

Polynomial_Regression_Algorithm::~Polynomial_Regression_Algorithm() {
	// TODO Auto-generated destructor stub
}

