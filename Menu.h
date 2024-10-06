#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Menu {
    private:
        int selectedOption;
        sf::Font font;
        vector<sf::Text> menuOptions;  
    public:
        Menu(float width, float height);
        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getSelectedOption() const;
};


#endif // MENU_H