#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

#include "apartament.h"

using namespace std;

void main() {

	double vect_supr1[3] = { 24.3, 33.1, 22.8 };

	Apartament a1;
	Apartament a2(1978, "Bucuresti", 70000.0, 3, vect_supr1);

	cout << a1.get_AnConstr() << endl;

	a2.setLocalitate("Cluj");

	cout << a2.getVectSupr()[1] << endl;

	double vect_supr2[3] = { 30.3, 22.1, 48.0 };

	a2.setVectorSupr(vect_supr2, 3);

	Apartament a3 = a2;
	Apartament a4;

	a4 = a3;

	cout << "a1: \n" << a1 << "a2: \n" << a2 << "a3: \n" << a3 << "a4: \n" << a4;

	a3 = a3 + 1000; 
	cout << a3;

	a3++;
	cout << a3;
	cout << "suprafata totala a apartamentului este: " << a3.suprTotal() << endl;

	if (a3 > a2) cout << "Apartamentul a3 este mai scump ca a2" << endl;
	else if (a3 < a2) cout << "Apartamentul a3 este mai ieftin ca a2" << endl;
	else cout << "Apartamentele au acelasi pret" << endl;

	ofstream fisierOut("iesire.txt");

	fisierOut << a4;

	fisierOut.close();

	ifstream fisIn("intrare.txt", ios::in);

	fisIn >> a4;
	cout << a4;
	fisIn.close();

	cout << "Suprafata medie a4: " << (double)a4 << endl << endl;

	double vect_supr3[2] = { 68.5, 57.1};

	ApartamentSocial aps1(1999, "Bucuresti", 57000.1, 2, vect_supr3, "Popescu Ion", 750.0);

	cout << aps1 << endl;

	vector<Apartament> bloc;
	bloc.push_back(a1);
	bloc.push_back(a2);
	bloc.push_back(a3);
	bloc.push_back(a4);
	bloc.push_back(aps1);
	int i = 1;
	for (vector<Apartament>::iterator it = bloc.begin(); it != bloc.end(); ++it) {
		cout << "Apartamentul " << i << " are urmatoarele proprietati: " << endl;
		cout << *(it) << endl;	
		i++;
	}

	_getch();

}
