#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Algorithm.h"

class SelectionSort : public Algorithm {
public:
    void sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) override;
};

#endif // SELECTIONSORT_H
