#include "GraphTraversal.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

GraphTraversal::GraphTraversal(int rows, int cols) : rows(rows), cols(cols) {
    maze.resize(rows, std::vector<int>(cols, 0));
    directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Movimientos: arriba, abajo, izquierda, derecha
    srand(static_cast<unsigned>(time(nullptr))); // Semilla para generación aleatoria
}

bool GraphTraversal::isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
}

void GraphTraversal::generateMaze() {
    maze.assign(rows, std::vector<int>(cols, 0)); // Inicializa el laberinto vacío
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (rand() % 4 == 0) { // Genera obstáculos aleatorios
                maze[i][j] = 1;   // 1 representa un obstáculo
            }
        }
    }
    maze[0][0] = 0; // Asegura que el punto inicial esté libre
    maze[rows - 1][cols - 1] = 0; // Asegura que el punto de salida esté libre
}

std::vector<int> GraphTraversal::depthFirstSearch(int startNode) {
    std::vector<int> visited(rows * cols, 0);
    std::vector<int> order;

    std::stack<int> stack;
    stack.push(startNode);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        int x = current / cols;
        int y = current % cols;

        if (!isValid(x, y) || visited[current]) {
            continue;
        }

        visited[current] = 1;
        order.push_back(current);

        for (const auto &dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (isValid(nx, ny)) {
                stack.push(nx * cols + ny);
            }
        }
    }

    return order;
}

std::vector<int> GraphTraversal::breadthFirstSearch(int startNode) {
    std::vector<int> visited(rows * cols, 0);
    std::vector<int> order;

    std::queue<int> queue;
    queue.push(startNode);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        int x = current / cols;
        int y = current % cols;

        if (!isValid(x, y) || visited[current]) {
            continue;
        }

        visited[current] = 1;
        order.push_back(current);

        for (const auto &dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (isValid(nx, ny)) {
                queue.push(nx * cols + ny);
            }
        }
    }

    return order;
}

void GraphTraversal::visualizeMaze(sf::RenderWindow &window, sf::Font &font, const std::vector<int> &order, bool isDFS) {
    sf::RectangleShape cell(sf::Vector2f(20.f, 20.f));
    cell.setOutlineThickness(1.f);
    cell.setOutlineColor(sf::Color::Black);

    // Dibujar laberinto inicial
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 1) {
                cell.setFillColor(sf::Color::Black); // Obstáculo
            } else {
                cell.setFillColor(sf::Color::White); // Camino libre
            }
            cell.setPosition(j * 20.f, i * 20.f);
            window.draw(cell);
        }
    }
    window.display();
    sf::sleep(sf::seconds(1)); // Pausa inicial

    // Dibujar el recorrido
    for (size_t k = 0; k < order.size(); ++k) {
        int x = order[k] / cols;
        int y = order[k] % cols;

        cell.setFillColor(isDFS ? sf::Color::Blue : sf::Color::Green);
        cell.setPosition(y * 20.f, x * 20.f);
        window.draw(cell);

        window.display();
        sf::sleep(sf::milliseconds(200)); // Pausa para animación
    }

    // Mostrar mensaje final
    sf::Text message("Traversal Complete!", font, 24);
    message.setFillColor(sf::Color::Red);
    message.setPosition(10.f, rows * 20.f + 10.f);
    window.draw(message);
    window.display();

    sf::sleep(sf::seconds(2)); // Pausa final
}
