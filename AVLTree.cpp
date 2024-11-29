#include "AVLTree.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>

AVLTree::AVLTree() : root(nullptr) {}

void AVLTree::interactiveMode(sf::RenderWindow &window, const sf::Font &font) {
    bool running = true;
    std::string userInput;
    sf::Text instructions("Press A to Add, R to Remove, Esc to Exit.", font, 20);
    instructions.setPosition(10, 10);
    instructions.setFillColor(sf::Color::White);

    sf::Text inputText("", font, 20);
    inputText.setPosition(10, 40);
    inputText.setFillColor(sf::Color::Yellow);

    while (running && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    running = false;
                } else if (event.key.code == sf::Keyboard::A) {
                    if (!userInput.empty() && std::all_of(userInput.begin(), userInput.end(), ::isdigit)) {
                        int value = std::stoi(userInput);
                        root = insert(root, value);
                        userInput.clear();
                    }
                } else if (event.key.code == sf::Keyboard::R) {
                    if (!userInput.empty() && std::all_of(userInput.begin(), userInput.end(), ::isdigit)) {
                        int value = std::stoi(userInput);
                        root = remove(root, value);
                        userInput.clear();
                    }
                }
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !userInput.empty()) {
                    userInput.pop_back();
                } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                    userInput += static_cast<char>(event.text.unicode);
                }
            }
        }

        inputText.setString("Input: " + userInput);

        window.clear();
        draw(window, font);
        window.draw(instructions);
        window.draw(inputText);
        window.display();
    }
}

void AVLTree::draw(sf::RenderWindow &window, const sf::Font &font) const {
    if (!root) return;

    // Coordenadas iniciales y desplazamiento
    float startX = window.getSize().x / 2.0f;
    float startY = 50.0f;
    float xOffset = 150.0f;

    // Llamada recursiva para dibujar el árbol
    std::function<void(std::shared_ptr<Node>, float, float, float)> drawNode = [&](std::shared_ptr<Node> node, float x, float y, float offset) {
        if (!node) return;

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(x - 20, y - 20);

        sf::Text valueText(std::to_string(node->value), font, 20);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(x - 10, y - 15);

        if (node->left) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
                sf::Vertex(sf::Vector2f(x - offset, y + 100), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->left, x - offset, y + 100, offset / 1.5f);
        }

        if (node->right) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
                sf::Vertex(sf::Vector2f(x + offset, y + 100), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->right, x + offset, y + 100, offset / 1.5f);
        }

        window.draw(circle);
        window.draw(valueText);
    };

    drawNode(root, startX, startY, xOffset);
}

std::shared_ptr<AVLTree::Node> AVLTree::insert(std::shared_ptr<Node> node, int value) {
    if (!node) return std::make_shared<Node>(value);

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node; // No duplicados
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    // Balanceos
    if (balance > 1 && value < node->left->value)
        return rotateRight(node);
    if (balance < -1 && value > node->right->value)
        return rotateLeft(node);
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

std::shared_ptr<AVLTree::Node> AVLTree::remove(std::shared_ptr<Node> node, int value) {
    if (!node) return node;

    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left || !node->right) {
            std::shared_ptr<Node> temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node.reset();
            } else {
                node = temp;
            }
        } else {
            std::shared_ptr<Node> temp = node->right;
            while (temp->left) temp = temp->left;
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    // Balanceos
    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rotateRight(node);
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return rotateLeft(node);
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

int AVLTree::getHeight(std::shared_ptr<Node> node) const {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(std::shared_ptr<Node> node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

std::shared_ptr<AVLTree::Node> AVLTree::rotateRight(std::shared_ptr<Node> y) {
    std::shared_ptr<Node> x = y->left;
    std::shared_ptr<Node> T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

std::shared_ptr<AVLTree::Node> AVLTree::rotateLeft(std::shared_ptr<Node> x) {
    std::shared_ptr<Node> y = x->right;
    std::shared_ptr<Node> T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}