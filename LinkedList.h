#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <SFML/Graphics.hpp>

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void addAtHead(int value);
    void remove(int value);
    void draw(sf::RenderWindow &window, const sf::Font &font) const;
    void interactiveMode(sf::RenderWindow &window, const sf::Font &font);
};

#endif
