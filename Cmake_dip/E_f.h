#pragma once
#include <vector>
#include <cmath>


const double L = 10.0;
const double dx = 0.1; //шаг по сетке

//Ёлектрическое поле
double E0 = pow(10, -12);
/*
double E(double x) {
	return (E0 * (x - L / 2));
}
*/

double E(double E1, double E2, double x) {

	//int n1 = x1 / dx;
	//double x_loc = L - n1 * dx;

	//int n2 = n1 + 1;
	//double x2_loc = L - n2 * dx;
	return  (E1 * x + E2 * (L - x)) / dx;
}
