#pragma once
#include<cmath>

double L = 10.0; // размер пространства
double dx = 0.1; // шаг по сетке

double T = 10.0; // всего времени
double dt = 0.1; // шаг по времени

int num_ceil = L / dx + 1; // чилсло ячеек


int NX = L / dx; // в какой ячейке частица

double E_0 = pow(10, -12);

int N = 1000; // числл частиц


double m_ion = 1.67 * pow(10, -27);
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);

