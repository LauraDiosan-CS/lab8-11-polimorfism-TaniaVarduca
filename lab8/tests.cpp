#include "tests.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "RepoCSV.h"
#include "RepoCostum.h"
#include "ValidareDate.h"
#include <assert.h>
#include <iostream>

//teste entitati
void testeEntitati() {

	//mancare
	Mancare m1; //constructor implicit
	assert((m1.getListaPreparate() == "") && (m1.getNumeClient() == "") && (m1.getAdresaClient() == "") && (m1.getPretTotal() == 0));
	Mancare m2("nume1", "str.X,nr.8", "supa,cartofi", 20); //constructor cu param
	assert((m2.getNumeClient().compare("nume1") == 0) && (m2.getAdresaClient().compare("str.X,nr.8") == 0) && m2.getPretTotal() == 20 && (m2.getListaPreparate().compare("supa,cartofi") == 0));
	Mancare m3(m2); //constructor de copiere
	assert(m3 == m2);

	//shopping
	Shopping s1; //constructor implicit
	assert((s1.getListaCumparaturi() == "") && s1.getNumeClient() == "" && (s1.getAdresaClient() == "") && (s1.getPretTotal() == 0) && s1.getNumeMagazin() == "");
	Shopping s2("nume2", "str.X,nr.8", "crema,parfum", 110, "maga"); //constructor cu param
	assert((s2.getNumeClient().compare("nume2") == 0) && (s2.getAdresaClient().compare("str.X,nr.8") == 0) && s2.getPretTotal() == 110 && (s2.getListaCumparaturi().compare("crema,parfum") == 0) && (s2.getNumeMagazin().compare("maga") == 0));
	Shopping s3(s2); //constructor de copiere
	assert(s3 == s2);

	//set, get
	m1.setNumeClient("nume"); m1.setAdresaClient("stradaNoua"); m1.setPretTotal(100); m1.setListaPreparate("abc");
	assert((m1.getNumeClient().compare("nume") == 0) && (m1.getAdresaClient().compare("stradaNoua") == 0) && m1.getPretTotal() == 100 && (m1.getListaPreparate().compare("abc") == 0));
	
	s1.setNumeClient("nume1"); s1.setAdresaClient("stradaN"); s1.setPretTotal(400); s1.setListaCumparaturi("xyz"); s1.setNumeMagazin("maga1");
	assert((s1.getNumeClient().compare("nume1") == 0) && (s1.getAdresaClient().compare("stradaN") == 0) && s1.getPretTotal() == 400 && (s1.getListaCumparaturi().compare("xyz") == 0) && (s1.getNumeMagazin().compare("maga1") == 0));
}

void repoCSVtests() {

	//mancare
	RepoCSV<Mancare>* repoMancare = new RepoCSV<Mancare>("mancare.csv");
	((RepoCSV<Mancare>*)repoMancare)->loadFromFile();
	assert(repoMancare->size() == 2);
	Mancare m1("mancare1", "str.X,nr.1", "pui,cartofi", 50);
	repoMancare->add(m1);
	((RepoCSV<Mancare>*)repoMancare)->saveToFile();
	assert(repoMancare->size() == 3);
	Mancare m2("mancare2", "str.X,nr.2", "pui,salata", 30);
	//repoMancare->update(m1, m2);
	assert(repoMancare->getAll().at(2) == m1);
	assert(repoMancare->find(m1) == 2);
	repoMancare->del(2);
	assert(repoMancare->size() == 2);
	assert(repoMancare->find(m1) == -1);
	((RepoCSV<Mancare>*)repoMancare)->saveToFile();

	//shopping
	RepoCSV<Shopping>* repoShopping = new RepoCSV<Shopping>("shopping.csv");
	((RepoCSV<Shopping>*)repoShopping)->loadFromFile();
	assert(repoShopping->size() == 2);
	Shopping s1("shopping1", "str.X,nr.1", "haine,pantofi", 500, "h&m");
	repoShopping->add(s1);
	((RepoCSV<Shopping>*)repoShopping)->saveToFile();
	assert(repoShopping->size() == 3);
	Shopping s2("shopping2", "str.X,nr.2", "curea,jucarie", 300, "zara");
	//repoMancare->update(m1, m2);
	assert(repoShopping->getAll().at(2) == s1);
	assert(repoShopping->find(s1) == 2);
	repoShopping->del(2);
	assert(repoShopping->size() == 2);
	assert(repoShopping->find(s1) == -1);
	((RepoCSV<Shopping>*)repoShopping)->saveToFile();
}

void repoCostumTests() {

	//mancare
	RepoCostum<Mancare>* repoMancare = new RepoCostum<Mancare>("mancare.txt");
	((RepoCostum<Mancare>*)repoMancare)->loadFromFile();
	assert(repoMancare->size() == 2);
	Mancare m1("mancare1", "str.X,nr.1", "pui,cartofi", 50);
	repoMancare->add(m1);
	((RepoCostum<Mancare>*)repoMancare)->saveToFile();
	assert(repoMancare->size() == 3);
	Mancare m2("mancare2", "str.X,nr.2", "pui,salata", 30);
	//repoMancare->update(m1, m2);
	assert(repoMancare->getAll().at(2) == m1);
	assert(repoMancare->find(m1) == 2);
	repoMancare->del(2);
	assert(repoMancare->size() == 2);
	assert(repoMancare->find(m1) == -1);
	((RepoCostum<Mancare>*)repoMancare)->saveToFile();

	//shopping
	RepoCostum<Shopping>* repoShopping = new RepoCostum<Shopping>("shopping.txt");
	((RepoCostum<Shopping>*)repoShopping)->loadFromFile();
	assert(repoShopping->size() == 2);
	Shopping s1("shopping1", "str.X,nr.1", "haine,pantofi", 500, "h&m");
	repoShopping->add(s1);
	((RepoCostum<Shopping>*)repoShopping)->saveToFile();
	assert(repoShopping->size() == 3);
	Shopping s2("shopping2", "str.X,nr.2", "curea,jucarie", 300, "zara");
	//repoMancare->update(m1, m2);
	assert(repoShopping->getAll().at(2) == s1);
	assert(repoShopping->find(s1) == 2);
	repoShopping->del(2);
	assert(repoShopping->size() == 2);
	assert(repoShopping->find(s1) == -1);
	((RepoCostum<Shopping>*)repoShopping)->saveToFile();

}

void testeValidari() {
	
	//mancareCSV
	RepoCSV<Mancare>* repoMancare = new RepoCSV<Mancare>("mancare.csv");
	((RepoCSV<Mancare>*)repoMancare)->loadFromFile();
	ValidareDate vd;
	Mancare m("nume", "adresa", "", -2);
	try {
		vd.validareMancare(m);
		repoMancare->add(m);
	}
	catch(exception& e){}
	assert(repoMancare->size() == 2);

	//mancareCostum
	RepoCostum<Mancare>* repoM = new RepoCostum<Mancare>("mancare.txt");
	((RepoCostum<Mancare>*)repoM)->loadFromFile();
	ValidareDate vd1;
	Mancare m1("nume", "adresa", "", -2);
	try {
		vd1.validareMancare(m1);
		repoM->add(m1);
	}
	catch (exception & e) {}
	assert(repoM->size() == 2);

	//shoppingCSV
	RepoCSV<Shopping>* repoShopping = new RepoCSV<Shopping>("shopping.csv");
	((RepoCSV<Shopping>*)repoShopping)->loadFromFile();
	ValidareDate vd2;
	Shopping s("nume", "adresa", "", -2, "maga");
	try {
		vd2.validareShopping(s);
		repoShopping->add(s);
	}
	catch (exception & e) {}
	assert(repoShopping->size() == 2);

	//shoppingCostum
	RepoCostum<Shopping>* repoS = new RepoCostum<Shopping>("shopping.txt");
	((RepoCostum<Shopping>*)repoS)->loadFromFile();
	ValidareDate vd3;
	Shopping s1("nume", "adresa", "", -2, "maga");
	try {
		vd3.validareShopping(s1);
		repoS->add(s1);
	}
	catch (exception & e) {}
	assert(repoS->size() == 2);
}

void tests() {
	std::cout << "first tests ..." << endl;

	testeEntitati();
	repoCSVtests();
	repoCostumTests();
	testeValidari();

	std::cout << "all tests are ok ... good job!" << endl << endl;
}