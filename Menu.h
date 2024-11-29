#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
private:
    std::vector<std::string> options;
    sf::Text menuText;
    sf::Font font;
    int selectedIndex;

public:
    Menu(const std::vector<std::string>& options, float width, float height);
    void draw(sf::RenderWindow& window, const sf::Font& font); // Ahora acepta font como parámetro
    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
};

#endif // MENU_H
