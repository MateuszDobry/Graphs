#include <iostream>
#include "Graf.h"
#include "MergeSort.h"
#include "DFS.h"
#include "Dwudzielnosc.h"
#include "Kolorowanie.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int liczba_grafow;
    cin >> liczba_grafow;
    for (int g = 0; g < liczba_grafow; g++) {
        unsigned long long int liczba_wierzcholkow;
        int wszystkie_krawedzie = 0;

        // Wczytywanie 
        cin >> liczba_wierzcholkow;
        Graf graf(liczba_wierzcholkow);
        for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
            int tmp_sasiad;
            int liczba_sasiadow;
            graf.wierzcholki[i].nr_wierzcholka = i + 1;

            cin >> liczba_sasiadow;
            wszystkie_krawedzie += liczba_sasiadow;
            graf.wierzcholki[i].sasiedzi = new Wierzcholek * [liczba_sasiadow];
            graf.wierzcholki[i].liczba_sasiadow = liczba_sasiadow;
            for (int j = 0; j < liczba_sasiadow; j++) {
                cin >> tmp_sasiad;
                graf.wierzcholki[i].sasiedzi[j] = &(graf.wierzcholki[tmp_sasiad - 1]);
            }
        }

        unsigned long long int* ciag_stopniowy = new unsigned long long int[liczba_wierzcholkow];
        for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
            ciag_stopniowy[i] = graf.wierzcholki[i].liczba_sasiadow;
        }
        mergeSort(ciag_stopniowy, 0, liczba_wierzcholkow - 1);
        printArray(ciag_stopniowy, liczba_wierzcholkow);
        delete[] ciag_stopniowy;

        bool* visited = new bool[liczba_wierzcholkow];
        for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
            visited[i] = false;
        }

        unsigned long long int liczba_skladowych_spojnosci = 0;

        for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
            if (!visited[i]) {
                liczba_skladowych_spojnosci++;
                DFS(graf.wierzcholki[i], visited);
            }
        }

        cout << liczba_skladowych_spojnosci << endl;
        enum SIDE : char {
            NONE, LEFT = 'L', RIGHT = 'R'
        };

        char* strona = new char[liczba_wierzcholkow];
        for (unsigned long long int i = 0; i < liczba_wierzcholkow; i++) {
            strona[i] = NONE;
        }

        if (Dwudzielnosc(graf.wierzcholki, strona, liczba_wierzcholkow)) {
            cout << 'T' << endl;
        }
        else {
            cout << 'F' << endl;
        }

        for (int i = 0; i < 2; i++) {
            cout << '?' << endl;
        }

      

        KolorowanieZachlanne(graf.wierzcholki, liczba_wierzcholkow);
        
        cout << endl;

        KolorowanieLF(graf.wierzcholki, liczba_wierzcholkow);

        cout << endl;


        for (int i = 0; i < 2; i++) {
            cout << '?' << endl;
        }
       
        long long int krawedzie_do_dopelnienia = ((liczba_wierzcholkow - 1) * liczba_wierzcholkow) / 2 - wszystkie_krawedzie / 2;
        cout << krawedzie_do_dopelnienia << endl;

        delete[] strona;
        delete[] visited;
    }

    return 0;
}
