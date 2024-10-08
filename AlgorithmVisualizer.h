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
        Algorithm *algorithm = nullptr; // Solo para algoritmos de ordenamiento
        BinarySearch binarySearch;      // Objeto para búsqueda binaria
        Statistics stats;

    public:
        void promptForInput(sf::RenderWindow &window);
        void displayInputData(sf::RenderWindow &window, const vector<int> &data);
        void executeAlgorithm(const string &algorithmName);
        void executeBinarySearch(sf::RenderWindow &window); // Nueva función
        void showResults(sf::RenderWindow &window, const vector<int> &data, const string &algorithmName);
        const vector<int> &getData() const;
};

#endif // ALGORITHMVISUALIZER_H