#include "MergeSort.h"
#include <iostream>

void merge(unsigned long long int arr[], unsigned long long int left, unsigned long long int mid, unsigned long long int right) {
    unsigned long long int n1 = mid - left + 1;
    unsigned long long int n2 = right - mid;

    unsigned long long int* L = new unsigned long long int[n1];
    unsigned long long int* R = new unsigned long long int[n2];

    for (unsigned long long int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (unsigned long long int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    unsigned long long int i = 0, j = 0, k = left;

    // Zmiana warunku porównania na `>=` dla sortowania malej¹cego
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(unsigned long long int arr[], unsigned long long int left, unsigned long long int right) {
    if (left < right) {
        unsigned long long int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(unsigned long long int arr[], unsigned long long int size) {
    for (unsigned long long int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void debugPrintArray(Wierzcholek** wierzcholki, unsigned long long int size) {
    for (unsigned long long int i = 0; i < size; i++) {
        std::cout << wierzcholki[i]->nr_wierzcholka << " " << wierzcholki[i]->liczba_sasiadow;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void mergeLF(Wierzcholek** wierzcholki, unsigned long long int left, unsigned long long int mid, unsigned long long int right) {
    unsigned long long int n1 = mid - left + 1;
    unsigned long long int n2 = right - mid;

    Wierzcholek** L = new Wierzcholek* [n1];
    Wierzcholek** R = new Wierzcholek* [n2];

    for (unsigned long long int i = 0; i < n1; i++)
        L[i] = wierzcholki[left + i];
    for (unsigned long long int j = 0; j < n2; j++)
        R[j] = wierzcholki[mid + 1 + j];

    unsigned long long int i = 0, j = 0, k = left;
        
    while (i < n1 && j < n2) {
        if (L[i]->liczba_sasiadow > R[j]->liczba_sasiadow) {
            wierzcholki[k] = L[i];
            i++;
        }
        else if (L[i]->liczba_sasiadow == R[j]->liczba_sasiadow)
        {
            if (L[i]->nr_wierzcholka < R[j]->nr_wierzcholka)
            {
                wierzcholki[k] = L[i];
                i++;
            }
            else
            {
                wierzcholki[k] = R[j];
                j++;
            }
        }
        else
        {
            wierzcholki[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        wierzcholki[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        wierzcholki[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortLF(Wierzcholek** wierzcholki, unsigned long long int left, unsigned long long int right)
{
    if (left < right) {
        unsigned long long int mid = left + (right - left) / 2;

        mergeSortLF(wierzcholki, left, mid);
        mergeSortLF(wierzcholki, mid + 1, right);
        mergeLF(wierzcholki, left, mid, right);
    }
    return;
}
