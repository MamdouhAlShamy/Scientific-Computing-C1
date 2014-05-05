/*
 * LinearRegressionAlgorithm.cpp
 *
 *  Created on: May 5, 2014
 *      Author: mostafa
 */

#include "LinearRegressionAlgorithm.h"

Linear_Regression_Algorithm::Linear_Regression_Algorithm() {
	// TODO Auto-generated constructor stub

}
std::vector<Point > Linear_Regression_Algorithm::solve(std::vector<Point> data,int start,int end,float step){
   double sum_xy_ =0,sum_x_=0,sum_y_=0,sum_xsquared_=0;
   double n=data.size();
   for(int i=0;i<data.size();i++)
   {
	   sum_x_+=data[i].x;
	   sum_y_+=data[i].y;
	   sum_xy_+=(data[i].x*data[i].y);
	   sum_xsquared_+=(data[i].x*data[i].x);
   }
   double mean_x=sum_x_/(double)data.size(),mean_y=sum_y_/(double)data.size();
   double a1=(n*sum_xy_-sum_x_*sum_y_)/(n*sum_xsquared_-(sum_x_*sum_x_));
   double a0=mean_y-a1*mean_x;
   std::vector<Point> result;
   for(double x =start;x<end;x+=step)
   {
	   result.push_back(Point(x,a0+a1*x));
   }
   return result;
}

Linear_Regression_Algorithm::~Linear_Regression_Algorithm() {
	// TODO Auto-generated destructor stub
}

