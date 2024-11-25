#pragma once
#include <vector>
#include "Constants.h"

using std::vector;

void CIC(std::vector< double>& rho_ions, std::vector< double>& rho_el, std::vector<double>& X_ions, std::vector<double>& X_el) {

	for (std::size_t i = 0; i < X_ions.size(); i++) {
		
		int ceil_ion = X_ions[i] / dx;
		int ceil_el = X_el[i] / dx;

		double x_ion_loc = fmod(X_ions[i], dx * 1.0);
		double x_el_loc = fmod(X_el[i], dx * 1.0);

		rho_ions[ceil_ion] += q * (dx - x_ion_loc) / (dx * eps_0) ;
		rho_ions[ceil_ion + 1] += q * x_ion_loc / (dx * eps_0);

		rho_el[ceil_el] -= q * (dx - x_el_loc) / (dx * eps_0);
		rho_el[ceil_el + 1] -= q * x_el_loc / (dx * eps_0);

	}
	
	for (std::size_t i = 0; i < rho_el.size(); i++) {
		rho_el[i] *= (- n_2);
		rho_ions[i] *= (-n_2);
	}
	

}
