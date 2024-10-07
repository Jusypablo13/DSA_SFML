#include "MergeSort.h"
#include <vector>

void MergeSort::merge(std::vector<int> &data, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; ++i)
        left[i] = data[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        } else {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(std::vector<int> &data, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
}

void MergeSort::sort(std::vector<int> &data) {
    mergeSort(data, 0, data.size() - 1);
}