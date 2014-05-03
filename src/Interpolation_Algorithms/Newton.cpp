/*
 * Newton.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mostafa
 */

#include "Newton.h"
#include <vector>
#include "../utils.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

Newton::Newton() {

}
vector<Point> Newton::solve(vector<Point> data, int start, int end, int step) {

	int i, j, k , m;
	vector<Point> search;
	float differ[data.size()][data.size()], product, sum;

	// Get Y for desired X
	for (float m = data.front().x + 1; m < data.back().x; m = m + step) {

		k = 0;
		if (m < data.front().x || m > data.back().x) {
			printf("\n\nValue lies outside the given values of x ");
			// ERROR;
		} else {
			for (j = 0; j < data.size() - 1; j++) {
				for (i = 0; i < data.size() - (j + 1); i++) {
					if (j == 0) {
						differ[i][j] = (data.at(i + 1).y - data.at(i).y)
								/ (data.at(i + 1).x - data.at(i).x);
					} else {
						differ[i][j] = (differ[i + 1][j - 1] - differ[i][j - 1])
								/ (data.at(i + (j + 1)).x - data.at(i).x);
					}
				}
			}
			for (i = 0; i < data.size(); i++) {
				if (m > data.at(i).x) {
					k = k + 1;
				}
			}

			k = k - 1;
			sum = data.at(k).y;
			for (i = 0; i < data.size() - (k + 1); i++) {
				product = 1;
				for (j = 0; j <= i; j++) {
					product = product * (m - data.at(j + k).x);
				}
				sum = sum + (differ[k][i] * product);

			}
		}
		search.push_back(Point(m, sum));
	}

	return search;
}

Newton::~Newton() {
// TODO Auto-generated destructor stub
}

