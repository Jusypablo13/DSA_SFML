#include "AlgorithmVisualizer.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std;

void AlgorithmVisualizer::runLinearSearch(sf::RenderWindow& window) {
    promptForInput(window);
    int target = promptForTarget(window);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text prompt("Linear Search", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    bool found = false;
    for (int i = 0; i < data.size(); ++i) {
        displayArray(window, data, i);
        if (data[i] == target) {
            found = true;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    stats.stopTimer();

    sf::Text result(found ? "Element found." : "Element not found.", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n), Space Complexity: O(1)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();

    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runBinarySearch(sf::RenderWindow& window) {
    promptForInput(window);
    sort(data.begin(), data.end());
    int target = promptForTarget(window);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text prompt("Binary Search", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    bool found = false;
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        displayArray(window, data, mid);
        if (data[mid] == target) {
            found = true;
            break;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    stats.stopTimer();

    sf::Text result(found ? "Element found." : "Element not found.", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(log n), Space Complexity: O(1)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();

    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runBubbleSort(sf::RenderWindow& window) {
    BubbleSort bubbleSort;
    promptForInput(window);
    stats.startTimer();
    bubbleSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text result("Bubble Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runSelectionSort(sf::RenderWindow& window) {
    SelectionSort selectionSort;
    promptForInput(window);
    stats.startTimer();
    selectionSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text result("Selection Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runInsertionSort(sf::RenderWindow& window) {
    InsertionSort insertionSort;
    promptForInput(window);
    stats.startTimer();
    insertionSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text result("Insertion Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runMergeSort(sf::RenderWindow& window) {
    MergeSort mergeSort;
    promptForInput(window);
    stats.startTimer();
    mergeSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text result("Merge Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n log n), Space Complexity: O(n)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(3));
}

void AlgorithmVisualizer::runQuickSort(sf::RenderWindow& window) {
    QuickSort quickSort;
    promptForInput(window);
    stats.startTimer();
    quickSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text result("Quick Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + to_string(stats.getExecutionTime()) + " seconds", font, 24);
    executionTime.setPosition(50, 530);

    sf::Text complexity("Time Complexity: O(n log n), Space Complexity: O(log n)", font, 24);
    complexity.setPosition(50, 560);

    window.clear();
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(3));
}