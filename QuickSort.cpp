#include "QuickSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

int QuickSort::partition(std::vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            std::swap(data[++i], data[j]);
            visualizer.displayArray(window, data, j);  // Visualiza los cambios
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pausa para animación
        }
    }
    std::swap(data[i + 1], data[high]);
    visualizer.displayArray(window, data, i + 1);  // Visualiza el paso final
    return i + 1;
}

void QuickSort::quickSort(std::vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    if (low < high) {
        int pi = partition(data, low, high, window, visualizer);
        quickSort(data, low, pi - 1, window, visualizer);
        quickSort(data, pi + 1, high, window, visualizer);
    }
}

void QuickSort::sortWithVisualization(std::vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    quickSort(data, 0, data.size() - 1, window, visualizer);
}
