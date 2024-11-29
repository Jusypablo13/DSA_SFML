#include "SelectionSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void SelectionSort::sortWithVisualization(std::vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(data[i], data[minIndex]);
            visualizer.displayArray(window, data, i);  // Visualiza los cambios
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pausa para animación
        }
    }
}
