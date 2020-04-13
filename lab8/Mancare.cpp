#include "Mancare.h"
#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Mancare::Mancare():Comanda() {
}

Mancare::Mancare(vector<char*> preparate)
{
}

Mancare::Mancare(const Mancare& c)
{
}

//destructor
Mancare::~Mancare() {
}

//getter pentru nume
vector<char*> Mancare::getPreparate() {
	return this->preparate;
}

//suprascrie operatorul "=" pentru un element de tip Mancare
Mancare& Mancare::operator=(const Mancare& a) {
	if (this == &a) return *this; //self-assignment
	preparate = a.preparate;
	return *this;
}

//operatorul de egalitate
bool Mancare:: operator==(const Mancare& a) {
	return  this->preparate == a.preparate;
}

//pt afisare
ostream& operator<<(ostream& os, const Mancare& a)
{
	Comanda c;
	os << "Nume - " << c.getName() << ", adresa - " << c.getAdresa() << ", preparate - " << a.preparate << ", pret - " << c.getPret();
	return os;
}