#include "LinkedList.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(int value) {
    auto newNode = std::make_shared<Node>(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::remove(int value) {
    auto current = head;
    std::shared_ptr<Node> prev = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

void LinkedList::draw(sf::RenderWindow &window, sf::Font &font) {
    auto current = head;
    float x = 50.0f, y = 200.0f;

    while (current != nullptr) {
        drawNode(window, font, current->value, x, y);
        x += 100.0f;
        current = current->next;
    }
}

void LinkedList::drawNode(sf::RenderWindow &window, sf::Font &font, int value, float x, float y) {
    sf::RectangleShape rect(sf::Vector2f(80, 40));
    rect.setFillColor(sf::Color::White);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(2);
    rect.setPosition(x, y);

    sf::Text text(std::to_string(value), font, 20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 20, y + 5);

    window.draw(rect);
    window.draw(text);
}

void LinkedList::interactiveMode(sf::RenderWindow &window, sf::Font &font) {
    std::string input;
    sf::Text prompt("", font, 20);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(50, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (std::isdigit(event.text.unicode) || event.text.unicode == '-') {
                    input += static_cast<char>(event.text.unicode);
                } else if (event.text.unicode == '\b' && !input.empty()) {
                    input.pop_back();
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                try {
                    int value = std::stoi(input);
                    insert(value);
                    input.clear();
                } catch (const std::invalid_argument &) {
                    input.clear();
                }
            }
        }

        window.clear();
        draw(window, font);
        prompt.setString("Enter a number to add: " + input);
        window.draw(prompt);
        window.display();
    }
}
