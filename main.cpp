#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "AlgorithmVisualizer.h"

void drawMenu(sf::RenderWindow &window, const sf::Font &font, const std::vector<std::string> &options, int selectedIndex) {
    window.clear();
    sf::Text title("Main Menu", font, 30);
    title.setPosition(300, 50);
    window.draw(title);

    for (size_t i = 0; i < options.size(); i++) {
        sf::Text option(options[i], font, 20);
        option.setPosition(100, 150 + i * 50);
        if (i == selectedIndex) {
            option.setFillColor(sf::Color::Red);
        } else {
            option.setFillColor(sf::Color::White);
        }
        window.draw(option);
    }
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Data Structures & Algorithms Visualizer");
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")) {
        // Handle error if font cannot be loaded
        return -1;
    }

    AlgorithmVisualizer algorithmVisualizer;
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    std::vector<std::string> mainMenu = {"Search Algorithms", "Sorting Algorithms", "Linear Structures", "Exit"};
    int selectedIndex = 0;

    bool running = true;
    while (running && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                running = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + mainMenu.size()) % mainMenu.size();
                } else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % mainMenu.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedIndex == 0) { // Search Algorithms
                        std::vector<std::string> searchMenu = {"Linear Search", "Binary Search", "Back"};
                        int searchIndex = 0;
                        bool searchRunning = true;

                        while (searchRunning && window.isOpen()) {
                            drawMenu(window, font, searchMenu, searchIndex);
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        searchIndex = (searchIndex - 1 + searchMenu.size()) % searchMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        searchIndex = (searchIndex + 1) % searchMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        if (searchIndex == 0) {
                                            algorithmVisualizer.runLinearSearch(window);
                                        } else if (searchIndex == 1) {
                                            algorithmVisualizer.runBinarySearch(window);
                                        } else if (searchIndex == 2) {
                                            searchRunning = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        searchRunning = false;
                                    }
                                }
                            }
                        }
                    } else if (selectedIndex == 1) { // Sorting Algorithms
                        std::vector<std::string> sortingMenu = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Back"};
                        int sortingIndex = 0;
                        bool sortingRunning = true;

                        while (sortingRunning && window.isOpen()) {
                            drawMenu(window, font, sortingMenu, sortingIndex);
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        sortingIndex = (sortingIndex - 1 + sortingMenu.size()) % sortingMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        sortingIndex = (sortingIndex + 1) % sortingMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        if (sortingIndex == 0) {
                                            algorithmVisualizer.runBubbleSort(window);
                                        } else if (sortingIndex == 1) {
                                            algorithmVisualizer.runSelectionSort(window);
                                        } else if (sortingIndex == 2) {
                                            algorithmVisualizer.runInsertionSort(window);
                                        } else if (sortingIndex == 3) {
                                            algorithmVisualizer.runMergeSort(window);
                                        } else if (sortingIndex == 4) {
                                            algorithmVisualizer.runQuickSort(window);
                                        } else if (sortingIndex == 5) {
                                            sortingRunning = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        sortingRunning = false;
                                    }
                                }
                            }
                        }
                    } else if (selectedIndex == 2) { // Linear Structures
                        std::vector<std::string> structuresMenu = {"Linked List", "Stack", "Queue", "Back"};
                        int structuresIndex = 0;
                        bool structuresRunning = true;

                        while (structuresRunning && window.isOpen()) {
                            drawMenu(window, font, structuresMenu, structuresIndex);
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::KeyPressed) {
                                    if (event.key.code == sf::Keyboard::Up) {
                                        structuresIndex = (structuresIndex - 1 + structuresMenu.size()) % structuresMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Down) {
                                        structuresIndex = (structuresIndex + 1) % structuresMenu.size();
                                    } else if (event.key.code == sf::Keyboard::Enter) {
                                        if (structuresIndex == 0) {
                                            linkedList.interactiveMode(window, font);
                                        } else if (structuresIndex == 1) {
                                            stack.interactiveMode(window, font);
                                        } else if (structuresIndex == 2) {
                                            queue.interactiveMode(window, font);
                                        } else if (structuresIndex == 3) {
                                            structuresRunning = false;
                                        }
                                    } else if (event.key.code == sf::Keyboard::Escape) {
                                        structuresRunning = false;
                                    }
                                }
                            }
                        }
                    } else if (selectedIndex == 3) { // Exit
                        running = false;
                    }
                }
            }
        }
        drawMenu(window, font, mainMenu, selectedIndex);
    }

    return 0;
}