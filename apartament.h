#pragma once
#include <iostream>

class Apartament {

private:

	int nr_camere;
	double *suprafete;

	const int an_constructie;

	char *localitate;

	double pret;

public:

	Apartament();
	Apartament(const Apartament &a);
	Apartament(int an_constructie, char * localitate, double pret, int nr_camere, double *suprafete);


	Apartament & operator=(const Apartament& a);

	Apartament & operator++(int);

	friend Apartament & operator+(const Apartament& a, int i);
	friend int operator<(const Apartament& a1, const Apartament& a2);
	friend int operator>(const Apartament& a1, const Apartament& a2);


	friend std::ostream & operator<<(std::ostream& os, const Apartament& a);

	friend std::istream & operator>>(std::istream& is, Apartament& a);

	operator double()const;


	int get_AnConstr();
	double * getVectSupr();
	char * getLocalitate();
	int getNrCamere();
	double getPret();


	void setVectorSupr(double *vect, int cam);
	void setLocalitate(char * loc);

	double suprTotal();

	//~Apartament();

};


class ApartamentSocial : public Apartament{

private:
	char * locatar;
	int chirie;

public:

	ApartamentSocial(int an_constructie, char * localitate, double pret, int nr_camere, double *suprafete, char* locatar, double chirie);

	friend std::ostream & operator<<(std::ostream& os, ApartamentSocial &a);

	//~ApartamentSocial();

};
