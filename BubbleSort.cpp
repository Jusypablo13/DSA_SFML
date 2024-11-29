#include "BubbleSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void BubbleSort::sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
            visualizer.displayArray(window, data, j + 1);  // Visualiza el progreso
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }
}
