#include "Menu.h"

Menu::Menu(float width, float height) {
    selectedOption = 0;
    if (font.loadFromFile("arial.ttf")) {
        vector<string> options = {"BubbleSort", "QuickSort", "MergeSort", "BinarySearch", "Salir"};
        for (int i = 0; i < options.size(); i++) {
            sf::Text text;
            text.setFont(font);
            text.setString(options[i]);
            text.setCharacterSize(24);
            text.setPosition(sf::Vector2f(width / 2 - 50, height / (options.size() + 1) * (i + 1)));
            menuOptions.push_back(text);
        }
    }
}

void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < menuOptions.size(); i++) {
        if (i == selectedOption) {
            menuOptions[i].setFillColor(sf::Color::Red);
        } else {
            menuOptions[i].setFillColor(sf::Color::White);
        }
        window.draw(menuOptions[i]);
    }
}

void Menu::moveUp() {
    if (selectedOption > 0) {
        selectedOption--;
    }
}

void Menu::moveDown() {
    if (selectedOption < menuOptions.size() - 1) {
        selectedOption++;
    }
}

int Menu::getSelectedOption() const {
    return selectedOption;
}

void Menu::handleInput(sf::RenderWindow &window, bool &inMenu) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Maneja teclas de flecha para moverse por el menú
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                moveUp();
            } else if (event.key.code == sf::Keyboard::Down) {
                moveDown();
            } else if (event.key.code == sf::Keyboard::Enter) {
                // El usuario ha presionado Enter para seleccionar la opción actual
                inMenu = false;
            }
        }
    }
}