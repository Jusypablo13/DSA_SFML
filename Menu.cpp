#include "Menu.h"

Menu::Menu(const std::vector<std::string>& options, float width, float height)
    : selectedOption(0), width(width), height(height) {
    font.loadFromFile("arial.ttf");

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(30);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        text.setPosition(width / 2 - 100, height / (options.size() + 1) * (i + 1));
        menuOptions.push_back(text);
    }
}

void Menu::moveUp() {
    if (selectedOption - 1 >= 0) {
        menuOptions[selectedOption].setFillColor(sf::Color::White);
        selectedOption--;
        menuOptions[selectedOption].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedOption + 1 < menuOptions.size()) {
        menuOptions[selectedOption].setFillColor(sf::Color::White);
        selectedOption++;
        menuOptions[selectedOption].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedOption() const {
    return selectedOption;
}

void Menu::draw(sf::RenderWindow& window) {
    for (const auto& option : menuOptions) {
        window.draw(option);
    }
}
