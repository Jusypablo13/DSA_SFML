#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <stack>

class Maze {
private:
    int rows, cols;
    std::vector<std::vector<bool>> walls; // Representa las paredes (true = pared, false = camino)
    std::vector<std::vector<bool>> visited; // Celdas visitadas
    sf::Vector2i start, end; // Posición inicial y final

    void drawCell(sf::RenderWindow& window, const sf::Vector2i& cell, const sf::Color& color);

public:
    Maze(int rows, int cols);
    void generateMaze(); // Genera un laberinto aleatorio
    std::vector<sf::Vector2i> depthFirstSearch(); // Devuelve el orden de exploración DFS
    std::vector<sf::Vector2i> breadthFirstSearch(); // Devuelve el orden de exploración BFS
    void visualize(sf::RenderWindow& window, const std::vector<sf::Vector2i>& path, bool isDFS);
};

#endif // MAZE_H
