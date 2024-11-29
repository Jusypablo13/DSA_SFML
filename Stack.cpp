#include "Stack.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Stack::interactiveMode(sf::RenderWindow &window, const sf::Font &font) {
    bool running = true;
    std::string userInput;
    sf::Text instructions("Press A to Add, R to Remove, Esc to Exit.", font, 20);
    instructions.setPosition(10, 10);
    instructions.setFillColor(sf::Color::White);

    sf::Text inputText("", font, 20);
    inputText.setPosition(10, 40);
    inputText.setFillColor(sf::Color::Yellow);

    sf::Text errorText("", font, 20);
    errorText.setPosition(10, 70);
    errorText.setFillColor(sf::Color::Red);

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
                        push(value);
                        userInput.clear();
                        errorText.setString(""); // Limpia cualquier mensaje de error
                    } else {
                        errorText.setString("Invalid input. Please enter a number.");
                    }
                } else if (event.key.code == sf::Keyboard::R) {
                    if (!isEmpty()) {
                        pop();
                        errorText.setString(""); // Limpia cualquier mensaje de error
                    } else {
                        errorText.setString("The stack is empty. Cannot remove.");
                    }
                }
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !userInput.empty()) {
                    userInput.pop_back();
                } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                    char enteredChar = static_cast<char>(event.text.unicode);
                    if (isdigit(enteredChar) || (enteredChar == '-' && userInput.empty())) {
                        userInput += enteredChar;
                    }
                }
            }
        }

        inputText.setString("Input: " + userInput);

        window.clear();
        draw(window, font);
        window.draw(instructions);
        window.draw(inputText);
        window.draw(errorText);
        window.display();
    }
}

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

bool Stack::isEmpty() const {
    return data.empty();
}

void Stack::draw(sf::RenderWindow &window, const sf::Font &font) const {
    float x = 200;
    float y = 400;

    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        sf::RectangleShape block(sf::Vector2f(100, 50));
        block.setPosition(x, y);
        block.setFillColor(sf::Color::Green);

        sf::Text blockText(std::to_string(*it), font, 20);
        blockText.setPosition(x + 25, y + 10);

        window.draw(block);
        window.draw(blockText);

        y -= 60;
    }
}