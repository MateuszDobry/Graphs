#pragma once
#include "Graf.h"
void KolorowanieZachlanne(Wierzcholek* wierzcholki, unsigned long long int liczba_wierzcholkow);
void Kolorowanie(Wierzcholek* wierzcholki, unsigned long long int nr_wierzcholka, bool* zajete, unsigned long long int liczba_wierzcholkow);
void KolorowanieLF(Wierzcholek* wierzcholki, unsigned long long int liczba_wierzcholkow);
void Kolorowanie(Wierzcholek** wierzcholki, unsigned long long int nr_wierzcholka, bool* zajete_kolory, unsigned long long int liczba_wierzcholkow);