//============================================================================
// Name : Task1.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Linear_Equ_Solving_Algorithms/Solvers.h"
#include"Interpolation_Algorithms/Interpolation_Algorithms.h"
#include "Regression_Algorithms/Regression_Algorithms.h"
#include <vector>
#include <fstream>
#include "utils.h"
#include <stdlib.h>
#include<time.h>

using namespace std;
void help() {
	cout << "Welcome" << endl;
	cout << "Regression: " << endl;
	cout
	<< "Usage : ./Task1 --regress <Algorithm> <Input file name> <Output Prefix> <Start> <End> <Step Size> <order> <linear quation solvers>"
	<< endl;
	;
	cout << "Available Algorithms: " << endl;
	cout << "\t--Linear" << endl;
	cout << "\t--Polynomial" << endl;
	cout << "Available Solvers: default (Elimination)" << endl;
	cout << "\t--siedel" << endl;
	cout << "\t--elimination" << endl;

	cout << "interpolation: " << endl;
	cout
	<< "Usage : ./Task1 --interpolate <Algorithm> <Input file name> <Output Prefix> <Start> <End> <Step Size> <No of Points Used In Interpolation>"
	<< endl;
	;
	cout << "Available Algorithms: " << endl;
	cout << "\t--cubic" << endl;
	cout << "\t--newton" << endl;
}



void regress(string input_file_name, string output_prefix, int start,
		int end, float step,IRegression_Algorithm* regress) {
	ifstream inputfile(input_file_name.c_str());
	vector<Point> input;
	double x, y;
	while (inputfile >> x >> y) {
		input.push_back(Point(x, y));
	}

	cout << "data size: " << input.size() << endl;


	vector<Point> res = regress->solve(input, start, end, step);
	if ( res.size()==0 )
		return ;
	ofstream output_dat(string(output_prefix + "out.dat").c_str());
	for (int i = 0; i < res.size() - 1; i++)
		output_dat << res.at(i).x << "\t" << res.at(i).y << endl;
	output_dat.close();
	system(
			string(
					"../plot.sh " + input_file_name + " " + output_prefix
					+ "out.dat" + " " + output_prefix + "out.png").c_str());

}

template<class Interpolate_Algo>
void interpolate(string input_file_name, string output_prefix, int start,
		int end, float step) {
	ifstream inputfile(input_file_name.c_str());
	vector<Point> input;
	double x, y;
	while (inputfile >> x >> y) {
		input.push_back(Point(x, y));
	}

	cout << "data size: " << input.size() << endl;

	Interpolate_Algo interpolater;
	vector<Point> res = interpolater.solve(input, start, end, step);
	double nan=1.0/0.0;
	//	for (int i =0; i < res.size();i++)
	//	{
	//		if(res[i].y !=res[i].y)
	//		{
	//			res.erase(res.begin()+i);
	//			i--;
	//		}
	//	}
	ofstream output_dat(string(output_prefix + "out.dat").c_str());
	for (int i = 0; i < res.size() - 1; i++)
		output_dat << res.at(i).x << "\t" << res.at(i).y << endl;
	output_dat.close();
	system(
			string(
					"../plot.sh " + input_file_name + " " + output_prefix
					+ "out.dat" + " " + output_prefix + "out.png").c_str());

}

int main(int argc, char* argv[]) {
	//cout<<1.0/0.0<<endl;
	if (argc > 1 && string("--help").compare(argv[1]) == 0) {
		help();
		return -1;
	}



	srand(time(NULL));
	if (string("--solve").compare(argv[1]) == 0) {
		//radom data generator
		int N=atoi(argv[3]);
		vector<vector<double> >m(N);
		for(int i=0;i<N;i++)
		{
			m[i]=vector<double>(N+1);
			double sum=0;
			for(int j=0;j<N+1;j++)
			{
				if(i!=j)
				{
					double curr=rand()%10000;
					double sign=rand()%2;
					sign =(sign==0? 1:-1);
					curr*=sign;
					sum+=curr;
					m[i][j]=curr;
				}
			}
			m[i][i]=sum+rand()%100;
		}
		cerr<<"Data Preparation is finised"<<endl;
		vector<double> res;
		if(string("--elimination").compare(argv[2])==0){
			GAUSSIAN_ELIMINATION_Solver solver=GAUSSIAN_ELIMINATION_Solver();
			res = solver.solve(m, N);
		}
		else if(string("--seidel").compare(argv[2])==0){
			float acc=atof(argv[4]);
			GaussianSeidel solver=GaussianSeidel(acc);
			res = solver.solve(m, N);
		}
		else
		{
			cerr<<"unsupported Algorithm"<<endl;
			return 0;
		}
		for(int i=0;i<N;i++)
			cout<<res[i]<<endl;
		double error=0;
		for (int i = 0; i < N; i++) {
			double sum=0;
			for(int j=0;j<N;j++)

				sum+=m[i][j]*res[j];
			error+=fabs(sum-m[i][N]);
		}
		cout<<"Total Absolute  Error = "<<error << endl;

		//		vector<vector<double> > m(2);
		//		m[0] = vector<double>(3);
		//		m[0][0] = 3, m[0][1] = -0.1, m[0][2] = 18;
		//
		//		m[1] = vector<double>(3);
		//		m[1][0] = -1, m[1][1] = 2, m[1][2] = 2;
		//
		//		 int n = 3;
		//		 vector<vector<double> > m(n);
		//		 m[0] = vector<double>(4);
		//		 m[0][0] = 3;
		//		 m[0][1] = -0.1;
		//		 m[0][2] = -0.2;
		//		 m[0][3] = 7.85;
		//		 m[1] = vector<double>(4);
		//		 m[1][0] = 0.1;
		//		 m[1][1] = 7;
		//		 m[1][2] = -0.3;
		//		 m[1][3] = -19.3;
		//		 m[2] = vector<double>(4);
		//		 m[2][0] = 0.3;
		//		 m[2][1] = -0.2;
		//		 m[2][2] = 10;
		//		 m[2][3] = 71.4;


	} else if (string("--interpolate").compare(argv[1]) == 0) {
		cout << "Interpolate .. " << endl;
		string algorithm = argv[2];
		string input_file = argv[3];
		string output_file = argv[4];
		int start = atoi(argv[5]);
		int end = atoi(argv[6]);
		float step = atof(argv[7]);
		if (algorithm.compare("--cubic") == 0) {
			cout << "Interpolating using Cubic Spline" << endl;
			interpolate<CubicSpline>(input_file, output_file, start, end, step);
		} else if (algorithm.compare("--newton") == 0) {
			cout << "Interpolating using Newton" << endl;
			interpolate<Newton>(input_file, output_file, start, end, step);
		} else {
			cerr << algorithm << " is not supported" << endl;
			help();
			return -1;
		}

	} else if (string("--regress").compare(argv[1]) == 0) {
		cout << "Regress .. " << endl;
		string algorithm = argv[2];
		string input_file = argv[3];
		string output_file = argv[4];
		int start = atoi(argv[5]);
		int end = atoi(argv[6]);

		float step = atof(argv[7]);
		if (algorithm.compare("--linear") == 0) {
			cout << "Using Linear Regression" << endl;
			IRegression_Algorithm* regresss=new Linear_Regression_Algorithm();
			regress(input_file, output_file, start, end, step,
					regresss);
		} else if (algorithm.compare("--polynomial") == 0) {
			int order=atoi(argv[8]);
			bool solver=false;;
			if(argc>9)
			{
				if(string("--seidel").compare(argv[9])==0)
				{
					solver=true;
				}
				else if(string("--elimination").compare(argv[9])==0)
				{
					solver=false;
				}
				else
				{
					cerr<<"Unkown Solver Algorithm : Gaussian elimination with partial pivoting is used instead"<<endl;
				}
			}

			IRegression_Algorithm * regresss=new Polynomial_Regression_Algorithm(order,solver);
			regress(input_file, output_file, start, end, step,
					regresss);
		} else {
			cerr << algorithm << " is not supported" << endl;
			help();
			return -1;
		}

	} else {
		cerr << "Wrong parameters" << endl;
		help();
		return -1;

		// RUN FROM IDE

	}
	return 0;
}
