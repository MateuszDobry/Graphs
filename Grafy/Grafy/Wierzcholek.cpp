#include "Wierzcholek.h"
#include <utility>

Wierzcholek::Wierzcholek() : liczba_sasiadow(0), nr_wierzcholka(0), kolor(0), sasiedzi(nullptr) {}

Wierzcholek::Wierzcholek(const Wierzcholek& other) 
	: liczba_sasiadow(other.liczba_sasiadow)
	, nr_wierzcholka(other.nr_wierzcholka)
	, kolor(other.kolor)
{
	this->sasiedzi = new Wierzcholek * [liczba_sasiadow];
	for (int i = 0; i < liczba_sasiadow; i++) {
		this->sasiedzi[i] = other.sasiedzi[i];
	}
}

Wierzcholek::~Wierzcholek() {
	if (sasiedzi != nullptr) {
		delete[] sasiedzi;
	}
}

Wierzcholek Wierzcholek::operator=(Wierzcholek other)
{
	std::swap(this->liczba_sasiadow, other.liczba_sasiadow);
	std::swap(this->nr_wierzcholka, other.nr_wierzcholka);
	std::swap(this->kolor, other.kolor);
	std::swap(this->sasiedzi, other.sasiedzi);
	return *this;
}
