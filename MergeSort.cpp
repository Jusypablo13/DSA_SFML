#include "MergeSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void MergeSort::merge(std::vector<int>& data, int left, int mid, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= mid) temp[k++] = data[i++];
    while (j <= right) temp[k++] = data[j++];

    for (i = left, k = 0; i <= right; ++i, ++k) {
        data[i] = temp[k];
        visualizer.displayArray(window, data, i);  // Visualiza los cambios
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pausa para animación
    }
}

void MergeSort::mergeSort(std::vector<int>& data, int left, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid, window, visualizer);
        mergeSort(data, mid + 1, right, window, visualizer);
        merge(data, left, mid, right, window, visualizer);
    }
}

void MergeSort::sortWithVisualization(std::vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    mergeSort(data, 0, data.size() - 1, window, visualizer);
}
