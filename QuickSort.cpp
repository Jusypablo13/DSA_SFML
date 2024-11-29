#include "QuickSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void QuickSort::sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    quickSort(data, 0, data.size() - 1, window, visualizer);
}

void QuickSort::quickSort(vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    if (low < high) {
        int pi = partition(data, low, high, window, visualizer);
        quickSort(data, low, pi - 1, window, visualizer);
        quickSort(data, pi + 1, high, window, visualizer);
    }
}

int QuickSort::partition(vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            ++i;
            swap(data[i], data[j]);
        }
        visualizer.displayArray(window, data, j);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}
