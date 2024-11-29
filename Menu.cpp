#include "Menu.h"

Menu::Menu(float width, float height) : selectedOption(0), width(width), height(height) {
    font.loadFromFile("arial.ttf");  // Asegúrate de que el archivo "arial.ttf" esté disponible
}

void Menu::setOptions(const vector<string>& options) {
    menuOptions.clear();
    for (int i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(24);
        text.setPosition(sf::Vector2f(width / 2 - 100, height / (options.size() + 1) * (i + 1)));  // Centrado aproximado
        menuOptions.push_back(text);
    }
}

void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < menuOptions.size(); ++i) {
        if (i == selectedOption) {
            menuOptions[i].setFillColor(sf::Color::Red);  // Opción seleccionada en rojo
        } else {
            menuOptions[i].setFillColor(sf::Color::White);  // Opciones no seleccionadas en blanco
        }
        window.draw(menuOptions[i]);  // Dibuja cada opción
    }
}

void Menu::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            // Movimiento con teclas de flecha
            if (event.key.code == sf::Keyboard::Up) {
                if (selectedOption > 0) {
                    selectedOption--;
                }
            } else if (event.key.code == sf::Keyboard::Down) {
                if (selectedOption < menuOptions.size() - 1) {
                    selectedOption++;
                }
            }
        } else if (event.type == sf::Event::MouseMoved) {
            // Detectar si el mouse pasa sobre una opción
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (int i = 0; i < menuOptions.size(); ++i) {
                sf::FloatRect textBounds = menuOptions[i].getGlobalBounds();
                if (textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    selectedOption = i;  // Cambia la opción seleccionada al pasar el mouse
                }
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Detectar si se hace clic en una opción
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (int i = 0; i < menuOptions.size(); ++i) {
                    sf::FloatRect textBounds = menuOptions[i].getGlobalBounds();
                    if (textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        selectedOption = i;  // Cambia la opción seleccionada
                    }
                }
            }
        }
    }
}

int Menu::getSelectedOption() const {
    return selectedOption;
}
