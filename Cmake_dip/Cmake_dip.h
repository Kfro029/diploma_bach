// Cmake_dip.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#include <vector>
#include <cmath>
#include "E_f.h"
#include <fstream>

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
//double L = 10.0;

//Электрическое поле
//double E0 = 1;


void Move(std::vector<float> V_ions, std::vector<float> V_el, std::vector<float> X_ions, std::vector<float> X_el){
	std::ofstream out_el;          // поток для записи
	out_el.open("data_el_10.txt");

	std::ofstream out_ions;          // поток для записи
	out_ions.open("data_ions_10.txt");
	for (float tim = 0.0; tim < T; tim += dt) {
		

		for (std::size_t i = 0; i < X_ions.size(); i++) {
			out_el << X_el[i] << " ";
			out_ions << X_ions[i] << " ";

			V_ions[i] += E(X_ions[i]) * q / m_ion * dt;
			V_el[i] -= E(X_el[i]) * q / m_el * dt;
			X_ions[i] += V_ions[i] * dt;
			X_el[i] += V_el[i] * dt;

			//проверка на нормальность координаты
			if (X_ions[i] >= L) { X_ions[i] -= L; };
			if (X_ions[i] < 0) { X_ions[i] += L; };

			if (X_el[i] >= L) { X_el[i] -= L; };
			if (X_el[i] < 0) { X_el[i] += L; };
		}
		out_el << std::endl;
		out_ions << std::endl;
	}
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
