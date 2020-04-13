#pragma once
#include <ostream>
#include "Comanda.h"
#include <vector>;
using namespace std;

class Shopping : public Comanda {
private:
	vector <char*> cumparaturi;
	char* magazin;
public:
	Shopping();
	Shopping(vector <char*> preparate, const char* magazin);
	Shopping(const Shopping& c);
	~Shopping();
	vector <char*> getCumparaturi();
	char* getMagazin();
	void setMagazin(const char*);
	Shopping& operator=(const Shopping& c);
	bool operator==(const Shopping& c);
	friend ostream& operator<<(ostream& os, const Shopping& c);
};
