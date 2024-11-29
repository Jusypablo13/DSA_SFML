#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <limits>

class Dijkstra {
private:
    std::vector<std::vector<std::pair<int, int>>> graph; // Grafo como lista de adyacencia
    int numNodes; // Número de nodos

public:
    Dijkstra(int nodes);
    void addEdge(int u, int v, int weight);
    std::vector<int> calculateShortestPaths(int startNode);
    void visualizeGraph(sf::RenderWindow& window, const sf::Font& font, const std::vector<int>& parents, const std::vector<int>& distances);
    std::pair<std::vector<int>, std::vector<int>> run(int source);
};

#endif // DIJKSTRA_H
