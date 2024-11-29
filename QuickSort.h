#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Algorithm.h"

class QuickSort : public Algorithm {
public:
    void sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) override;

private:
    void quickSort(vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer);
    int partition(vector<int>& data, int low, int high, sf::RenderWindow& window, AlgorithmVisualizer& visualizer);
};

#endif // QUICKSORT_H
