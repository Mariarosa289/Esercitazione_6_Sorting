
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "SortingAlgorithm.hpp"  // Aggiungi l'inclusione del file SortingAlgorithm.hpp

using namespace std;
using namespace SortLibrary;  // Usa il namespace corretto se necessario

// Funzione per misurare il tempo
void measureSortTime(void (*sortFunc)(std::vector<int>&), std::vector<int>& arr, const string& algoName) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << algoName << " took " << duration.count() << " seconds\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <size>\n";
        return 1;
    }

    int size = std::atoi(argv[1]);
    std::vector<int> data(size);

    // Popola il vettore con valori casuali
    for (int& val : data) {
        val = rand() % 100000;
    }

    // Misura e stampa il tempo di BubbleSort
    std::vector<int> dataBubble = data;
    measureSortTime(BubbleSort<int>, dataBubble, "BubbleSort");

    // Misura e stampa il tempo di HeapSort
    std::vector<int> dataHeap = data;
    measureSortTime(heapSort<int>, dataHeap, "HeapSort");

    return 0;
}
