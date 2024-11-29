#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;

class Menu {
public:
    Menu(float width, float height);
    void setOptions(const vector<string>& options);  // Establecer opciones dinámicamente
    void draw(sf::RenderWindow &window);            // Dibuja el menú
    void handleInput(sf::RenderWindow &window);     // Maneja la entrada del usuario (teclado y mouse)
    int getSelectedOption() const;                  // Devuelve la opción seleccionada

private:
    int selectedOption;                             // Opción actualmente seleccionada
    sf::Font font;                                  // Fuente para el texto
    vector<sf::Text> menuOptions;                   // Opciones del menú
    float width, height;                            // Dimensiones del menú
};

#endif
