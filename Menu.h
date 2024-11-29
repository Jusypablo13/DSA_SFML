#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
public:
    Menu(const std::vector<std::string>& options, float width, float height);

    void moveUp();
    void moveDown();
    int getSelectedOption() const;
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::Text> menuOptions;
    sf::Font font;
    int selectedOption;
    float width, height;
};

#endif
