// Cmake_dip.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#include <vector>
#include <cmath>
#include "E_f.h"

// Число частиц
int N = 10;

//Основные константы
double m_ion = 1.673 * pow(10, -27); 
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);


// шаг по времени и время
double dt = 0.1;
double T = 10.0;

//Длина
double L = 10.0;

//Электрическое поле
double E0 = 1;
double E0 = 1;
std::vector <double> E_vec;

void nothing2(){
	for (int i = 0; i - 1 < int(L / dx); i++) {
	E_vec.push_back(E0 * (i * dx - L / 2));
}

	void Move(std::vector<double> V_ions, std::vector<double> V_el, std::vector<double> X_ions, std::vector<double> X_el){
		for (double tim = 0.0; tim < T; tim += dt) {
			for (std::size_t i = 0; i < X_ions.size(); i++) {
				V_ions[i] += E(X_ions[i]) * q / m_ion * dt;
				V_el[i] -= E(X_el[i]) * q / m_el * dt;
				X_ions[i] += V_ions[i] * dt;
				X_el[i] += V_el[i] * dt;

			}
		}
	};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
