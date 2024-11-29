#ifndef STACK_H
#define STACK_H

#include <SFML/Graphics.hpp>
#include <vector>

class Stack {
public:
    void interactiveMode(sf::RenderWindow &window, const sf::Font &font);
    void push(int value);
    void pop();
    void draw(sf::RenderWindow &window, const sf::Font &font) const;
    bool isEmpty() const;

private:
    std::vector<int> data;
    void drawBlock(sf::RenderWindow &window, sf::Font &font, int value, float x, float y);
};

#endif // STACK_H
