#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "AlgorithmVisualizer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Visualizador de Algoritmos");

    Menu menu(800, 600);
    AlgorithmVisualizer visualizer;
    bool inMenu = true;

    while (window.isOpen()) {
        if (inMenu) {
            menu.handleInput(window, inMenu);
            window.clear();
            menu.draw(window);
            window.display();
        } else {
            int selectedOption = menu.getSelectedOption();
            if (selectedOption == 0) {  // BubbleSort
                visualizer.promptForInput(window);
                visualizer.executeAlgorithm("BubbleSort");
                visualizer.showResults(window, visualizer.getData(), "BubbleSort");
                inMenu = true;
            } else if (selectedOption == 1) {  // QuickSort
                visualizer.promptForInput(window);
                visualizer.executeAlgorithm("QuickSort");
                visualizer.showResults(window, visualizer.getData(), "QuickSort");
                inMenu = true;
            } else if (selectedOption == 2) {  // MergeSort
                visualizer.promptForInput(window);
                visualizer.executeAlgorithm("MergeSort");
                visualizer.showResults(window, visualizer.getData(), "MergeSort");
                inMenu = true;
            } else if (selectedOption == 3) {  // BinarySearch
                visualizer.promptForInput(window);
                visualizer.executeBinarySearch(window);
                inMenu = true;
            } else if (selectedOption == 4) {  // Salir
                window.close();
            }
        }
    }

    return 0;
}