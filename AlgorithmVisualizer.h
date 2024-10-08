#ifndef ALGORITHMVISUALIZER_H
#define ALGORITHMVISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Algorithm.h"
#include "Statistics.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "BinarySearch.h"

using namespace std;

class AlgorithmVisualizer {
    private:
        vector<int> data;
        Algorithm *algorithm = nullptr;
        Statistics stats;
        BinarySearch binarySearch;
    
    public:
        void promptForInput(sf::RenderWindow &window);
        void displayInputData(sf::RenderWindow &window, const vector<int> &data);
        void executeAlgorithm(const string &algorithmName);
        void showResults(sf::RenderWindow &window, const vector<int> &data, const string &algorithmName);
        const vector<int> &getData() const; 
        void executeBinarySearch(sf::RenderWindow &window);
};

#endif // ALGORITHMVISUALIZER_H