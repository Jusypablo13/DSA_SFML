#include "Menu.h"
#include "AlgorithmVisualizer.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "AVLTree.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Structures and Algorithms");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Menú principal
    Menu mainMenu({"Search Algorithms", "Sorting Algorithms", "Linear Structures", "Non-Linear Structures", "Exit"}, window.getSize().x, window.getSize().y);

    AlgorithmVisualizer visualizer;
    LinkedList linkedList;
    Stack stack;
    Queue queue;
    AVLTree avlTree;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.moveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.moveDown();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    int mainMenuIndex = mainMenu.getSelectedIndex();

                    // Search Algorithms
                    if (mainMenuIndex == 0) {
                        Menu searchMenu({"Linear Search", "Binary Search", "Back"}, window.getSize().x, window.getSize().y);
                        bool inSearchMenu = true;

                        while (window.isOpen() && inSearchMenu) {
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        searchMenu.moveUp();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        searchMenu.moveDown();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        int searchMenuIndex = searchMenu.getSelectedIndex();

                                        if (searchMenuIndex == 0) { // Linear Search
                                            visualizer.runLinearSearch(window, font);
                                        } else if (searchMenuIndex == 1) { // Binary Search
                                            visualizer.runBinarySearch(window, font);
                                        } else if (searchMenuIndex == 2) { // Back
                                            inSearchMenu = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        inSearchMenu = false; // Salir del submenú
                                    }
                                }
                            }

                            if (!inSearchMenu) break;

                            window.clear();
                            searchMenu.draw(window, font);
                            window.display();
                        }
                    }
                    // Sorting Algorithms
                    else if (mainMenuIndex == 1) {
                        Menu sortingMenu({"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Back"}, window.getSize().x, window.getSize().y);
                        bool inSortingMenu = true;

                        while (window.isOpen() && inSortingMenu) {
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        sortingMenu.moveUp();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        sortingMenu.moveDown();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        int sortingMenuIndex = sortingMenu.getSelectedIndex();

                                        if (sortingMenuIndex == 0) { // Bubble Sort
                                            visualizer.runBubbleSort(window, font);
                                        } else if (sortingMenuIndex == 1) { // Selection Sort
                                            visualizer.runSelectionSort(window, font);
                                        } else if (sortingMenuIndex == 2) { // Insertion Sort
                                            visualizer.runInsertionSort(window, font);
                                        } else if (sortingMenuIndex == 3) { // Merge Sort
                                            visualizer.runMergeSort(window, font);
                                        } else if (sortingMenuIndex == 4) { // Quick Sort
                                            visualizer.runQuickSort(window, font);
                                        } else if (sortingMenuIndex == 5) { // Back
                                            inSortingMenu = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        inSortingMenu = false; // Salir del submenú
                                    }
                                }
                            }

                            if (!inSortingMenu) break;

                            window.clear();
                            sortingMenu.draw(window, font);
                            window.display();
                        }
                    }
                    // Linear Structures
                    else if (mainMenuIndex == 2) {
                        Menu linearMenu({"Linked List", "Stack", "Queue", "Back"}, window.getSize().x, window.getSize().y);
                        bool inLinearMenu = true;

                        while (window.isOpen() && inLinearMenu) {
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        linearMenu.moveUp();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        linearMenu.moveDown();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        int linearMenuIndex = linearMenu.getSelectedIndex();

                                        if (linearMenuIndex == 0) { // Linked List
                                            linkedList.interactiveMode(window, font);
                                        } else if (linearMenuIndex == 1) { // Stack
                                            stack.interactiveMode(window, font);
                                        } else if (linearMenuIndex == 2) { // Queue
                                            queue.interactiveMode(window, font);
                                        } else if (linearMenuIndex == 3) { // Back
                                            inLinearMenu = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        inLinearMenu = false; // Salir del submenú
                                    }
                                }
                            }

                            if (!inLinearMenu) break;

                            window.clear();
                            linearMenu.draw(window, font);
                            window.display();
                        }
                    }
                    // Non-Linear Structures
                    else if (mainMenuIndex == 3) {
                        Menu nonLinearMenu({"AVL Tree", "Back"}, window.getSize().x, window.getSize().y);
                        bool inNonLinearMenu = true;

                        while (window.isOpen() && inNonLinearMenu) {
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }

                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        nonLinearMenu.moveUp();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        nonLinearMenu.moveDown();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        int nonLinearMenuIndex = nonLinearMenu.getSelectedIndex();

                                        if (nonLinearMenuIndex == 0) { // AVL Tree
                                            avlTree.interactiveMode(window, font);
                                        } else if (nonLinearMenuIndex == 1) { // Back
                                            inNonLinearMenu = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        inNonLinearMenu = false; // Salir del submenú
                                    }
                                }
                            }

                            if (!inNonLinearMenu) break;

                            window.clear();
                            nonLinearMenu.draw(window, font);
                            window.display();
                        }
                    }
                    // Exit
                    else if (mainMenuIndex == 4) {
                        window.close();
                    }
                } else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear();
        mainMenu.draw(window, font);
        window.display();
    }

    return 0;
}
