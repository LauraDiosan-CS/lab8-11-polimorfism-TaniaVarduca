#include "UI.h"
#include <vector>;
#include <iostream>
using namespace std;


//afisare meniu
void UI::printMenu()
{
	cout << endl;
	cout << "1. Afisare comenzi de tip mancare" << endl;
	cout << "2. Afisare comenzi de tip shopping" << endl;
	cout << "3. Cautare dupa nume client" << endl;
	cout << "4. Adaugare comanda de tip mancare" << endl;
	cout << "5. Adaugare comanda de tip shopping" << endl;
	cout << "6. Logout" << endl;
	cout << "7. Inchidere aplicatie" << endl;
}

int UI::login()
{
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user: ";
	cin >> user;
	cout << "Parola: ";
	cin >> pass;
	return s.login(user, pass);
}

void UI::logout()
{
	s.logout(u.getUserName(), u.getPassword());
	cout << "Logout efectuat cu succes! La revedere!" << endl;
}



void UI::allMancare()
{
	map<int, Mancare> m = s.getAllMancare();
	map<int, Mancare>::iterator itr;
	cout << endl << "Comenzile de tip mancare sunt: " << endl;
	for (itr = m.begin(); itr != m.end(); ++itr) {
		cout << "cheia: " << itr->first << ", comanda: " << itr->second;
		cout << endl;
	}
}

void UI::allShopping()
{
	map<int, Shopping> sho = s.getAllShopping();
	map<int, Shopping>::iterator itr;
	cout << endl << "Comenzile de tip Shopping sunt: " << endl;
	for (itr = sho.begin(); itr != sho.end(); ++itr) {
		cout << "cheia: " << itr->first << ", comanda: " << itr->second;
		cout << endl;
	}
}

void UI::addMancare()
{
	string nume, adresa, preparate; int pret;
	cout << "Nume client: "; cin >> nume;
	cout << "Adresa client: "; cin >> adresa;
	cout << "Lista preparate: "; cin >> preparate; if (preparate == "-") preparate = "";
	cout << "Pret total: "; cin >> pret;
	Mancare m(nume, adresa, preparate, pret);
	s.addMancare(m);
}

void UI::addShopping()
{
	string nume, adresa, cumparaturi, magazin; int pret;
	cout << "Nume client: "; cin >> nume;
	cout << "Adresa client: "; cin >> adresa;
	cout << "Lista cumparaturi: "; cin >> cumparaturi; if (cumparaturi == "-") cumparaturi = "";
	cout << "Pret total: "; cin >> pret;
	cout << "Nume magazin: "; cin >> magazin;
	Shopping sho(nume, adresa, cumparaturi, pret, magazin);
	s.addShopping(sho);
}

void UI::cautareDupaNume()
{
	string nume;
	cout << "Dati numele clientului: "; cin >> nume;
	map<int, Mancare> m = s.mancareDupaNumeClient(nume);
	map<int, Mancare>::iterator itr;
	for (itr = m.begin(); itr != m.end(); ++itr) {
		cout << itr->second;
		cout << endl;
	}
	map<int, Shopping> sho = s.shoppingDupaNumeClient(nume);
	map<int, Shopping>::iterator it;
	for (it = sho.begin(); it != sho.end(); ++it) {
		cout << it->second;
		cout << endl;
	}
}

UI::UI()
{
}


UI::UI(Service& ss)
{
	s = ss;
}

void UI::run()
{
	bool k = true;
	Service s;
	int rez = login();
	if (rez) {
		cout << "Autentificare cu succes!" << endl;
		while (k)
		{
			printMenu();
			int option = 0;
			cin >> option;
			if (option == 1)
			{
				allMancare();
				continue;
			}
			if (option == 2)
			{
				allShopping();
				continue;
			}
			if (option == 3) {
				cautareDupaNume();
				continue;
			}
			if (option == 4) {
				addMancare();
				continue;
			}
			if (option == 5) {
				addShopping();
				continue;
			}
			if (option == 6) {
				logout();
				k = false;
			}
			if (option == 7)
				k = false;
		}
	}
	else
		cout << "User sau parola incorecte..." << endl;
}

UI::~UI()
{
}