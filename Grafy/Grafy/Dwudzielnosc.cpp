#include "Dwudzielnosc.h"

bool Dwudzielnosc(Wierzcholek* wierzcholki, char* strona, unsigned long long int liczba_wierzcholkow) {
    enum SIDE : char {
        NONE, LEFT = 'L', RIGHT = 'R'
    };

    // Dynamiczna tablica do kolejki BFS
    unsigned long long int* queue = new unsigned long long int[liczba_wierzcholkow];
    unsigned long long int front = 0, back = 0;

    for (int i = 0; i < liczba_wierzcholkow; i++) {
        if (strona[i] == NONE) {
            queue[back++] = i;
            strona[i] = RIGHT;

            while (front < back) {
                unsigned long long int u = queue[front++];
                for (unsigned long long int j = 0; j < wierzcholki[u].liczba_sasiadow; j++) {
                    unsigned long long int v = wierzcholki[u].sasiedzi[j]->nr_wierzcholka - 1;

                    if (strona[v] == NONE) {
                        strona[v] = (strona[u] == RIGHT) ? LEFT : RIGHT;
                        queue[back++] = v;
                    }
                    else if (strona[v] == strona[u]) {
                        delete[] queue; 
                        return false;
                    }
                }
            }
        }
    }

    delete[] queue; // Zwalnianie pamiêci po zakoñczeniu
    return true;
}
