#include "AlgorithmVisualizer.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

void AlgorithmVisualizer::promptForInput(sf::RenderWindow& window, sf::Font& font) {
    data.clear();

    sf::Text prompt("Enter number of elements:", font, 24);
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
            window.draw(elementPrompt);
            inputText.setString(userInput);
            window.draw(inputText);
            window.display();
        }

        data.push_back(stoi(userInput));
        displayArray(window, data);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
int AlgorithmVisualizer::promptForTarget(sf::RenderWindow& window, sf::Font& font) {
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

void AlgorithmVisualizer::runSearchAlgorithms(sf::RenderWindow& window,  sf::Font& font) {
    std::vector<std::string> searchOptions = {"Linear Search", "Binary Search", "Back"};
    Menu searchMenu(searchOptions, window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    searchMenu.moveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    searchMenu.moveDown();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    int selectedIndex = searchMenu.getSelectedIndex();
                    if (selectedIndex == 0) {
                        // Ejecuta Linear Search
                    } else if (selectedIndex == 1) {
                        // Ejecuta Binary Search
                    } else if (selectedIndex == 2) {
                        return; // Regresa al menú principal
                    }
                }
            }
        }

        window.clear();
        searchMenu.draw(window, font);
        window.display();
    }
}

void AlgorithmVisualizer::runSortingAlgorithms(sf::RenderWindow& window, const sf::Font& font) {
    std::vector<std::string> sortingOptions = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Back"};
    Menu sortingMenu(sortingOptions, window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    sortingMenu.moveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    sortingMenu.moveDown();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    int selectedIndex = sortingMenu.getSelectedIndex();
                    if (selectedIndex == 0) {
                        // Ejecuta Bubble Sort
                    } else if (selectedIndex == 1) {
                        // Ejecuta Selection Sort
                    } else if (selectedIndex == 2) {
                        // Ejecuta Insertion Sort
                    } else if (selectedIndex == 3) {
                        // Ejecuta Merge Sort
                    } else if (selectedIndex == 4) {
                        // Ejecuta Quick Sort
                    } else if (selectedIndex == 5) {
                        return; // Regresa al menú principal
                    }
                }
            }
        }

        window.clear();
        sortingMenu.draw(window, font);
        window.display();
    }
}

#include "SearchAndSortMethods.cpp"