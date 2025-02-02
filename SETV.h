#pragma once

#include <iostream>
#include <vector>
#include "E_for.h"
#include <cmath>


using std::vector;

void SETV(std::vector<double>& X_ions, std::vector<double>& X_el, std::vector<double>& V_ions, std::vector<double>& V_el, std::vector<double>& E_vec) {


	// std::cout << "Начальный эл " << X_el[0] << " ";

	for (std::size_t i = 0; i < X_ions.size(); i++) {


		int ceil_ion = X_ions[i] / dx;
		int ceil_el = X_el[i] / dx;

		double x_ion_loc = fmod(X_ions[i], dx * 1.0);
		double x_el_loc = fmod(X_el[i], dx * 1.0);



		V_ions[i] += E_for(E_vec[ceil_ion], E_vec[ceil_ion + 1], x_ion_loc) * (-q / 2) / m_ion * dt;
		V_el[i] -= E_for(E_vec[ceil_el], E_vec[ceil_el + 1], x_el_loc) * (-q / 2) / m_el * dt;

		X_ions[i] += V_ions[i] * dt;
		X_el[i] += V_el[i] * dt;


		// граничные условия: жесткая стенка
		if (X_ions[i] >= L - eps) {
			X_ions[i] = (L - eps) - (X_ions[i] - (L - eps));
			V_ions[i] *= (-1);
		}

		if (X_ions[i] < 0) {
			X_ions[i] *= (-1);
			V_ions[i] *= (-1);
		}

		if (X_el[i] >= L) {
			X_el[i] = (L - eps) - (X_el[i] - (L - eps));
			V_el[i] *= (-1);
		}

		if (X_el[i] < 0) {
			X_el[i] *= (-1);
			V_el[i] *= (-1);
		}

	}
	// std::cout << "Конечный электрон" << X_el[0] << std::endl;



}
