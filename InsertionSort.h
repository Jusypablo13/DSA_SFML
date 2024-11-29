#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Algorithm.h"

class InsertionSort : public Algorithm {
public:
    void sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) override;
};

#endif // INSERTIONSORT_H
