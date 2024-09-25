// Cmake_dip.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <vector>
#include "Cmake_dip.h" 

// Число частиц
int N = 10;


int main(){

	std::vector<float> X_ions;
	std::vector<float> X_el;
	std::vector<float> V_ions (N, 0.0);
	std::vector<float> V_el(N, 0.0);

	double E0 = 1;
	std::vector <double> E_vec;

	for (int i = 0; i - 1 < int(L / dx); i++) {
		E_vec.push_back(E0 * (i * dx - L / 2));
	}

	for (int i = 0; i < N; i++) {
		int L_int = L;
		X_ions.push_back(rand() % (L_int+1));
		X_el.push_back(rand() % (L_int + 1));
	}

	
}
