// Cmake_dip.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "E_f.h"
#include <fstream>

// Число частиц
const int N = 10;

//Основные константы
const double m_ion = 1.673 * pow(10, -27); 
const double m_el = 9.31 * pow(10, -31);
const double q = 1.6 * pow(10, -19);


// шаг по времени и время
const double dt = 0.1;
const double T = 10.0;

//Длина
//double L = 10.0;

//Электрическое поле
//double E0 = 1;


void Move(std::vector<double> V_ions, std::vector<double> V_el, std::vector<double> X_ions, std::vector<double> X_el){

	std::vector <double> E_vec;
	int num_ceil = L / dx + 1;
	for (int i = 0; i - 1 < num_ceil; i++) {
		E_vec.push_back(E0 * (i * dx - L / 2));
	}
	std::ofstream out_el;          // поток для записи
	out_el.open("data_el_10.txt");

	std::ofstream out_ions;          // поток для записи
	out_ions.open("data_ions_10.txt");
	for (double tim = 0.0; tim < T; tim += dt) {
		

		for (std::size_t i = 0; i < X_ions.size(); i++) {
			out_el << X_el[i] << " ";
			out_ions << X_ions[i] << " ";
			double N_ion_loc = X_ions[i] / dx;
			double N_el_loc = X_el[i] / dx;

			V_ions[i] += E(E_vec[N_ion_loc], E_vec[N_ion_loc + 1], X_ions[i]) * q / m_ion * dt;
			V_el[i] -= E(E_vec[N_el_loc], E_vec[N_el_loc + 1], X_el[i]) * q / m_el * dt;
			X_ions[i] += V_ions[i] * dt;
			X_el[i] += V_el[i] * dt;

			// Граничные условия
			if (X_ions[i] >= L) { X_ions[i] -= L; };
			if (X_ions[i] < 0) { X_ions[i] += L; };

			if (X_el[i] >= L) { X_el[i] -= L; };
			if (X_el[i] < 0) { X_el[i] += L; };
		}
		out_el << std::endl;
		out_ions << std::endl;
	}

	out_el.close();
	out_ions.close();

};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
