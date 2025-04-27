#pragma once
#include "Wierzcholek.h"

void merge(unsigned long long int arr[], unsigned long long int left, unsigned long long int mid, unsigned long long int right);
void mergeSort(unsigned long long int arr[], unsigned long long int left, unsigned long long int right);
void printArray(unsigned long long int arr[], unsigned long long int size);
void debugPrintArray(Wierzcholek** wierzcholki, unsigned long long int size);
void mergeLF(Wierzcholek** wierzcholki, unsigned long long int left, unsigned long long int mid, unsigned long long int right);
void mergeSortLF(Wierzcholek** wierzcholki, unsigned long long int left, unsigned long long int right);