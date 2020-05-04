#include "Service.h"
#include "User.h"
#include "ValidareDate.h"
//#include "Exc.h"
#include<iostream>
using namespace std;


Service::Service()
{
}

Service::Service(Repo<Mancare>* repoMancare, Repo<Shopping>* repoShopping, Repo<User>* repoUseri)
{
	this->repoMancare = repoMancare;
	this->repoShopping = repoShopping;
	this->repoUser = repoUseri;
	User u1("Ana", "123");
	User u2("Ion", "1234");
	repoUser->add(u1);
	repoUser->add(u2);
}

bool Service::login(string u, string p)
{
	User usr(u, p);
	return repoUser->find(usr) != -1;
}

void Service::logout(string name, string pass)
{
	User u(name, pass);
	int pos = repoUser->find(u);
	repoUser->del(pos);
}

map<int, Mancare> Service::getAllMancare()
{
	return repoMancare->getAll();
}

map<int, Shopping> Service::getAllShopping()
{
	return repoShopping->getAll();
}

void Service::addMancare(Mancare& m)
{
	ValidareDate vd;
	try {
		vd.validareMancare(m);
		repoMancare->add(m);
		((Repo<Mancare>*)repoMancare)->saveToFile();
	}
	catch (exception& exc) {
		cout << "Exceptie: " << exc.what() << endl;
	}
}

void Service::addShopping(Shopping& sho)
{
	ValidareDate vd;
	try {
		vd.validareShopping(sho);

		repoShopping->add(sho);
		((Repo<Shopping>*)repoShopping)->saveToFile();
	}
	catch (exception & exc) {
		cout << "Exceptie: " << exc.what() << endl;
	}
}

map<int, Mancare> Service::mancareDupaNumeClient(string nume)
{
	int contor = 0;
	map<int, Mancare> rez;
	map<int, Mancare> cm = repoMancare->getAll();
	map<int, Mancare>::iterator itr;
	for (itr = cm.begin(); itr != cm.end(); ++itr) {
		if (itr->second.getNumeClient().compare(nume)==0) {
			rez.insert(pair<int, Mancare>(contor++, itr->second));
		}
	}
	return rez;
}

map<int, Shopping> Service::shoppingDupaNumeClient(string nume)
{
	int contor = 0;
	map<int, Shopping> rez;
	map<int, Shopping> cm = repoShopping->getAll();
	map<int, Shopping>::iterator itr;
	for (itr = cm.begin(); itr != cm.end(); ++itr) {
		if (itr->second.getNumeClient().compare(nume) == 0) {
			rez.insert(pair<int, Shopping>(contor++, itr->second));
		}
	}
	return rez;
}

Service::~Service()
{
}