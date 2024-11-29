#include "Menu.h"

Menu::Menu(const std::vector<std::string>& options, float width, float height)
    : options(options), selectedIndex(0) {
    font.loadFromFile("Arial.ttf");
    menuText.setFont(font);
    menuText.setCharacterSize(24);
    menuText.setFillColor(sf::Color::White);
    menuText.setPosition(width / 4, height / 4);
}

void Menu::draw(sf::RenderWindow& window, const sf::Font& font) {
    for (size_t i = 0; i < options.size(); ++i) {
        menuText.setString(options[i]);
        menuText.setFont(font); // Se asegura de usar la fuente proporcionada
        menuText.setFillColor(i == selectedIndex ? sf::Color::Red : sf::Color::White);
        menuText.setPosition(200, 100 + i * 50);
        window.draw(menuText);
    }
}

void Menu::moveUp() {
    if (selectedIndex > 0) {
        selectedIndex--;
    }
}

void Menu::moveDown() {
    if (selectedIndex < options.size() - 1) {
        selectedIndex++;
    }
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}
