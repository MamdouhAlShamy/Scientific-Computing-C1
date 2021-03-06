/*
 * CubicSpline.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#include "CubicSpline.h"

#include "../Linear_Equ_Solving_Algorithms/GAUSSIANELIMINATIONSolver.h"

CubicSpline::CubicSpline() {

}
void CubicSpline::tridiag(vector<Point> data, double* e, double* f, double* g,
		double* r) {
	int numberOfIntervals = data.size() - 1; // efgr[0] not used
	e[1] = 0;
	f[1] = 2 * (data[2].x - data[0].x);
	g[1] = (data[2].x - data[1].x);
	r[1] = (6 / (data[2].x - data[1].x)) * (data[2].y - data[1].y);
	r[1] = r[1] + ((6 / (data[1].x - data[0].x)) * (data[0].y - data[1].y));

	for (int i = 2; i < (numberOfIntervals - 1); i++) {
		e[i] = (data[i].x - data[i - 1].x);
		f[i] = 2 * (data[i + 1].x - data[i - 1].x);
		g[i] = (data[i + 1].x - data[i].x);
		r[i] = (6.0 / (data[i + 1].x - data[i].x))
				* (data[i + 1].y - data[i].y);
		r[i] = r[i]
				+ ((6.0 / (data[i].x - data[i - 1].x))
						* (data[i - 1].y - data[i].y));
	}
	e[numberOfIntervals - 1] = data[numberOfIntervals - 1].x
			- data[numberOfIntervals - 2].x;
	f[numberOfIntervals - 1] = 2
			* (data[numberOfIntervals].x - data[numberOfIntervals - 2].x);
	g[numberOfIntervals - 1] = 0; //data[n].x - data[n - 1].x;
	r[numberOfIntervals - 1] = (6.0
			/ (data[numberOfIntervals].x - data[numberOfIntervals - 1].x))
			* (data[numberOfIntervals].y - data[numberOfIntervals - 1].y);
	r[numberOfIntervals - 1] = r[numberOfIntervals - 1]
			+ ((6.0
					/ ((data[numberOfIntervals - 1].x
							- data[numberOfIntervals - 2].x)))
					* (data[numberOfIntervals - 2].y
							- data[numberOfIntervals - 1].y));

}

double CubicSpline::interpolate(vector<Point> data, double * d2x, double xu) {
	int i = 1;
	int intervals = data.size() - 1;
	while (i <= intervals) {
		// check if it is in the intervals
		if (xu >= data[i - 1].x && xu <= data[i].x) {
			double c1 = d2x[i - 1] / (6 * (data[i].x - data[i - 1].x));
			double c2 = d2x[i] / (6 * (data[i].x - data[i - 1].x));
			double c3 = (data[i - 1].y / (data[i].x - data[i - 1].x))
					- (d2x[i - 1] * (data[i].x - data[i - 1].x) / 6);
			double c4 = (data[i].y / (data[i].x - data[i - 1].x))
					- ((d2x[i] * (data[i].x - data[i - 1].x)) / 6);

			double t1 = c1 * pow((data[i].x - xu), 3);
			double t2 = c2 * pow((xu - data[i - 1].x), 3);
			double t3 = c3 * (data[i].x - xu);
			double t4 = c4 * (xu - data[i - 1].x);
			return (t1 + t2 + t3 + t4);
		} else {
			i = i + 1;
		}
	}
}

vector<double> CubicSpline::subst(double * e, double * f, double * g,
		double * r, int numberOfInterval) {
	cout << "numberOfInterval: " << numberOfInterval << endl;
	GAUSSIAN_ELIMINATION_Solver solver = GAUSSIAN_ELIMINATION_Solver();

	vector<vector<double> > m(numberOfInterval - 1);
	// fill m w zeros

	for (int i = 0; i < numberOfInterval - 1; i++) {
		// Create Row
		m[i] = vector<double>(numberOfInterval);
		// First Equation
		if (i == 0) {
			cout << "Eq: 0" << endl;
			m[0][0] = f[1];
			m[0][1] = g[1];
		}
		// Last Equation
		else if (i == numberOfInterval - 2) {
			cout << "last Eq: " << i << endl;
			m[i][numberOfInterval - 3] = e[i + 1];
			m[i][numberOfInterval - 2] = f[i + 1];
		}
		// inside Equation
		else {
			cout << "Eq: " << i << endl;
			m[i][i - 1] = e[i + 1];
			m[i][i] = f[i + 1];
			m[i][i + 1] = g[i + 1];
		}
		// after equal sign value
		m[i][numberOfInterval - 1] = r[i + 1];

	}

// working model for 18.8m
//	vector<vector<double> > m(numberOfInterval-1);
//	m[0] = vector<double>(numberOfInterval);
//	m[0][0] = f[1];
//	m[0][1] = g[1];
//	m[0][2] = 0;
//	m[0][3] = r[1];
//
//	m[1] = vector<double>(numberOfInterval);
//	m[1][0] = e[2];
//	m[1][1] = f[2];
//	m[1][2] = g[2];
//	m[1][3] = r[2];
//
//	m[2] = vector<double>(numberOfInterval);
//	m[2][0] = 0;
//	m[2][1] = e[3];
//	m[2][2] = f[3];
//	m[2][3] = r[3];

//	vector<vector<double> > m(numberOfInterval);
//	m[0] = vector<double>(3);
//	m[0][0] = f[1];
//	m[0][1] = g[1];
//	m[0][2] = r[1];
//
//	m[1] = vector<double>(3);
//	m[1][0] = e[2];
//	m[1][1] = f[2];
//	m[1][2] = r[2];

//	// FIXME Issue in Solving Equations simultaneously
//	vector<vector<double> > m(numberOfInterval);
//	for (int i = 0; i < numberOfInterval - 1; i++) {
//		m[i] = vector<double>(3);
//		m[i][0] = f[i + 1];
//		m[i][1] = g[i + 1];
//		m[i][2] = r[i + 1];
//	}
//
//	m[numberOfInterval - 1] = vector<double>(3);
//	m[numberOfInterval - 1][0] = e[numberOfInterval];
//	m[numberOfInterval - 1][1] = f[numberOfInterval];
//	m[numberOfInterval - 1][2] = r[numberOfInterval];

//	for (int i = 0; i < numberOfInterval; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << "m[" << i << "][" << j << "]" << m[i][j] << endl;
//		}
//	}
	return solver.solve(m, numberOfInterval - 1);
}

vector<Point> CubicSpline::solve(vector<Point> data, int start, int end,
		float step) {

	vector<Point> search;
	int n = data.size();
//cout << "n: " << n << endl;
	double e[n], f[n], g[n], r[n], dd2x[n]; // they are numbered w no of intervals +1 as [0] is not used
	std::fill_n(e, n, 0);
	std::fill_n(f, n, 0);
	std::fill_n(g, n, 0);
	std::fill_n(r, n, 0);
	std::fill_n(dd2x, n, 0);

	tridiag(data, e, f, g, r);
	for (int i = 1; i < n - 1; i++) {
		cout << "e[" << i << "]" << '\t' << e[i] << endl;
		cout << "f[" << i << "]" << '\t' << f[i] << endl;
		cout << "g[" << i << "]" << '\t' << g[i] << endl;
		cout << "r[" << i << "]" << '\t' << r[i] << endl;
	}
	double xu, yu;
	vector<double> d2x(n - 1);
	d2x = subst(e, f, g, r, n - 1);
	cout << "EQUATION SOLVED" << endl;
	for (int i = 1; i < n - 1; i++) {
		dd2x[i] = d2x[i - 1];
		cout << "dd2x" << dd2x[i] << endl;
	}

// LOOPING to make a curve
	for (xu = start; xu <= end; xu += step) {
		yu = interpolate(data, dd2x, xu);
		cout << "xu: " << xu << '\t' << "yu: " << yu << endl;
		search.push_back(Point(xu, yu));
	}
	return search;
}
CubicSpline::~CubicSpline() {
}

