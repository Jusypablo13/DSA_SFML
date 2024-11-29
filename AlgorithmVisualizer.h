#ifndef ALGORITHMVISUALIZER_H
#define ALGORITHMVISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Statistics.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

class AlgorithmVisualizer {
private:
    vector<int> data;
    Statistics stats;

    void promptForInput(sf::RenderWindow& window);  // Solicita entrada de datos
    int promptForTarget(sf::RenderWindow& window);  // Solicita el valor a buscar

public:
    // Métodos para algoritmos de búsqueda
    void displayArray(sf::RenderWindow& window, const vector<int>& data, int highlight = -1);
    void runLinearSearch(sf::RenderWindow& window);
    void runBinarySearch(sf::RenderWindow& window);

    // Métodos para algoritmos de ordenamiento
    void runBubbleSort(sf::RenderWindow& window);
    void runSelectionSort(sf::RenderWindow& window);
    void runInsertionSort(sf::RenderWindow& window);
    void runMergeSort(sf::RenderWindow& window);
    void runQuickSort(sf::RenderWindow& window);
};

#endif // ALGORITHMVISUALIZER_H
