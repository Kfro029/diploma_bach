#pragma once
#include "Constants.h"
#include <vector>
//программа будет решать методом прогонки уравнение Лапласа

using std::vector;

void Fi(std::vector<double>& fi, std::vector<long double>& rho) {
	
	std::vector<double> p(rho.size(), 0.0);
	std::vector<double> q(rho.size(), 0.0);

	//прямой ход прогонки
	p[1] = 1.0 / 2;
	q[1] = (-rho[0] / eps_0) * dx * dx / 2;

	for (int i = 2; i < rho.size(); i++) {
		p[i] = -1 / (p[i - 1] - 2);
		q[i] = (-rho[i - 1] / eps_0 * dx * dx - q[i - 1]) / (p[i - 1] - 2);
	}
	fi[rho.size() - 1] = (-rho[rho.size() - 1] / eps_0 * dx * dx - q[rho.size() - 1]);

	//обратный ход прогонки
	for (int i = rho.size() - 2; i + 1 > 0; i -= 1) {
		fi[i] = p[i + 1] * fi[i + 1] + q[i + 1];
	}

}
