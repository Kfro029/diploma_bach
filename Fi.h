#pragma once
#include "Constants.h"
#include <vector>
//программа будет решать методом прогонки уравнение Лапласа

// using std::vector;

void Fi(std::vector<double>& fi, std::vector<double>& rho, std::vector<double> p, std::vector<double> q) {
	/*
	std::vector<double> p(rho.size() - 2, 0.0);
	std::vector<double> q(rho.size() -2, 0.0);

	fi[0] = 0.0;
	fi[fi.size() - 1] = 0.0;
	//прямой ход прогонки
	p[1] = 1.0 / 2;
	q[1] = (-rho[0] - fi[0]) / 2;

	for (std::size_t i = 2; i < rho.size() - 2; i++) {
		p[i] = -1 / (p[i - 1] - 2);
		q[i] = (-rho[i] - q[i - 1]) / (p[i - 1] - 2);
	}
	fi[rho.size() - 2] = (-rho[rho.size() - 2] - fi[fi.size() - 1] - q[rho.size() - 3])/(p[rho.size() - 3] - 2);

	//обратный ход прогонки
	for (std::size_t i = rho.size() - 3; i > 0; i -= 1) {
		fi[i] = p[i] * fi[i + 1] + q[i];
	}
	*/
	//std::vector<double> p(rho.size() - 2, 0.0);
	//std::vector<double> q(rho.size() - 2, 0.0);

	//ГУ
	fi[0] = 0.0;
	fi[fi.size() - 1] = 0.0;

	//прямой ход прогонки
	p[1] = 1.0 / 2.0;
	q[1] = (dx * dx * rho[1] - fi[0]) / (-2.0);

	for (std::size_t i = 2; i + 2 < fi.size(); i++) {
		p[i] = -1.0 / (p[i - 1] - 2.0);
		q[i] = (dx * dx * rho[i] - q[i - 1]) / (p[i - 1] - 2.0);
	}

	fi[fi.size() - 2] = (dx * dx * rho[fi.size() - 2] - fi[fi.size() - 1] - q[fi.size() - 3]) / (p[fi.size() - 3] - 2.0);

	//обратный ход
	for (std::size_t i = fi.size() - 3; i > 0; i--) {
		fi[i] = p[i] * fi[i + 1] + q[i];
	}





}
