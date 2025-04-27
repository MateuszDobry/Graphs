#include "Graf.h"
#include <utility>
Graf::Graf(unsigned long long int liczba_wierzcholkow) {
	this->liczba_wierzcholkow = liczba_wierzcholkow;
	this->wierzcholki = new Wierzcholek[liczba_wierzcholkow];
}

Graf::Graf(unsigned long long int liczba_wierzcholkow, Wierzcholek* wierzcholki)
{
	this->liczba_wierzcholkow = liczba_wierzcholkow;
	this->wierzcholki = wierzcholki;
}

Graf Graf::operator=(Graf other)
{
	std::swap(this->liczba_wierzcholkow, other.liczba_wierzcholkow);
	std::swap(this->wierzcholki, other.wierzcholki);
	return *this;
}


Graf::~Graf()
{
	delete[] wierzcholki;
}

Graf::Graf(const Graf& other)
{
	this->liczba_wierzcholkow = other.liczba_wierzcholkow;
	this->wierzcholki = new Wierzcholek[liczba_wierzcholkow];
	for (int i = 0; i < liczba_wierzcholkow; i++) {
		this->wierzcholki[i] = other.wierzcholki[i];
	}
}
