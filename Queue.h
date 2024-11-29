#ifndef QUEUE_H
#define QUEUE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Queue {
public:
    void interactiveMode(sf::RenderWindow &window, const sf::Font &font);
    void enqueue(int value);
    void dequeue();
    void draw(sf::RenderWindow &window, const sf::Font &font) const;
    bool isEmpty() const;

private:
    std::vector<int> data;
    void drawBlock(sf::RenderWindow &window, sf::Font &font, int value, float x, float y);
};

#endif // QUEUE_H
