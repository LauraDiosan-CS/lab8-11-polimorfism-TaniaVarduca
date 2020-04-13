#pragma once
#include <ostream>
#include "Comanda.h"
#include <vector>;
using namespace std;

class Mancare: public Comanda {
private:
	vector <char*> preparate;
public:
	Mancare();
	Mancare(vector <char*> preparate);
	Mancare(const Mancare& c);
    ~Mancare();
	vector <char*> getPreparate();
	Mancare& operator=(const Mancare& c);
	bool operator==(const Mancare& c);
	friend ostream& operator<<(ostream& os, const Mancare& c);
};
