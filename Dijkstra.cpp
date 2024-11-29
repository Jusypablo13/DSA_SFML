#include "Dijkstra.h"
#include <queue>
#include <cmath>

Dijkstra::Dijkstra(int nodes) : numNodes(nodes) {
    graph.resize(nodes);
}

void Dijkstra::addEdge(int u, int v, int weight) {
    graph[u].emplace_back(v, weight);
    graph[v].emplace_back(u, weight); // Si es no dirigido
}

std::vector<int> Dijkstra::calculateShortestPaths(int startNode) {
    std::vector<int> distances(numNodes, std::numeric_limits<int>::max());
    std::vector<int> parents(numNodes, -1);
    distances[startNode] = 0;

    using NodeDistPair = std::pair<int, int>;
    std::priority_queue<NodeDistPair, std::vector<NodeDistPair>, std::greater<>> pq;
    pq.emplace(0, startNode);

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        if (currentDist > distances[currentNode]) continue;

        for (const auto& [neighbor, weight] : graph[currentNode]) {
            if (distances[currentNode] + weight < distances[neighbor]) {
                distances[neighbor] = distances[currentNode] + weight;
                parents[neighbor] = currentNode;
                pq.emplace(distances[neighbor], neighbor);
            }
        }
    }
    return parents;
}

void Dijkstra::visualizeGraph(sf::RenderWindow& window, const sf::Font& font, const std::vector<int>& parents, const std::vector<int>& distances) {
    float nodeRadius = 20.0f;
    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;
    float circleSpacing = 100.0f;

    std::vector<sf::Vector2f> nodePositions(numNodes);

    // Calcular posiciones de nodos en un círculo
    for (int i = 0; i < numNodes; ++i) {
        float angle = 2 * M_PI * i / numNodes;
        nodePositions[i] = sf::Vector2f(
            centerX + cos(angle) * circleSpacing,
            centerY + sin(angle) * circleSpacing
        );
    }

    // Dibujar aristas
    for (int u = 0; u < numNodes; ++u) {
        for (const auto& [v, weight] : graph[u]) {
            sf::Vertex line[] = {
                sf::Vertex(nodePositions[u], sf::Color::Yellow),
                sf::Vertex(nodePositions[v], sf::Color::Yellow)
            };
            window.draw(line, 2, sf::Lines);

            // Mostrar peso de la arista
            sf::Text edgeWeight(std::to_string(weight), font, 18);
            edgeWeight.setFillColor(sf::Color::White);
            edgeWeight.setPosition((nodePositions[u] + nodePositions[v]) / 2.0f);
            window.draw(edgeWeight);
        }
    }

    // Dibujar nodos
    for (int i = 0; i < numNodes; ++i) {
        sf::CircleShape circle(nodeRadius);
        circle.setFillColor(sf::Color::Blue);
        circle.setOrigin(nodeRadius, nodeRadius);
        circle.setPosition(nodePositions[i]);
        window.draw(circle);

        sf::Text nodeLabel(std::to_string(i), font, 18);
        nodeLabel.setFillColor(sf::Color::White);
        nodeLabel.setPosition(nodePositions[i].x - 10, nodePositions[i].y - 10);
        window.draw(nodeLabel);
    }

    // Mostrar el camino más corto
    for (int i = 0; i < numNodes; ++i) {
        if (parents[i] != -1) {
            sf::Vertex shortestPath[] = {
                sf::Vertex(nodePositions[i], sf::Color::Red),
                sf::Vertex(nodePositions[parents[i]], sf::Color::Red)
            };
            window.draw(shortestPath, 2, sf::Lines);
        }
    }

    // Mostrar distancias desde el nodo fuente
    for (int i = 0; i < numNodes; ++i) {
        sf::Text distanceText("Dist: " + std::to_string(distances[i]), font, 18);
        distanceText.setFillColor(sf::Color::Green);
        distanceText.setPosition(nodePositions[i].x, nodePositions[i].y + 20);
        window.draw(distanceText);
    }

    window.display();
}

std::pair<std::vector<int>, std::vector<int>> Dijkstra::run(int source) {
    std::vector<int> distances(numNodes, std::numeric_limits<int>::max());
    std::vector<int> parents(numNodes, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto &[v, weight] : graph[u]) {
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parents[v] = u;
                pq.push({distances[v], v});
            }
        }
    }

    return {parents, distances};
}