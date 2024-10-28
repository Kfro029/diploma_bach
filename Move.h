// test_cmake.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <vector>
#include "E_f.h"
#include <cmath>

double L = 10.0;


double dt = 0.1;

int num_ceil = L / dx + 1;


int NX = L / dx;

double E_0 = pow(10, -12);

int N = 1000;


double m_ion = 1.67 * pow(10, -27);
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);

using std::vector;

void Move(std::vector<double>& X_ions, std::vector<double>& X_el, std::vector<double>& V_ions, std::vector<double>& V_el) {
	std::vector<double> E_vec;
	int num_ceil = L / dx + 1;
	
	for (int i = 0; i - 1 < num_ceil; i++) {
		E_vec.push_back(E_0 * (i * dx - L / 2));
	}
	
	for (std::size_t i = 0; i < X_ions.size(); i++) {

		int ceil_ion = X_ions[i] / dx;
		int ceil_el = X_el[i] / dx;
		
		double x_ion_loc = fmod(X_ions[i], dx * 1.0);
		double x_el_loc = fmod(X_el[i], dx * 1.0);



		V_ions[i] += E(E_vec[ceil_ion], E_vec[ceil_ion + 1], x_ion_loc) * q * m_ion * dt;
		V_el[i] -= E(E_vec[ceil_el], E_vec[ceil_el + 1], x_el_loc) * q * m_el * dt;

		X_ions[i] += V_ions[i] * dt;
		X_el[i] += V_el[i] * dt;



		if (X_ions[i] >= L) {
			X_ions[i] = L - 2 * (X_ions[i] - L);
			V_ions[i] *= (-1);
		}

		if (X_ions[i] < 0) {
			X_ions[i] *= (-1);
			V_ions[i] *= (-1);
		}

		if (X_el[i] >= L) {
			X_el[i] = L - 2 * (X_el[i] - L);
			V_el[i] *= (-1);
		}

		if (X_el[i] < 0) {
			X_el[i] *= (-1);
			V_el[i] *= (-1);
		}
	}
	


}

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
