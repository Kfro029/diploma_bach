#pragma once
#include "Constants.h"

double E_for(double E1, double E2, double x) {
	return(E1 * x + E2 * (dx - x)) / dx;
}
