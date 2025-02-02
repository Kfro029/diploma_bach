// test_cmake.cpp: определяет точку входа для приложения.
//

#include "Move.h"
#include <random>
#include <fstream>
#include "CIC.h"
#include "Fi.h"
#include "E.h"
#include "SETV.h"
//using namespace std;


int main(){
	
	std::vector<double> X_ions(N, 0.0);
	std::vector<double> X_el(N, 0.0);


	std::vector<double> V_ions(N, 0.0);
	std::vector<double> V_el(N, 0.0);



	for (std::size_t i = 0; i < X_ions.size(); i++) {
		X_ions[i] = (i * 1.0) / X_ions.size() * L;
		X_el[i] = (i * 1.0) / X_el.size() * L;
	}
	for (std::size_t i = 0; i < X_el.size(); i++) {
		X_el[i] += 0.0005 * L * sin(X_el[i] / L * 2 * 3.1415926536 * k);
	}

	//

	//векторы данных
	std::vector<double> E_vec(num_ceil, 0.0);

	std::vector<double> rho_ions(num_ceil, 0.0);
	std::vector<double> rho_el(num_ceil, 0.0);
	std::vector<double> rho(num_ceil, 0.0);

	std::vector<double> p(num_ceil- 2, 0.0);
	std::vector<double> q(num_ceil - 2, 0.0);

	std::vector <double>fi(num_ceil, 0.0);

	

	//подсчет правой части уравнения Пуассона
	CIC(rho_ions, rho_el, X_ions, X_el);


	Fi(fi, rho_ions, rho_el, rho, p, q);
	E(fi, E_vec);


	
	SETV(X_ions, X_el, V_ions, V_el, E_vec); //шаг на -dt/2
	//обнуление нужных векторов
	std::fill(fi.begin(), fi.end(), 0.0);
	std::fill(rho.begin(), rho.end(), 0.0);
	std::fill(rho_ions.begin(), rho_ions.end(), 0.0);
	std::fill(rho_el.begin(), rho_el.end(), 0.0);

	//новый подсчет плотностей и зарядов
	CIC(rho_ions, rho_el, X_ions, X_el);


	Fi(fi, rho_ions, rho_el, rho, p, q);
	E(fi, E_vec);
	
	//

	std::ofstream rho_ions1;
	rho_ions1.open("rho_ions.txt");

	std::ofstream rho_el1;
	rho_el1.open("rho_el.txt");

	std::ofstream fi1;
	fi1.open("fi.txt");

	for (std::size_t p = 0; p < rho_el.size(); p++) {
		
		rho_ions1 << rho_ions[p] << " ";
		rho_el1 << rho_el[p] << " ";
		fi1 << fi[p] << " ";

	}

	rho_ions1 << std::endl;
	rho_el1 << std::endl;
	fi1 << std::endl;




	for (int i = 1; i <= (T / dt); i++) {

		//двигаем заряды в "старых" полях
		Move(X_ions, X_el, V_ions, V_el, E_vec);

		//обнуление нужных векторов
		std::fill(fi.begin(), fi.end(), 0.0);
		std::fill(rho.begin(), rho.end(), 0.0);
		std::fill(rho_ions.begin(), rho_ions.end(), 0.0);
		std::fill(rho_el.begin(), rho_el.end(), 0.0);

		//правая часть уравнения Пуассона
		CIC(rho_ions, rho_el, X_ions, X_el);

		//потенциал (в вольтах)
		Fi(fi, rho_ions, rho_el, rho, p, q);

		//подсчет электрического поля
		E(fi, E_vec);

		if (i % 1 == 0) {
			//запись данных
			for (std::size_t p = 0; p < rho_ions.size(); p++) {
				rho_ions1 << rho_ions[p] << " ";
				rho_el1 << rho_el[p] << " ";
				fi1 << fi[p] << " ";
				

			}
			rho_ions1 << std::endl;
			rho_el1 << std::endl;
			fi1 << std::endl;

			std::cout << "Zapis' i = " << i << std::endl;
		}
		

	}

	rho_ions1.close();
	rho_el1.close();
	fi1.close();

}
