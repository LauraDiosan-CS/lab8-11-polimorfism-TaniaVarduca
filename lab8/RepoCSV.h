#pragma once
#include "RepoBaza.h"
#include <fstream>
using namespace std;

template  <class T> class RepoCSV : public Repo<T>
{
protected:
	const char* fileName;
public:
	RepoCSV();
	RepoCSV(const char*);
	void loadFromFile();
	void saveToFile();
	~RepoCSV();
};
template<class T>
RepoCSV<T>::RepoCSV():Repo<T>()
{
}

template<class T>
inline RepoCSV<T>::RepoCSV(const char* fName) 
{
	fileName = fName;
}

template<class T>
void RepoCSV<T>::loadFromFile()
{
	string line;
	ifstream f(fileName);
	while (getline(f, line)) {
		T ob(line, ',');
		Repo<T>::add(ob);
	}
}

template<class T>
void RepoCSV<T>::saveToFile()
{
	ofstream f(fileName);
	map<int, T> t = Repo<T>::comenzi;
	for (auto itr = t.begin(); itr != t.end(); ++itr) {
		f << itr->second.toStringDelimiter(',') << endl;
	}
}

template<class T>
RepoCSV<T>::~RepoCSV()
{
}
