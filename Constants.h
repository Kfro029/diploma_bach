#pragma once
#include<cmath>

double L = 0.02; // размер пространства
int num_ceil = 1000; // число пролетов
double dx = L / (num_ceil); // шаг по сетке

double T = 3.5e-9; // всего времени
double dt = 1.0e-11; // шаг по времени

//Желаемая концентрация 1e17
double n_2 = 4e11; // сколько частиц моделирует 1 частица

//число волн в распределении электронов
int k = 4;


// int NX = L / dx; // в какой ячейке частица

double E_0 = 1.0 * pow(10, -12);

int N = num_ceil * 50; // число частиц


double m_ion = 1.67 * pow(10, -27);
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);

double eps_0 = 8.85e-12;












