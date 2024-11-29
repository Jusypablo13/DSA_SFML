#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "AlgorithmVisualizer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Structures & Algorithms");

    // Menú principal
    Menu mainMenu(800, 600);
    vector<string> mainOptions = {
        "Algoritmos de Búsqueda",
        "Algoritmos de Ordenamiento",
        "Estructuras Lineales",
        "Estructuras No Lineales"
    };
    mainMenu.setOptions(mainOptions);

    // Submenú: Algoritmos de Búsqueda
    Menu searchMenu(800, 600);
    vector<string> searchOptions = {"Linear Search", "Binary Search", "Back to Main Menu"};
    searchMenu.setOptions(searchOptions);

    // Submenú: Algoritmos de Ordenamiento
    Menu sortMenu(800, 600);
    vector<string> sortOptions = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Back to Main Menu"};
    sortMenu.setOptions(sortOptions);

    // Estados del programa
    bool inMenu = true;
    bool inSubmenu = false;
    int selectedMainOption = -1;
    int selectedSubOption = -1;

    // Visualizador de Algoritmos
    AlgorithmVisualizer visualizer;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Menú principal
            if (inMenu) {
                mainMenu.handleInput(window);
                selectedMainOption = mainMenu.getSelectedOption();

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (selectedMainOption == 0) {  // Algoritmos de Búsqueda
                        inMenu = false;
                        inSubmenu = true;
                    } else if (selectedMainOption == 1) {  // Algoritmos de Ordenamiento
                        inMenu = false;
                        inSubmenu = true;
                    }
                }
            }

            // Submenú: Algoritmos de Búsqueda
            else if (inSubmenu && selectedMainOption == 0) {
                searchMenu.handleInput(window);
                selectedSubOption = searchMenu.getSelectedOption();

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (selectedSubOption == 0) {  // Linear Search
                        visualizer.runLinearSearch(window);
                    } else if (selectedSubOption == 1) {  // Binary Search
                        visualizer.runBinarySearch(window);
                    } else if (selectedSubOption == 2) {  // Back to Main Menu
                        inSubmenu = false;
                        inMenu = true;
                    }
                }
            }

            // Submenú: Algoritmos de Ordenamiento
            else if (inSubmenu && selectedMainOption == 1) {
                sortMenu.handleInput(window);
                selectedSubOption = sortMenu.getSelectedOption();

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (selectedSubOption == 0) {  // Bubble Sort
                        visualizer.runBubbleSort(window);
                    } else if (selectedSubOption == 1) {  // Selection Sort
                        visualizer.runSelectionSort(window);
                    } else if (selectedSubOption == 2) {  // Insertion Sort
                        visualizer.runInsertionSort(window);
                    } else if (selectedSubOption == 3) {  // Merge Sort
                        visualizer.runMergeSort(window);
                    } else if (selectedSubOption == 4) {  // Quick Sort
                        visualizer.runQuickSort(window);
                    } else if (selectedSubOption == 5) {  // Back to Main Menu
                        inSubmenu = false;
                        inMenu = true;
                    }
                }
            }
        }

        // Dibujar las pantallas
        window.clear();
        if (inMenu) {
            mainMenu.draw(window);
        } else if (inSubmenu && selectedMainOption == 0) {
            searchMenu.draw(window);
        } else if (inSubmenu && selectedMainOption == 1) {
            sortMenu.draw(window);
        }
        window.display();
    }

    return 0;
}
