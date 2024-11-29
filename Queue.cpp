#include "Queue.h"
#include <SFML/Graphics.hpp>

void Queue::enqueue(int value) {
    data.push_back(value);
}

void Queue::dequeue() {
    if (!data.empty()) {
        data.erase(data.begin());
    }
}

void Queue::draw(sf::RenderWindow &window, sf::Font &font) {
    float x = 50.0f, y = 400.0f;

    for (const auto &value : data) {
        drawBlock(window, font, value, x, y);
        x += 100.0f; // Space between blocks
    }
}

void Queue::drawBlock(sf::RenderWindow &window, sf::Font &font, int value, float x, float y) {
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

void Queue::interactiveMode(sf::RenderWindow &window, sf::Font &font) {
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

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (!input.empty()) {
                        enqueue(std::stoi(input));
                        input.clear();
                    }
                } else if (event.key.code == sf::Keyboard::BackSpace) {
                    dequeue();
                }
            }
        }

        window.clear();
        draw(window, font);
        prompt.setString("Enter a number to enqueue: " + input + " (Press Backspace to dequeue)");
        window.draw(prompt);
        window.display();
    }
}
