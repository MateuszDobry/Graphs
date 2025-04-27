#pragma once
class Wierzcholek
{
public:
	int liczba_sasiadow;
	unsigned long long int nr_wierzcholka;
	unsigned long long int kolor;
	Wierzcholek** sasiedzi;
	
	Wierzcholek();
	Wierzcholek(const Wierzcholek& other);
	~Wierzcholek();

	Wierzcholek operator=(Wierzcholek other);
};

