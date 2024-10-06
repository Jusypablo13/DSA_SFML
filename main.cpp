#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "AlgorithmVisualizer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");

    Menu menu(800, 600);
    AlgorithmVisualizer visualizer;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        menu.draw(window);
        window.display();

        if (menu.getSelectedOption() == 0) {  // BubbleSort
            visualizer.promptForInput();
            visualizer.executeAlgorithm("BubbleSort");
            visualizer.showResults(window, visualizer.getData(), "BubbleSort");
        } else if (menu.getSelectedOption() == 1) {  // QuickSort
            visualizer.promptForInput();
            visualizer.executeAlgorithm("QuickSort");
            visualizer.showResults(window, visualizer.getData(), "QuickSort");
        }
    }

    return 0;
}