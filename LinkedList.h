#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

class LinkedList {
public:
    LinkedList();
    void insert(int value);
    void remove(int value);
    void draw(sf::RenderWindow &window, sf::Font &font);
    void interactiveMode(sf::RenderWindow &window, sf::Font &font);

private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        Node(int val) : value(val), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    void drawNode(sf::RenderWindow &window, sf::Font &font, int value, float x, float y);
};

#endif // LINKEDLIST_H
