#pragma once
#include<cmath>

double L = 10.0; // ������ ������������
double dx = 0.1; // ��� �� �����

double T = 10.0; // ����� �������
double dt = 0.1; // ��� �� �������

int num_ceil = L / dx + 1; // ������ �����


int NX = L / dx; // � ����� ������ �������

double E_0 = pow(10, -12);

int N = 1000; // ����� ������


double m_ion = 1.67 * pow(10, -27);
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);

