#pragma once
#include "Wierzcholek.h"

class Graf
{
public:
	Wierzcholek* wierzcholki;
	unsigned long long int liczba_wierzcholkow;

	Graf(unsigned long long int liczba_wierzcholkow);
	Graf(unsigned long long int liczba_wierzcholkow, Wierzcholek* wierzcholki);
	Graf operator=(Graf other);
	Graf(const Graf& other);
	
	~Graf();
};

