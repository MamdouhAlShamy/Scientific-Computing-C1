//============================================================================
// Name        : Task1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Linear_Equ_Solving_Algorithms/Solvers.h"
#include"Interpolation_Algorithms/Interpolation_Algorithms.h"
#include <vector>
#include <fstream>
#include "utils.h"
#include <stdlib.h>
#include<time.h>

using namespace std;
void help() {
	cout << "Welcome" << endl;
	cout << "interpolation: " << endl;
	cout
			<< "Usage : ./Task1 --interpolate <Algorithm> <Input file name> <Output Prefix> <Start> <End> <Step Size> <No of Points Used In Interpolation>"
			<< endl;
	;
	cout << "Available Algorithms: " << endl;
	cout << "\t--cubic" << endl;
	cout << "\t--newton" << endl;
}

template<class Interpolate_Algo>
void interpolate(string input_file_name, string output_prefix, int start,
		int end, int step, int no_samples_used) {
	ifstream inputfile(input_file_name.c_str());
	vector<Point> input;
	double x, y;
	while (inputfile >> x >> y) {
		input.push_back(Point(x, y));
	}
	while (input.size() > no_samples_used) //get random sample
	{
		int victim = rand() % input.size();
		input.erase(input.begin() + victim);
	}
	cout << "data size: " << input.size() << endl;

	Interpolate_Algo interpolater;
	vector<Point> res = interpolater.solve(input, start, end, step);
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
	if (argc > 1 && string("--help").compare(argv[1]) == 0) {
		help();
		return -1;
	}
	srand(time(NULL));
	if (string("--solve").compare(argv[1]) == 0) {
		cout << "sss" << endl;
		const int n = 2;
		GAUSSIAN_ELIMINATION_Solver solver = GAUSSIAN_ELIMINATION_Solver();

		vector<vector<double> > m(2);
		m[0] = vector<double>(3);
		m[0][0] = 3, m[0][1] = 2, m[0][2] = 18;

		m[1] = vector<double>(3);
		m[1][0] = -1, m[1][1] = 2, m[1][2] = 2;
		vector<double> res = solver.solve(m, n);
		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	} else if (string("--interpolate").compare(argv[1]) == 0) {
		cout << "Interpolate .. " << endl;
		string algorithm = argv[2];
		string input_file = argv[3];
		string output_file = argv[4];
		int start = atoi(argv[5]);
		int end = atoi(argv[6]);
		int step = atoi(argv[7]);
		int no_sample_points_used = atoi(argv[8]);
		if (algorithm.compare("--cubic") == 0) {
			interpolate<CubicSpline>(input_file, output_file, start, end, step,
					no_sample_points_used);
		} else if (algorithm.compare("--newton") == 0) {
			cout << "Interpolating using Newton" << endl;
			interpolate<Newton>(input_file, output_file, start, end, step,
					no_sample_points_used);
		} else {
			cerr << algorithm << " is not supported" << endl;
			help();
			return -1;
		}

	} else if (string("--regress").compare(argv[1]) == 0) {

	} else {
		cerr << "Wrong parameters" << endl;
		help();
		return -1;

//		 RUN FROM IDE

	}
	return 0;
}
