#include "Maze.h"
#include <random>
#include <iostream>

Maze::Maze(int rows, int cols) : rows(rows), cols(cols) {
    walls.resize(rows, std::vector<bool>(cols, true)); // Todo es pared inicialmente
    visited.resize(rows, std::vector<bool>(cols, false));
    start = {0, 0};
    end = {rows - 1, cols - 1};
}

// Genera el laberinto aleatoriamente
void Maze::generateMaze() {
    std::stack<sf::Vector2i> stack;
    stack.push(start);
    visited[start.x][start.y] = true;

    // Generación usando DFS
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<sf::Vector2i> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!stack.empty()) {
        sf::Vector2i current = stack.top();
        stack.pop();

        std::shuffle(directions.begin(), directions.end(), gen);

        for (auto dir : directions) {
            sf::Vector2i next = {current.x + dir.x, current.y + dir.y};
            if (next.x >= 0 && next.y >= 0 && next.x < rows && next.y < cols && !visited[next.x][next.y]) {
                visited[next.x][next.y] = true;
                walls[next.x][next.y] = false; // Crea un camino
                stack.push(next);
            }
        }
    }

    // Limpia el estado de visitados
    visited.assign(rows, std::vector<bool>(cols, false));
}

// Dibuja una celda en la ventana
void Maze::drawCell(sf::RenderWindow& window, const sf::Vector2i& cell, const sf::Color& color) {
    sf::RectangleShape rectangle(sf::Vector2f(20, 20));
    rectangle.setPosition(cell.y * 20, cell.x * 20);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

// DFS
std::vector<sf::Vector2i> Maze::depthFirstSearch() {
    std::stack<sf::Vector2i> stack;
    std::vector<sf::Vector2i> path;
    stack.push(start);

    while (!stack.empty()) {
        sf::Vector2i current = stack.top();
        stack.pop();

        if (visited[current.x][current.y]) continue;

        visited[current.x][current.y] = true;
        path.push_back(current);

        if (current == end) break;

        std::vector<sf::Vector2i> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : directions) {
            sf::Vector2i next = {current.x + dir.x, current.y + dir.y};
            if (next.x >= 0 && next.y >= 0 && next.x < rows && next.y < cols && !visited[next.x][next.y] && !walls[next.x][next.y]) {
                stack.push(next);
            }
        }
    }

    return path;
}

// BFS
std::vector<sf::Vector2i> Maze::breadthFirstSearch() {
    std::queue<sf::Vector2i> queue;
    std::vector<sf::Vector2i> path;
    queue.push(start);

    while (!queue.empty()) {
        sf::Vector2i current = queue.front();
        queue.pop();

        if (visited[current.x][current.y]) continue;

        visited[current.x][current.y] = true;
        path.push_back(current);

        if (current == end) break;

        std::vector<sf::Vector2i> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : directions) {
            sf::Vector2i next = {current.x + dir.x, current.y + dir.y};
            if (next.x >= 0 && next.y >= 0 && next.x < rows && next.y < cols && !visited[next.x][next.y] && !walls[next.x][next.y]) {
                queue.push(next);
            }
        }
    }

    return path;
}

// Visualiza el laberinto
void Maze::visualize(sf::RenderWindow& window, const std::vector<sf::Vector2i>& path, bool isDFS) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            drawCell(window, {i, j}, walls[i][j] ? sf::Color::Black : sf::Color::White);
        }
    }

    // Dibuja el camino
    for (const auto& cell : path) {
        drawCell(window, cell, sf::Color::Yellow);
        window.display();
        sf::sleep(sf::milliseconds(100));
    }

    // Dibuja inicio y fin
    drawCell(window, start, sf::Color::Green);
    drawCell(window, end, sf::Color::Red);
    window.display();
}
