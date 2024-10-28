#pragma once
#include <vector>
#include "Constants.h"

using std::vector;

void CIC(std::vector< long double>& rho, std::vector<double>& X_ions, std::vector<double>& X_el) {

	for (std::size_t i = 0; i < X_ions.size(); i++) {
		
		int ceil_ion = X_ions[i] / dx;
		int ceil_el = X_el[i] / dx;

		double x_ion_loc = fmod(X_ions[i], dx * 1.0);
		double x_el_loc = fmod(X_el[i], dx * 1.0);

		rho[ceil_ion] += q * (dx - x_ion_loc) / dx;
		rho[ceil_ion + 1] += q * x_ion_loc / dx;

		rho[ceil_el] -= q * (dx - x_el_loc) / dx;
		rho[ceil_el] -= q * x_el_loc / dx;

	}

}
