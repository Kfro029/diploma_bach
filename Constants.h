#pragma once
#include<cmath>

double L = 0.02; // ������ ������������
int num_ceil = 1000; // ����� ��������
double dx = L / (num_ceil); // ��� �� �����

double T = 3.5e-9; // ����� �������
double dt = 1.0e-11; // ��� �� �������

//�������� ������������ 1e17
double n_2 = 4e11; // ������� ������ ���������� 1 �������

//����� ���� � ������������� ����������
int k = 4;


// int NX = L / dx; // � ����� ������ �������

double E_0 = 1.0 * pow(10, -12);

int N = num_ceil * 50; // ����� ������


double m_ion = 1.67 * pow(10, -27);
double m_el = 9.31 * pow(10, -31);
double q = 1.6 * pow(10, -19);

double eps_0 = 8.85e-12;












