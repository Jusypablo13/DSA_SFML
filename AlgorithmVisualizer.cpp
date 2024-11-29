#include "AlgorithmVisualizer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

void AlgorithmVisualizer::promptForInput(sf::RenderWindow &window) {
    data.clear();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text prompt("Enter number of elements:", font, 24);
    prompt.setPosition(50, 50);

    sf::Text inputText("", font, 24);
    inputText.setPosition(50, 100);

    string userInput;
    bool inputComplete = false;

    // Paso 1: Solicitar la cantidad de elementos
    while (window.isOpen() && !inputComplete) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !userInput.empty()) {  // Borrar carácter
                    userInput.pop_back();
                } else if (isdigit(event.text.unicode)) {
                    userInput += static_cast<char>(event.text.unicode);
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if (!userInput.empty()) {
                    inputComplete = true;
                }
            }
        }

        window.clear();
        window.draw(prompt);
        inputText.setString(userInput);
        window.draw(inputText);
        window.display();
    }

    int numElements = stoi(userInput);

    // Paso 2: Solicitar cada número
    for (int i = 0; i < numElements; ++i) {
        userInput.clear();
        inputComplete = false;

        sf::Text elementPrompt("Enter element " + to_string(i + 1) + ":", font, 24);
        elementPrompt.setPosition(50, 50);

        while (window.isOpen() && !inputComplete) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == '\b' && !userInput.empty()) {  // Borrar carácter
                        userInput.pop_back();
                    } else if (isdigit(event.text.unicode) || event.text.unicode == '-') {  // Números o negativos
                        userInput += static_cast<char>(event.text.unicode);
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (!userInput.empty()) {
                        inputComplete = true;
                    }
                }
            }

            // Mostrar el número en tiempo real
            window.clear();
            window.draw(elementPrompt);
            inputText.setString(userInput);
            window.draw(inputText);
            window.display();
        }

        data.push_back(stoi(userInput));

        // Mostrar la lista actualizada
        displayArray(window, data);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int AlgorithmVisualizer::promptForTarget(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text prompt("Enter value to search:", font, 24);
    prompt.setPosition(50, 50);

    sf::Text inputText("", font, 24);
    inputText.setPosition(50, 100);

    string userInput;
    bool inputComplete = false;

    while (window.isOpen() && !inputComplete) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !userInput.empty()) {
                    userInput.pop_back();
                } else if (isdigit(event.text.unicode) || event.text.unicode == '-') {
                    userInput += static_cast<char>(event.text.unicode);
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if (!userInput.empty()) {
                    inputComplete = true;
                }
            }
        }

        window.clear();
        window.draw(prompt);
        inputText.setString(userInput);
        window.draw(inputText);
        window.display();
    }

    return stoi(userInput);
}

void AlgorithmVisualizer::displayArray(sf::RenderWindow &window, const vector<int> &data, int highlight) {
    window.clear();
    float xPos = 50.0f;
    for (int i = 0; i < data.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(30, data[i] * 5));
        bar.setFillColor(i == highlight ? sf::Color::Red : sf::Color::White);
        bar.setPosition(xPos, 500 - data[i] * 5);
        window.draw(bar);
        xPos += 40.0f;
    }
    window.display();
}

#include "SearchAndSortMethods.cpp"