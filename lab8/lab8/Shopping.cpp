#include "Shopping.h"
#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Shopping::Shopping():Comanda() {
	this->magazin = NULL;
}

//constructor cu param
Shopping::Shopping(vector<char*> cumparaturi, const char* magazin):Comanda()
{
	this->magazin = new char[strlen(magazin) + 1];
	strcpy_s(this->magazin, 1 + strlen(magazin), magazin);
}

//constructor de copiere
Shopping::Shopping(const Shopping& a) {
	if (a.magazin) {
		this->magazin = new char[strlen(a.magazin) + 1];
		strcpy_s(this->magazin, 1 + strlen(a.magazin), a.magazin);
	}
}

//destructor
Shopping::~Shopping() {
	if (magazin) delete[]magazin;
	magazin = NULL;
}

//getter pentru nume
char* Shopping::getMagazin() {
	return this->magazin;
}

vector<char*> Shopping::getCumparaturi() {
	return this->cumparaturi;
}


//setter pentru nume
void Shopping::setMagazin(const char* magazin)
{
	if (this->magazin) {
		delete[] this->magazin;
	}
	this->magazin = new char[strlen(magazin) + 1];
	strcpy_s(this->magazin, strlen(magazin) + 1, magazin);
}

//suprascrie operatorul "=" pentru un element de tip Shopping
Shopping& Shopping::operator=(const Shopping& a) {
	if (this == &a) return *this; //self-assignment
	if (magazin) delete[] magazin;
	if (a.magazin) {
		this->magazin = new char[strlen(a.magazin) + 1];
		strcpy_s(magazin, strlen(a.magazin) + 1, a.magazin);
	}
	cumparaturi = a.cumparaturi;
	return *this;
}

//operatorul de egalitate
bool Shopping:: operator==(const Shopping& a) {
	return this->cumparaturi == a.cumparaturi && strcmp(this->magazin, a.magazin) == 0;
}

//pt afisare
ostream& operator<<(ostream& os, const Shopping& a)
{
	Comanda c;
	os << "Nume - " << c.getName() << ", adresa - " << c.getAdresa() << ", pret - " << c.getPret()<<", magazin - "<<a.magazin;
	return os;
}