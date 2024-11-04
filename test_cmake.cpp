// test_cmake.cpp: определяет точку входа для приложения.
//

#include "Move.h"
#include <random>
#include <fstream>
#include "CIC.h"
#include "Fi.h"
#include "vectors.h"
//using namespace std;


int main(){
	
	// заполнение начальных координат электронов и ионов случайным образом
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
	//

	//векторы данных
	std::vector<double> E_vec;
	int num_ceil = L / dx + 1;

	for (int i = 0; i - 1 < num_ceil; i++) {
		E_vec.push_back(E_0 * (i * dx - L / 2));
	}

	std::vector<double> rho(num_ceil, 0.0);

	std::vector<double> p(rho.size() - 2, 0.0);
	std::vector<double> q(rho.size() - 2, 0.0);

	std::vector<int> n_el(num_ceil, 0);
	std::vector<int> n_ions(num_ceil, 0);

	std::vector <double>fi(num_ceil, 0.0);

	//
	std::ofstream data_ions;
	data_ions.open("ions.txt");

	std::ofstream data_el;
	data_el.open("el.txt");

	std::ofstream rho1;
	rho1.open("rho.txt");

	std::ofstream fi1;
	fi1.open("fi.txt");





	for (double time = dt; time < T; time += dt) {

		//двигаем заряды в "старых" полях
		Move(X_ions, X_el, V_ions, V_el, E_vec);

		//плотность заряда
		CIC(rho, X_ions, X_el);

		//потенциал
		Fi(fi, rho, p, q);

		//подсчет концентрации
		for (std::size_t i = 0; i < X_ions.size(); i++) {
			int ceil_ion = X_ions[i] / dx;
			int ceil_el = X_el[i] / dx;

			n_el[ceil_el] += 1;
			n_ions[ceil_ion] += 1;
		}

		//запись данных
		for (std::size_t p = 0; p < n_el.size(); p++) {
			data_el << n_el[p] << " ";
			data_ions << n_ions[p] << " ";
			rho1 << rho[p] << " ";
			fi1 << fi[p] << " ";

		}
		data_el << std::endl;
		data_ions << std::endl;
		rho1 << std::endl;
		fi1 << std::endl;

		//обнуление нужных векторов
		std::fill(fi.begin(), fi.end(), 0.0);
		std::fill(rho.begin(), rho.end(), 0.0);
		std::fill(n_el.begin(), n_el.end(), 0.0);
		std::fill(n_ions.begin(), n_ions.end(), 0.0);		

	}

	data_ions.close();
	data_el.close();
	rho1.close();
	fi1.close();
	
	/*
	std::ofstream fi1;
	fi1.open("fi.txt");

	std::ofstream rho1;
	rho1.open("rho.txt");
	

	std::vector <double>fi(21, 0.0);
	std::vector<long double> rho(21);
	for (std::size_t i = 0; i < rho.size(); i++) {
		rho[i] = sin(i * 2.0 / 10.0 * 3.14);
	}

	Fi(fi, rho);
	for (std::size_t i = 0; i < rho.size(); i++) {
		fi1 << i << " " << fi[i] << std::endl;
		rho1 << i << " " << rho[i] << std::endl;
	}
	fi1.close();
	rho1.close();
	*/
}
