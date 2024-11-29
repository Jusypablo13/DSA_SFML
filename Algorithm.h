#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class AlgorithmVisualizer;  // Forward declaration

class Algorithm {
public:
    virtual ~Algorithm() = default;
    virtual void sortWithVisualization(vector<int>& data, sf::RenderWindow& window, AlgorithmVisualizer& visualizer) = 0;
};

#endif // ALGORITHM_H