#pragma once
#include <vector>
#include "Constants.h"

void E(std::vector<double>& fi, std::vector<double>& E_vec) {
	E_vec[0] = (fi[0] - fi[1]) / dx;
	for (int i = 1; i + 1 < fi.size(); i++) {
		E_vec[i] = (fi[i - 1] - fi[i + 1]) / (2.0 * dx);
	}
	E_vec[E_vec.size() - 1] = (fi[fi.size() - 2] - fi[fi.size() - 1]) / dx;
}