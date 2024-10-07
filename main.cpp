#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "AlgorithmVisualizer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

    Menu menu(800, 600);  // Inicializa el menú
    AlgorithmVisualizer visualizer;  // Inicializa el visualizador
    bool inMenu = true;
    int selectedOption = -1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (inMenu) {
                menu.handleInput(window);  // Maneja las teclas para el menú
                selectedOption = menu.getSelectedOption();
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    inMenu = false;  // Sale del menú al presionar Enter
                }
            }
        }

        // Dibujar el menú si aún estamos en él
        if (inMenu) {
            window.clear();
            menu.draw(window);
            window.display();
        } else {
            // Ejecución del algoritmo seleccionado
            if (selectedOption == 0) {  // BubbleSort
                visualizer.promptForInput(window);
                visualizer.executeAlgorithm("BubbleSort");
                visualizer.showResults(window, visualizer.getData(), "BubbleSort");
                inMenu = true;  // Vuelve al menú al terminar
            } else if (selectedOption == 1) {  // QuickSort
                visualizer.promptForInput(window);
                visualizer.executeAlgorithm("QuickSort");
                visualizer.showResults(window, visualizer.getData(), "QuickSort");
                inMenu = true;  // Vuelve al menú al terminar
            } else if (selectedOption == 3) {  // Exit
                window.close();
            }
        }
    }

    return 0;
}