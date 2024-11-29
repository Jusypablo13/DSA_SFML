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

    void promptForInput(sf::RenderWindow& window, sf::Font& font);
    int promptForTarget(sf::RenderWindow& window, sf::Font& font);

public:
    // Métodos para algoritmos de búsqueda
    void displayArray(sf::RenderWindow& window, const vector<int>& data, int highlight = -1);
    void runLinearSearch(sf::RenderWindow& window, sf::Font& font);
    void runBinarySearch(sf::RenderWindow& window, sf::Font& font);

    // Métodos para algoritmos de ordenamiento
    void runBubbleSort(sf::RenderWindow& window, sf::Font& font);
    void runSelectionSort(sf::RenderWindow& window, sf::Font& font);
    void runInsertionSort(sf::RenderWindow& window, sf::Font& font);
    void runMergeSort(sf::RenderWindow& window, sf::Font& font);
    void runQuickSort(sf::RenderWindow& window, sf::Font& font);

    void runSearchAlgorithms(sf::RenderWindow& window, sf::Font& font);
    void runSortingAlgorithms(sf::RenderWindow& window, const sf::Font& font);
};

#endif // ALGORITHMVISUALIZER_H
