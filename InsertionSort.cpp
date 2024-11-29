#include "InsertionSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void InsertionSort::sortWithVisualization(std::vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    for (size_t i = 1; i < data.size(); ++i) {
        int key = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] > key) {
            data[j] = data[j - 1];
            j--;
            visualizer.displayArray(window, data, j);  // Visualiza los cambios
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pausa para animación
        }
        data[j] = key;
        visualizer.displayArray(window, data, j);  // Visualiza el paso final
    }
}
