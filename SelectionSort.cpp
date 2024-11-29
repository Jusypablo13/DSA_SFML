#include "SelectionSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void SelectionSort::sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
            visualizer.displayArray(window, data, j);  // Visualiza el progreso
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        swap(data[i], data[minIndex]);
    }
}
