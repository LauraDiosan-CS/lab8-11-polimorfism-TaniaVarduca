#include "RepoBaza.h"
#include "Mancare.h"
#include "Shopping.h"
#include "RepoCSV.h"
#include "RepoCostum.h"
#include "tests.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
    tests();
    cout << "Alegeti tipul de fisier: " << endl;
    cout << "1. CSV" << endl;
    cout << "2. Costum" << endl;
    cout << "Introduceti 1 sau 2: ";
    int opt; cin >> opt; cout << endl;
    if (opt == 1) {
        Repo<Mancare>* repoMancare = new RepoCSV<Mancare>("mancare.csv");
        ((RepoCSV<Mancare>*)repoMancare)->loadFromFile();
        Repo<Shopping>* repoShopping = new RepoCSV<Shopping>("shopping.csv");
        ((RepoCSV<Shopping>*)repoShopping)->loadFromFile();
        Repo<User>* repoUser = new Repo<User>();
        Service s(repoMancare, repoShopping, repoUser);
        UI ui(s);
        ui.run();
    }
    if (opt == 2) {
        Repo<Mancare>* repoMancare = new RepoCostum<Mancare>("mancare.txt");
        ((RepoCostum<Mancare>*)repoMancare)->loadFromFile();
        Repo<Shopping>* repoShopping = new RepoCostum<Shopping>("shopping.txt");
        ((RepoCostum<Shopping>*)repoShopping)->loadFromFile();
        Repo<User>* repoUser = new Repo<User>();
        Service s(repoMancare, repoShopping, repoUser);
        UI ui(s);
        ui.run();
    }
    return 0;
}
