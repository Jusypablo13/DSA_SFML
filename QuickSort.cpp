#include "QuickSort.h"

void QuickSort::sort(vector<int> &data){
    quickSort(data, 0, data.size() - 1);
}

void QuickSort::quickSort(vector<int> &data, int low, int high){
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

int QuickSort::partition(vector<int> &data, int low, int high){
    int pivot = data[high]; // Escoger el ultimo elemento como pivote
    int i = low - 1; // Pared izquierda

    for (int j = low; j < high; j++){
        if (data[j] < pivot){ // Si el elemento actual es menor que el pivote
            i++;
            swap(data[i], data[j]); // Intercambiar los elementos
        }
    }
    swap(data[i + 1], data[high]); // Intercambiar el pivote con el elemento en la pared izquierda
    return i + 1; // Regresar la posicion del pivote
}