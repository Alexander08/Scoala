#include <string.h>
#include "apartament.h"

Apartament::Apartament(): an_constructie(2000)
{
	this->nr_camere = 0;

	this->localitate = new char[strlen("Bucuresti") + 1];
	strcpy(this->localitate, "Bucuresti");

	this->pret = 0.0;

	this->suprafete = new double[1];
}

Apartament::Apartament(const Apartament & a) : an_constructie(a.an_constructie)
{
	this->nr_camere = a.nr_camere;

	this->localitate = new char[strlen(a.localitate) + 1];
	strcpy(this->localitate, a.localitate);

	this->pret = a.pret;

	this->suprafete = new double[this->nr_camere];
	for (short int i = 0; i < this->nr_camere; i++) {

		this->suprafete[i] = a.suprafete[i];
	}
}

Apartament::Apartament(int an_constructie, char * localitate, double pret, int nr_camere, double * suprafete) : an_constructie(an_constructie)
{
	this->nr_camere = nr_camere;

	this->localitate = new char[strlen(localitate) + 1];
	strcpy(this->localitate, localitate);

	this->pret = pret;

	this->suprafete = new double[this->nr_camere];
	for (short int i = 0; i < this->nr_camere; i++) {
	
		this->suprafete[i] = suprafete[i];
	}
}

Apartament & Apartament::operator=(const Apartament & a)
{
	*( ( int* ) ( &this->an_constructie ) ) = a.an_constructie;

	this->nr_camere = a.nr_camere;
	this->localitate = new char[strlen(a.localitate) + 1];
	strcpy(this->localitate, a.localitate);

	this->pret = a.pret;

	this->suprafete = new double[this->nr_camere];
	for (short int i = 0; i < this->nr_camere; i++) {

		this->suprafete[i] = a.suprafete[i];
	}
	return *this;
}

Apartament & Apartament::operator++(int)
{
	*( (int*) ( &this->an_constructie ) ) = this->an_constructie + 1;

	return *this;
}

Apartament::operator double() const
{
	double sum = 0.0;
	for (short int i = 0; i < this->nr_camere; i++)
		sum += this->suprafete[i];
	return sum / (double)this->nr_camere;
}

int Apartament::get_AnConstr()
{
	return this->an_constructie;
}

double * Apartament::getVectSupr()
{
	return this->suprafete;
}

char * Apartament::getLocalitate()
{
	return this->localitate;
}

int Apartament::getNrCamere()
{
	return this->nr_camere;
}

double Apartament::getPret()
{
	return this->pret;
}

void Apartament::setVectorSupr(double * vect, int cam)
{
	this->nr_camere = cam;
	for (short int i = 0; i < this->nr_camere; i++) {

		this->suprafete[i] = vect[i];
	}

}

void Apartament::setLocalitate(char * loc)
{
	this->localitate = new char[strlen(loc) + 1];
	strcpy(this->localitate, loc);
}

double Apartament::suprTotal()
{
	double sum = 0.0;
	for (short int i = 0; i < this->nr_camere; i++)
		sum += this->suprafete[i];
	
	return sum;
}

//Apartament::~Apartament()
//{
//	if(this->suprafete != NULL)
//		delete[] this->suprafete;
//	
//	if (this->localitate != NULL)
//		delete[] this->localitate;
//}

Apartament & operator+(const Apartament & a, int i)
{
	Apartament * aux = new Apartament(a);
	aux->pret += i;

	return *aux;
}

int operator<(const Apartament & a1, const Apartament & a2)
{
	return a1.pret < a2.pret ? 1 : 0;
}

int operator>(const Apartament & a1, const Apartament & a2)
{
	return a1.pret > a2.pret ? 1 : 0;
}

std::ostream & operator<<(std::ostream & os, const Apartament &a)
{
	os << "An constructie: " << a.an_constructie << std::endl;
	os << "Localitate: " << a.localitate << std::endl;
	os << "Nr camere: " << a.nr_camere << std::endl;
	os << "Suprafetele camerelor sunt:" << std::endl;
	for (short int i = 0; i < a.nr_camere; i++) {
	
		os << "camera " << i +1 << ": " << a.suprafete[i] << "\t";
	}
	os << std::endl <<"Pret: " << a.pret << std::endl << std::endl;

	return os;
}

std::istream & operator>>(std::istream & is, Apartament& a)
{
	int aux;
	is >> aux;
	*((int*)(&a.an_constructie)) = aux;
	is >> a.localitate;
	is >> a.nr_camere;
	for (short int i = 0; i < a.nr_camere; i++)
		is >> a.suprafete[i];
	is >> a.pret;

	return is;
}

std::ostream & operator<<(std::ostream & os, ApartamentSocial &a)
{

	os << "Proprietarul: " << a.locatar << std::endl;
	os << "Chirie: " << a.chirie << std::endl;
	os << "An constructie: " << a.get_AnConstr() << std::endl;
	os << "Localitate: " << a.getLocalitate() << std::endl;
	os << "Nr camere: " << a.getNrCamere() << std::endl;
	os << "Suprafetele camerelor sunt:" << std::endl;
	for (short int i = 0; i < a.getNrCamere(); i++) {

		os << "camera " << i + 1 << ": " << a.getVectSupr()[i] << "\t";
	}
	os << std::endl << "Pret: " << a.getPret() << std::endl << std::endl;

	return os;
}

ApartamentSocial::ApartamentSocial(int an_constructie, char * localitate, double pret, int nr_camere, double * suprafete, char * locatar, double chirie): Apartament(an_constructie,localitate,pret,nr_camere,suprafete)
{
	this->locatar = new char[strlen(locatar) + 1];
	strcpy(this->locatar, locatar);

	this->chirie = (int)chirie;
}

//ApartamentSocial::~ApartamentSocial()
//{
//	if (this->locatar != NULL)
//			delete[] this->locatar;
//}
