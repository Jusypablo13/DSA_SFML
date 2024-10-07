#include "Menu.h"

Menu::Menu(float width, float height) {
    selectedOption = 0;
    if (font.loadFromFile("arial.ttf")) {
        vector<string> options = {"BubbleSort", "QuickSort", "MergeSort", "Exit"};
        for (int i = 0; i < options.size(); i++) {
            sf::Text text;
            text.setFont(font);
            text.setString(options[i]);
            text.setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * (i + 1)));
            menuOptions.push_back(text);
        }
    }
}

void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < menuOptions.size(); i++) {
        if (i == selectedOption) {
            menuOptions[i].setFillColor(sf::Color::Red);  // Opción seleccionada en rojo
        } else {
            menuOptions[i].setFillColor(sf::Color::White);  // Opción no seleccionada en blanco
        }
        window.draw(menuOptions[i]);  // Dibuja la opción
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

void Menu::handleInput(sf::RenderWindow &window) {
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
                int selected = getSelectedOption();
                if (selected == 0) {
                    // BubbleSort seleccionado
                    // Ejecutar la lógica para BubbleSort
                } else if (selected == 1) {
                    // QuickSort seleccionado
                    // Ejecutar la lógica para QuickSort
                } else if (selected == 2) {
                    // MergeSort seleccionado
                    // Ejecutar la lógica para MergeSort
                } else if (selected == 3) {
                    // Exit seleccionado
                    window.close();
                }
            }
        }

        // Manejar selección directa con teclas específicas (B para BubbleSort, Q para QuickSort, etc.)
        if (event.type == sf::Event::TextEntered) {
            char inputChar = static_cast<char>(event.text.unicode);
            inputChar = tolower(inputChar);  // Convierte la entrada a minúscula
            if (inputChar == 'b') {
                selectedOption = 0;  // Selecciona BubbleSort
            } else if (inputChar == 'q') {
                selectedOption = 1;  // Selecciona QuickSort
            } else if (inputChar == 'm') {
                selectedOption = 2;  // Selecciona MergeSort
            } else if (inputChar == 'e') {
                selectedOption = 3;  // Selecciona Exit
            }
        }
    }
}