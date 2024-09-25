#pragma once
#include <vector>


double L = 10.0;
double dx = 0.1; //шаг по сетке

//Ёлектрическое поле
double E0 = 1;
/*
double E(double x) {
	return (E0 * (x - L / 2));
}
*/

double E(std::vector<double> E, double x1) {
	int n1 = L / dx;
	double x_loc = L - n1 * dx;

	int n2 = n1 + 1;
	//double x2_loc = L - n2 * dx;
	return  (E[n1] * x_loc + E[n2] * (dx - x_loc)) / dx;
}
