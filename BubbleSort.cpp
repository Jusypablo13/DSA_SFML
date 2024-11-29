#include "BubbleSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void BubbleSort::sortWithVisualization(std::vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                visualizer.displayArray(window, data, j);  // Visualiza los cambios
                std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pausa para animación
            }
        }
    }
}
