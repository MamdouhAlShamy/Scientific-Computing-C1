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
	int n = data.size();
	f[1] = 2 * (data[2].x - data[0].x);
	g[2] = (data[2].x - data[1].x);
	r[3] = (6 / (data[2].x - data[1].x)) * (data[2].y - data[1].y);
	r[4] = r[1] + ((6 / (data[1].x - data[0].x)) * (data[0].y - data[1].y));

	for (int i = 2; i < (n - 1); i++) {
		e[i] = (data[i].x - data[i - 1].x);
		f[i] = 2 * (data[i + 1].x - data[i - 1].x);
		g[i] = (data[i + 1].x - data[i].x);
		r[i] = (6 / (data[i + 1].x - data[i].x)) * (data[i + 1].y - data[i].y);
		r[i] =
				r[i]
						+ ((6 / data[i].x - data[i - 1].x)
								* (data[i - 1].y - data[i].y));
	}
	e[n - 1] = data[n - 1].x - data[n - 2].x;
	f[n - 1] = 2 * (data[n].x - data[n - 2].x);
	r[n - 1] = 6 / ((data[n].x - data[n - 1].x) * (data[n].y - data[n - 1].y));
	r[n - 1] = r[n - 1]
			+ (6
					/ ((data[n - 1].x - data[n - 2].x) * (data[n - 2].y)
							- data[n - 1].y));

}

double CubicSpline::interpolate(vector<Point> data, double * d2x, double xu) {
	int i = 1;
	int q = data.size();
	while (i <= q + 1) {
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
		double * r) {
	GAUSSIAN_ELIMINATION_Solver solver = GAUSSIAN_ELIMINATION_Solver();
	int n = 3;
	vector<vector<double> > m(n);
	m[0] = vector<double>(4);
	m[0][0] = e[1];
	m[0][1] = f[1];
	m[0][2] = g[1];
	m[0][3] = r[1];
	m[1] = vector<double>(4);
	m[1][0] = e[2];
	m[1][1] = f[2];
	m[1][2] = g[2];
	m[1][3] = r[2];
	m[2] = vector<double>(4);
	m[2][0] = e[3];
	m[2][1] = f[3];
	m[2][2] = g[3];
	m[2][3] = r[3];
	vector<double> res = solver.solve(m, n);
	for (int i = 0; i < n; i++) {
		cout << res[i] << endl;
	}
	return res;
}

vector<Point> CubicSpline::solve(vector<Point> data, int start, int end,
		float step) {

	vector<Point> search;
	int n = data.size();
	double e[n], f[n], g[n], r[n], dd2x[n];
	std::fill_n(e, n, 0);
	std::fill_n(f, n, 0);
	std::fill_n(g, n, 0);
	std::fill_n(r, n, 0);
	std::fill_n(dd2x, n, 0);

	tridiag(data, e, f, g, r);
//	for (int i = 1; i < n; i++) {
//		cout << i << '\t' << e[i] << endl;
//		cout << i << '\t' << f[i] << endl;
//		cout << i << '\t' << g[i] << endl;
//		cout << i << '\t' << r[i] << endl;
//	}
	double xu, yu;
	vector<double> d2x;
	d2x = subst(e, f, g, r);
	cout << "EQUATION SOLVED" << endl;
	for (int i = 0; i < 3; i++) {
		dd2x[i] = d2x[i];
		cout << dd2x[i] << endl;
	}

	//TODO LOOPING to make a curve
	for (xu = data[0].x + 1; xu <= data.back().x; xu += step) {
		yu = interpolate(data, dd2x, xu);
		cout << "xu: " << xu << '\t' << "yu: " << yu << endl;
		search.push_back(Point(xu, yu));
	}
	return search;
}
CubicSpline::~CubicSpline() {
// TODO Auto-generated destructor stub
}

