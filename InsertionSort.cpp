#include "InsertionSort.h"
#include "AlgorithmVisualizer.h"
#include <thread>
#include <chrono>

void InsertionSort::sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) {
    int n = data.size();
    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            visualizer.displayArray(window, data, j);  // Visualiza el progreso
            this_thread::sleep_for(chrono::milliseconds(200));
            --j;
        }
        data[j + 1] = key;
    }
}
