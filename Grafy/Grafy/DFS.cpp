#include "DFS.h"

void DFS(Wierzcholek& wierzcholek, bool* visited) {
    visited[wierzcholek.nr_wierzcholka - 1] = true;
    for (unsigned long long int i = 0; i < wierzcholek.liczba_sasiadow; i++) {
        if (!visited[wierzcholek.sasiedzi[i]->nr_wierzcholka - 1]) {
            DFS(*wierzcholek.sasiedzi[i], visited);
        }
    }
}