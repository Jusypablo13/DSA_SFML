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

void AlgorithmVisualizer::runLinearSearch(sf::RenderWindow& window, sf::Font& font) {
    promptForInput(window, font);
    int target = promptForTarget(window, font);

    sf::Text prompt("Linear Search", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    bool found = false;
    int position = -1;
    for (int i = 0; i < data.size(); ++i) {
        displayArray(window, data, i);
        if (data[i] == target) {
            found = true;
            position = 1;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    stats.stopTimer();

    sf::Text result(found ? "Element found at position: " + std::to_string(position) : "Element not found.", font, 24);
    result.setPosition(50, 200);
    
    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);
    
    sf::Text complexity("Time Complexity: O(n), Space Complexity: O(1)", font, 20);
    complexity.setPosition(50, 300);\

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();

    this_thread::sleep_for(chrono::seconds(5));
}

void AlgorithmVisualizer::runBinarySearch(sf::RenderWindow& window, sf::Font& font) {
    promptForInput(window, font);
    sort(data.begin(), data.end());
    int target = promptForTarget(window, font);

    sf::Text prompt("Binary Search", font, 24);
    prompt.setPosition(50, 50);


    stats.startTimer();
    bool found = false;
    int left = 0, right = data.size() - 1;
    int mid = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        displayArray(window, data, mid);
        if (data[mid] == target) {
            found = true;
            break;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    stats.stopTimer();

    sf::Text result(found ? "Element found at position " + std::to_string(mid) : "Element not found", font, 20);
    result.setPosition(50, 200);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(log n), Space Complexity: O(1)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();

    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void AlgorithmVisualizer::runBubbleSort(sf::RenderWindow& window, sf::Font& font) {
    BubbleSort bubbleSort;
    promptForInput(window, font);

    sf::Text prompt("Bubble Sort", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    bubbleSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Text result("Bubble Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();

    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void AlgorithmVisualizer::runSelectionSort(sf::RenderWindow& window, sf::Font& font) {
    SelectionSort selectionSort;
    promptForInput(window, font);

    sf::Text prompt("Selection Sort", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    selectionSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Text result("Selection Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(5));
}

void AlgorithmVisualizer::runInsertionSort(sf::RenderWindow& window, sf::Font& font) {
    InsertionSort insertionSort;
    promptForInput(window, font);

    sf::Text prompt("Insertion Sort", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    insertionSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Text result("Insertion Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(n^2), Space Complexity: O(1)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(5));
}

void AlgorithmVisualizer::runMergeSort(sf::RenderWindow& window, sf::Font& font) {
    MergeSort mergeSort;
    promptForInput(window, font);

    sf::Text prompt("Merge Sort", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    mergeSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Text result("Merge Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(n log n), Space Complexity: O(n)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(5));
}

void AlgorithmVisualizer::runQuickSort(sf::RenderWindow& window, sf::Font& font) {
    QuickSort quickSort;
    promptForInput(window, font);

    sf::Text prompt("Quick Sort", font, 24);
    prompt.setPosition(50, 50);

    stats.startTimer();
    quickSort.sortWithVisualization(data, window, *this);
    stats.stopTimer();

    sf::Text result("Quick Sort Complete!", font, 24);
    result.setPosition(50, 500);

    sf::Text executionTime("Execution Time: " + std::to_string(stats.getExecutionTime()) + " seconds", font, 20);
    executionTime.setPosition(50, 250);

    sf::Text complexity("Time Complexity: O(n log n), Space Complexity: O(log n)", font, 20);
    complexity.setPosition(50, 300);

    window.clear();
    window.draw(prompt);
    window.draw(result);
    window.draw(executionTime);
    window.draw(complexity);
    window.display();
    this_thread::sleep_for(chrono::seconds(5));
}