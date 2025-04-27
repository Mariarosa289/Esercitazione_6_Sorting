#pragma once

#include <iostream>
#include <vector>
#include <type_traits>  // Per std::convertible_to

using namespace std;

namespace SortLibrary {
    // Concept che definisce i tipi che sono ordinabili
    template<typename T>
    concept Sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>; // Verifica che il tipo supporti l'operatore '<'
    };
}

// Funzione BubbleSort generica
template<SortLibrary::Sortable T>
void BubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Funzione heapify generica per HeapSort
template<SortLibrary::Sortable T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // Confronta i figli con il nodo corrente
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Se uno dei figli è maggiore del nodo corrente, scambia
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // Chiama ricorsivamente
    }
}

// Funzione HeapSort generica
template<SortLibrary::Sortable T>
void heapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Costruisce il max heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Estrae uno a uno gli elementi dal heap
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
