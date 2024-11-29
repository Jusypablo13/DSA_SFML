#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <stack>

class GraphTraversal {
private:
    int rows, cols;
    std::vector<std::vector<int>> maze; // Representación del laberinto
    std::vector<std::pair<int, int>> directions; // Movimientos posibles: {arriba, derecha, abajo, izquierda}

    // Validar si la celda es válida
    bool isValid(int x, int y);

public:
    // Constructor
    GraphTraversal(int rows, int cols);

    // Generar el laberinto
    void generateMaze();

    // Algoritmos de búsqueda
    std::vector<int> depthFirstSearch(int startNode);
    std::vector<int> breadthFirstSearch(int startNode);

    // Visualizar el laberinto
    void visualizeMaze(sf::RenderWindow &window, sf::Font &font, const std::vector<int> &order, bool isDFS);
};

#endif // GRAPHTRAVERSAL_H
