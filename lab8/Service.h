#pragma once
#include "RepoCSV.h"
#include "RepoCostum.h"
#include "Mancare.h"
#include "Shopping.h"
#include "User.h"

class Service
{
private:
	Repo<Mancare>* repoMancare;
	Repo<Shopping>* repoShopping;
	Repo<User>* repoUser;
public:
	Service();
	Service(Repo<Mancare>*, Repo<Shopping>*, Repo<User>*);
	bool login(string, string);
	void logout(string, string);
	map<int, Mancare> getAllMancare();
	map<int, Shopping> getAllShopping();
	void addMancare(Mancare&);
	void addShopping(Shopping&);
	map<int, Mancare> mancareDupaNumeClient(string);
	map<int, Shopping> shoppingDupaNumeClient(string);
	~Service();
};
