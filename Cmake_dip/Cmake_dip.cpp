// Cmake_dip.cpp: определяет точку входа для приложения.
//

#include "Cmake_dip.h" 


/*
double E(double x) {
	return (E0 * (x - L / 2));
}
*/

int main(){

	std::vector<double> X_ions;
	std::vector<double> X_el;
	std::vector<double> V_ions (N, 0.0);
	std::vector<double> V_el(N, 0.0);


	for (int i = 0; i < N; i++) {
		int L_int = L;
		X_ions.push_back(rand() % (L_int+1));
		X_el.push_back(rand() % (L_int + 1));
	}

	Move(V_ions, V_el, X_ions, X_el);

	
}
