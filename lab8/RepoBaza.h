#pragma once
#include <map>
#include <algorithm>
#include <string>
//#include "Exc.h"
using namespace std;

template <class T> class Repo
{
protected:
	map<int, T> comenzi;
	int contor;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void add(T& a);
	map<int, T> getAll();
	void del(int pos);
	//void updateComanda(T& a, int pos, char* numeClient, char* adresaClient, float pretTotal);
	//void update(T&, T&);
	int size();
	int find(T&);
	virtual void loadFromFile();
	virtual void saveToFile();
};

//constructor fara param
template <class T>  Repo<T>::Repo() {
}

//constuctor de copiere
template <class T> Repo<T>::Repo(const Repo& r) {
	this->comenzi = r.comenzi;
	this->contor = r.contor;
}

//destructorul
template <class T> Repo<T>::~Repo() {
}

//adaugarea unui comenzi
template <class T> void Repo<T>::add(T& a) {
	comenzi.insert(pair<int, T>(contor++, a));
}

//returnarea tuturor comenzilor
template <class T> map<int, T> Repo<T>::getAll() {
	return comenzi;
}

//stergerea unei comenzi
template <class T> void Repo<T>::del(int pos)
{
	comenzi.erase(pos);
}

//template<class T> void Repo<T>::updateComanda(T& a, int pos, char* numeClient, char* adresaClient, float pretTotal)
//{
//	a.setNumeClient(numeClient);
//	a.setAdresaClient(adresaClient);
//	a.setPretTotal(pretTotal);
//	comenzi.at(pos) = a;
//}

//template<class T>
//inline void Repo<T>::update(T& vechi, T& nou)
//{
//	std::replace(comenzi.begin()->second, comenzi.end()->second, vechi, nou);
//}

//dimensiune map
template <class T> int Repo<T>::size() {
	return comenzi.size();
}

template<class T>
inline int Repo<T>::find(T& a)
{
	for (auto itr = comenzi.begin(); itr != comenzi.end(); ++itr) {
		if (itr->second == a)
			return itr->first;
	}
	return -1;
}

template<class T>
inline void Repo<T>::loadFromFile()
{
}

template<class T>
inline void Repo<T>::saveToFile()
{
}
