#pragma once
#include "Constants.h"
#include <vector>
//????????? ????? ?????? ??????? ???????? ????????? ???????

// using std::vector;

void Fi(std::vector<double>& fi, std::vector<double>& rho_ions, std::vector<double>& rho_el, std::vector<double>& rho, std::vector<double> p, std::vector<double> q) {
	
	for (std::size_t i = 0; i < rho.size(); i++) {
		rho[i] += rho_el[i] + rho_ions[i];
	}

	//ГУ


	fi[0] = 0.0;
	fi[fi.size() - 1] = 0.0;

	//прямой ход
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
