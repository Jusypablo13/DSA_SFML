#include "QuickSort.h"

void QuickSort::sort(vector<int>& data) {
    quickSort(data, 0, data.size() - 1);
}

void QuickSort::quickSort(vector<int>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

int QuickSort::partition(vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}