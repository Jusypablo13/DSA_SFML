#ifndef MERGESORT_H
#define MERGESORT_H

#include "Algorithm.h"

class MergeSort : public Algorithm {
public:
    void sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) override;

private:
    void mergeSort(vector<int>& data, int left, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer);
    void merge(vector<int>& data, int left, int mid, int right, sf::RenderWindow& window, AlgorithmVisualizer& visualizer);
};

#endif // MERGESORT_H
