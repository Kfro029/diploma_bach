// test_cmake.cpp: определяет точку входа для приложения.
//

#include "Move.h"
#include <random>
#include <fstream>
//using namespace std;

double T = 10.0;

int main()
{
	std::vector<double> X_ions;
	std::vector<double> X_el;

	std::vector<double> V_ions(N, 0.0);
	std::vector<double> V_el(N, 0.0);

	double lower_bound = 0.0;
	double upper_bound = L;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;

	for (int i = 0; i < N; i++) {
		double a = unif(re);
		X_ions.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		double b = unif(re);
		X_el.push_back(b);
	}

	std::ofstream data_ions;
	data_ions.open("ions.txt");

	std::ofstream data_el;
	data_el.open("el.txt");



	for (double time = dt; time < T; time += dt) {
		Move(X_ions, X_el, V_ions, V_el);

		//подсчет концентрации
		std::vector<int> n_el(num_ceil, 0);
		std::vector<int> n_ions(num_ceil, 0);
		for (std::size_t i = 0; i < X_ions.size(); i++) {
			int ceil_ion = X_ions[i] / dx;
			int ceil_el = X_el[i] / dx;

			n_el[ceil_el] += 1;
			n_ions[ceil_ion] += 1;
		}
		for (std::size_t p = 0; p < n_el.size(); p++) {
			data_el << n_el[p] << " ";
			data_ions << n_ions[p] << " ";

		}
		data_el << std::endl;
		data_ions << std::endl;
	}

	data_ions.close();
	data_el.close();

}
