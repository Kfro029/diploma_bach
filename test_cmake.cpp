// test_cmake.cpp: определяет точку входа для приложения.
//

#include "Move.h"
#include <random>
#include <fstream>
#include "CIC.h"
#include "Fi.h"
#include "E.h"

//using namespace std;


int main(){
	
	std::vector<double> X_ions(N, 0.0);
	std::vector<double> X_el(N, 0.0);


	std::vector<double> V_ions(N, 0.0);
	std::vector<double> V_el(N, 0.0);



	// заполнение начальных координат электронов и ионов случайным образом
	/*
	double lower_bound = 0.0;
	double upper_bound = L;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;

	for (int i = 0; i < N; i++) {
		double a = unif(re);
		X_ions[i] = a;
	}

	for (int i = 0; i < N; i++) {
		double b = unif(re);
		X_el[i] = b;
	}
	*/


	

	for (int i = 0; i < N; i++) {
		X_ions[i] = (i * 1.0) / N * L;
		X_el[i] = (i * 1.0) / N * L;
	}
	for (int i = 0; i < N; i++) {
		X_el[i] += 0.0005 * L * sin(X_el[i] / L * 2 * 3.1415926536 * k);
	}

	//

	//векторы данных
	std::vector<double> E_vec(num_ceil + 1, 0.0);

	std::vector<double> rho_ions(num_ceil + 1, 0.0);
	std::vector<double> rho_el(num_ceil + 1, 0.0);
	std::vector<double> rho(num_ceil + 1, 0.0);

	std::vector<double> p(num_ceil- 1, 0.0);
	std::vector<double> q(num_ceil - 1, 0.0);

	std::vector<int> n_el(num_ceil + 1, 0);
	std::vector<int> n_ions(num_ceil + 1, 0);

	std::vector <double>fi(num_ceil + 1, 0.0);

	/*
	//проверим метод прогонки
	for (int i = 0; i < num_ceil + 1; i++) {
		rho_el[i] = 10 * sin(i / (num_ceil * 1.0) * 2 * 3.1415926536 * k);
	}
	Fi(fi, rho_ions, rho_el, rho, p, q);

	std::ofstream fi3;
	fi3.open("fi.txt");

	std::ofstream fi2;
	fi2.open("rho.txt");

	for (std::size_t i = 0; i < fi.size(); i++) {
		fi3 << fi[i] << " ";
		fi2 << rho_el[i] << " ";
	}
	fi3.close();
	fi2.close();
	return 0;
	*/

	//подсчет плотности заряда и полей
	CIC(rho_ions, rho_el, X_ions, X_el);
	Fi(fi, rho_ions, rho_el, rho, p, q);
	E(fi, E_vec);

	//
	std::ofstream data_ions;
	data_ions.open("ions.txt");

	std::ofstream data_el;
	data_el.open("el.txt");

	std::ofstream rho_ions1;
	rho_ions1.open("rho_ions.txt");

	std::ofstream rho_el1;
	rho_el1.open("rho_el.txt");

	std::ofstream n_el1;
	n_el1.open("n_el.txt");

	std::ofstream n_ions1;
	n_ions1.open("n_ions.txt");

	std::ofstream fi1;
	fi1.open("fi.txt");

	for (std::size_t p = 0; p < n_el.size(); p++) {
		data_el << n_el[p] << " ";
		data_ions << n_ions[p] << " ";
		rho_ions1 << rho_ions[p] << " ";
		rho_el1 << rho_el[p] << " ";
		fi1 << fi[p] << " ";

	}

	data_el << std::endl;
	data_ions << std::endl;
	rho_ions1 << std::endl;
	rho_el1 << std::endl;
	fi1 << std::endl;




	for (int i = 1; i < (T / dt); i++) {

		//двигаем заряды в "старых" полях
		Move(X_ions, X_el, V_ions, V_el, E_vec);

		//обнуление нужных векторов
		std::fill(fi.begin(), fi.end(), 0.0);
		std::fill(rho.begin(), rho.end(), 0.0);
		std::fill(rho_ions.begin(), rho_ions.end(), 0.0);
		std::fill(rho_el.begin(), rho_el.end(), 0.0);
		std::fill(n_el.begin(), n_el.end(), 0.0);
		std::fill(n_ions.begin(), n_ions.end(), 0.0);

		//плотность заряда (в Кл/(м^3 * eps_0 * (-1)))
		CIC(rho_ions, rho_el, X_ions, X_el);

		//потенциал (в вольтах)
		Fi(fi, rho_ions, rho_el, rho, p, q);

		//подсчет электрического поля
		E(fi, E_vec);

		//подсчет концентрации
		for (std::size_t p = 0; p < X_ions.size(); p++) {
			int ceil_ion = X_ions[p] / dx;
			int ceil_el = X_el[p] / dx;

			n_el[ceil_el] += 1;
			n_ions[ceil_ion] += 1;
		}
		
		
			//запись данных
			for (std::size_t p = 0; p < num_ceil + 1; p++) {
				data_el << n_el[p] << " ";
				data_ions << n_ions[p] << " ";
				rho_ions1 << rho_ions[p] << " ";
				rho_el1 << rho_el[p] << " ";
				fi1 << fi[p] << " ";
				n_ions1 << n_ions[p] << " ";
				n_el1 << n_el[p] << " ";

			}
			data_el << std::endl;
			data_ions << std::endl;
			rho_ions1 << std::endl;
			rho_el1 << std::endl;
			fi1 << std::endl;
			n_ions1 << std::endl;
			n_el1 << std::endl;

		

	}

	data_ions.close();
	data_el.close();
	rho_ions1.close();
	rho_el1.close();
	fi1.close();
	n_ions1.close();
	n_el1.close();
	
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
