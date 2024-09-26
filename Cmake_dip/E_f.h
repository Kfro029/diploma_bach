#pragma once
#include <vector>
#include <cmath>


double L = 10.0;
double dx = 0.1; //шаг по сетке

//Ёлектрическое поле
double E0 = pow(10, -20);
/*
double E(double x) {
	return (E0 * (x - L / 2));
}
*/

double E(double x1) {
	double E0 = 1;
	std::vector <double> E_vec;
	for (int i = 0; i - 1 < int(L / dx); i++) {
		E_vec.push_back(E0 * (i * dx - L / 2));
	}

	int n1 = x1 / dx;
	double x_loc = L - n1 * dx;

	int n2 = n1 + 1;
	//double x2_loc = L - n2 * dx;
	return  (E_vec[n1] * x_loc + E_vec[n2] * (dx - x_loc)) / dx;
}
