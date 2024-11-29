#ifndef AVLTREE_H
#define AVLTREE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class AVLTree {
public:
    AVLTree();
    void interactiveMode(sf::RenderWindow &window, const sf::Font &font);
    void draw(sf::RenderWindow &window, const sf::Font &font) const;

private:
    struct Node {
        int value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        int height;

        Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
    };

    std::shared_ptr<Node> root;

    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, int value);
    std::shared_ptr<Node> remove(std::shared_ptr<Node> node, int value);
    int getHeight(std::shared_ptr<Node> node) const;
    int getBalanceFactor(std::shared_ptr<Node> node) const;
    std::shared_ptr<Node> rotateRight(std::shared_ptr<Node> y);
    std::shared_ptr<Node> rotateLeft(std::shared_ptr<Node> x);
};

#endif
