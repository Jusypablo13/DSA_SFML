#include "MergeSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void MergeSort::sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    mergeSort(data, 0, data.size() - 1, window, visualizer);
}

void MergeSort::mergeSort(vector<int>& data, int left, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid, window, visualizer);
        mergeSort(data, mid + 1, right, window, visualizer);
        merge(data, left, mid, right, window, visualizer);
    }
}

void MergeSort::merge(vector<int>& data, int left, int mid, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = data[left + i];
    for (int i = 0; i < n2; ++i) R[i] = data[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
        visualizer.displayArray(window, data, k);
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    while (i < n1) {
        data[k++] = L[i++];
        visualizer.displayArray(window, data, k);
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    while (j < n2) {
        data[k++] = R[j++];
        visualizer.displayArray(window, data, k);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}
