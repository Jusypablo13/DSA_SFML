#ifndef ALGORITHMVISUALIZER_H
#define ALGORITHMVISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Algorithm.h"
#include "Statistics.h"
#include "BubbleSort.h"
#include "QuickSort.h"

using namespace std;

class AlgorithmVisualizer {
    private:
        vector<int> data;
        Algorithm *algorithm = nullptr; //Por defecto no se ha seleccionado ningún algoritmo
        Statistics stats;
    
    public:
        void promptForInput(sf::RenderWindow &window);
        void displayInputData(sf::RenderWindow &window, const vector<int> &data);
        void executeAlgorithm(const string &algorithmName);
        void showResults(sf::RenderWindow &window, const vector<int> &data, const string &algorithmName);
        const vector<int> &getData() const; 
};

#endif // ALGORITHMVISUALIZER_H