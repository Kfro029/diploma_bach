#pragma once

double dx = 0.1;

double E(double E1, double E2, double x) {
	return(E1 * x + E2 * (dx - x)) / dx;
}
