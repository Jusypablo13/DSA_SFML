#include "LinkedList.h"
#include <SFML/Graphics.hpp>
#include <string>

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::remove(int value) {
    Node** current = &head;
    while (*current) {
        if ((*current)->value == value) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return;
        }
        current = &((*current)->next);
    }
}

void LinkedList::draw(sf::RenderWindow &window, const sf::Font &font) const {
    Node* current = head;
    int x = 10;

    while (current) {
        sf::Text nodeValue(std::to_string(current->value), font, 20);
        nodeValue.setPosition(x, 100);
        nodeValue.setFillColor(sf::Color::White);
        window.draw(nodeValue);
        x += 50;
        current = current->next;
    }
}

void LinkedList::interactiveMode(sf::RenderWindow &window, const sf::Font &font) {
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
                        addAtHead(value);
                        userInput.clear();
                        errorText.setString(""); // Limpia cualquier mensaje de error
                    } else {
                        errorText.setString("Invalid input. Please enter a number.");
                    }
                } else if (event.key.code == sf::Keyboard::R) {
                    if (!userInput.empty() && std::all_of(userInput.begin(), userInput.end(), ::isdigit)) {
                        int value = std::stoi(userInput);
                        remove(value);
                        userInput.clear();
                        errorText.setString(""); // Limpia cualquier mensaje de error
                    } else {
                        errorText.setString("Invalid input. Please enter a number.");
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