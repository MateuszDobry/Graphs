#include "Kolorowanie.h"
#include <iostream>
#include "MergeSort.h"

void KolorowanieZachlanne(Wierzcholek* wierzcholki, unsigned long long int liczba_wierzcholkow)
{
    bool* zajeteKolory = new bool[liczba_wierzcholkow];
    for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
        zajeteKolory[i] = false;
    }
    wierzcholki[0].kolor = 1;
    for (unsigned long long int i = 1; i < liczba_wierzcholkow; i++) {
        wierzcholki[i].kolor = 0;
    }

    for (unsigned long long int i = 1; i < liczba_wierzcholkow; i++) {
        Kolorowanie(wierzcholki, i, zajeteKolory, liczba_wierzcholkow);
    }

    for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
        std::cout << wierzcholki[i].kolor << " ";
    }
    delete[] zajeteKolory;
}

void Kolorowanie(Wierzcholek* wierzcholki, unsigned long long int nr_wierzcholka, bool* zajeteKolory, unsigned long long int liczba_wierzcholkow)
{
    for (unsigned long long int i = 0; i < wierzcholki[nr_wierzcholka].liczba_sasiadow; i++) {
        unsigned long long int spr = wierzcholki[nr_wierzcholka].sasiedzi[i]->nr_wierzcholka;
        if (wierzcholki[spr - 1].kolor != 0) {
            zajeteKolory[wierzcholki[spr - 1].kolor - 1] = true;
        }
    }

    unsigned long long int NowyKolor;
    for (NowyKolor = 0; NowyKolor < liczba_wierzcholkow; NowyKolor++) {
        if (zajeteKolory[NowyKolor] != true) {
            break;
        }
    }


    wierzcholki[nr_wierzcholka].kolor = NowyKolor + 1;

    for (unsigned long long int i = 0; i < wierzcholki[nr_wierzcholka].liczba_sasiadow; i++) {
        unsigned long long int spr = wierzcholki[nr_wierzcholka].sasiedzi[i]->nr_wierzcholka;
        if (wierzcholki[spr - 1].kolor != 0) {
            zajeteKolory[wierzcholki[spr - 1].kolor - 1] = false;
        }
    }

}

void Kolorowanie(Wierzcholek** wierzcholki, unsigned long long int nr_wierzcholka, bool* zajete_kolory, unsigned long long int liczba_wierzcholkow)
{
    const unsigned int liczba_sasiadow = wierzcholki[nr_wierzcholka]->liczba_sasiadow;

    for (unsigned long long int i = 0; i < liczba_sasiadow; i++) {
        zajete_kolory[i] = false;
    }

    for (unsigned long long int i = 0; i < liczba_sasiadow; i++) {
        unsigned long long int kolor_sasiada = wierzcholki[nr_wierzcholka]->sasiedzi[i]->kolor;
        if (kolor_sasiada != 0)
        {
            zajete_kolory[kolor_sasiada - 1] = true;
        }
    }

    unsigned long long int nowy_kolor = 0;
    while (nowy_kolor < liczba_wierzcholkow && zajete_kolory[nowy_kolor] != false)
    {
        nowy_kolor++;
    }
    
    wierzcholki[nr_wierzcholka]->kolor = nowy_kolor + 1;
}

void KolorowanieLF(Wierzcholek* wierzcholki, unsigned long long int liczba_wierzcholkow) {
    bool* zajeteKolory = new bool[liczba_wierzcholkow];
    for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
        zajeteKolory[i] = false;
    }
    
    Wierzcholek** wierzcholkiSort = new Wierzcholek * [liczba_wierzcholkow];
    for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
        wierzcholkiSort[i] = &wierzcholki[i];
    }

    //debugPrintArray(wierzcholkiSort, liczba_wierzcholkow);
    mergeSortLF(wierzcholkiSort, 0, liczba_wierzcholkow - 1);
    //debugPrintArray(wierzcholkiSort, liczba_wierzcholkow);

    wierzcholkiSort[0]->kolor = 1;
    for (unsigned long long int i = 1; i < liczba_wierzcholkow; i++) {
        wierzcholkiSort[i]->kolor = 0;
    }
    for (unsigned long long int i = 1; i < liczba_wierzcholkow; i++) {
        Kolorowanie(wierzcholkiSort, i, zajeteKolory, liczba_wierzcholkow);
    }

    for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
        std::cout << wierzcholki[i].kolor << " ";
    }

    delete[] wierzcholkiSort;
    delete[] zajeteKolory;
}