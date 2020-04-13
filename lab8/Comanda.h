#pragma once
#include <ostream>
using namespace std;

class Comanda {
private:
	char* name;
	char* adresa;
	float pret;
public:
	Comanda();
	Comanda(const char* name, const char* adresa, float pret);
	Comanda(const Comanda& c);
	virtual ~Comanda();
	virtual char* getName();
	virtual char* getAdresa();
	virtual float getPret();
	virtual void setName(const char* name);
	virtual void setAdresa(const char* adresa);
	virtual void setPret(float pret);
	Comanda& operator=(const Comanda& c);
	bool operator==(const Comanda& c);
	friend ostream& operator<<(ostream& os, const Comanda& c);
};
