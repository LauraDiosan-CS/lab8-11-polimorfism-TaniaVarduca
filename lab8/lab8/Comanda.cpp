#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Comanda::Comanda() {
	this->name = NULL;
	this->adresa = NULL;
	this->pret = NULL;
}

//constructor cu param
Comanda::Comanda(const char* name, const char* adresa, float pret)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, 1 + strlen(adresa), adresa);
	this->pret = pret;
}

//constructor de copiere
Comanda::Comanda(const Comanda& a) {
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(this->name, 1 + strlen(a.name), a.name);
	}
	if (a.adresa) {
		this->adresa = new char[strlen(a.adresa) + 1];
		strcpy_s(this->adresa, 1 + strlen(a.adresa), a.adresa);
	}
	this->pret = a.pret;
}

//destructor
Comanda::~Comanda() {
	if (name) delete[]name;
	name = NULL;
	adresa = NULL;
	pret = -1;
}

//getter pentru nume
char* Comanda::getName() {
	return this->name;
}

//getter pentru adresa
char* Comanda::getAdresa() {
	return this->adresa;
}

//getter pentru statusul nou
float Comanda::getPret() {
	return this->pret;
}

//setter pentru nume
void Comanda::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

//setter pentru adresa
void Comanda::setAdresa(const char* adresa)
{
	if (this->adresa) {
		delete[] this->adresa;
	}
	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
}

//setter pentru statusul nou
void Comanda::setPret(float pret)
{
	this->pret = pret;
}

//suprascrie operatorul "=" pentru un element de tip Comanda
Comanda& Comanda::operator=(const Comanda& a) {
	if (this == &a) return *this; //self-assignment
	if (name) delete[] name;
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
	}
	pret = a.pret;
	if (adresa) delete[] adresa;
	if (a.adresa) {
		this->adresa = new char[strlen(a.adresa) + 1];
		strcpy_s(adresa, strlen(a.adresa) + 1, a.adresa);
	}
	return *this;
}

//operatorul de egalitate
bool Comanda:: operator==(const Comanda& a) {
	return strcmp(this->name, a.name) == 0  && strcmp(this->adresa, a.adresa) == 0 && this->pret == a.pret;
}

//pt afisare
ostream& operator<<(ostream& os, const Comanda& a)
{
	os << "Nume - " << a.name << ", adresa - " << a.adresa << ", pret - " << a.pret;
	return os;
}