#include "Statistics.h"
#include <iostream>

void Statistics::startTimer() {
    startTime = high_resolution_clock::now();
}

void Statistics::stopTimer() {
    endTime = high_resolution_clock::now();
}

double Statistics::getExecutionTime() const {
    duration<double> time_span = duration_cast<duration<double>>(endTime - startTime);
    return time_span.count();
}

void Statistics::displayComplexity(const string &algorithm) const {
    if (algorithm == "BubbleSort") {
        cout << "Time complexity of BubbleSort is O(n^2)" << endl;
        cout << "Space complexity of BubbleSort is O(1)" << endl;
    } else if (algorithm == "QuickSort") {
        cout << "Time complexity of QuickSort is O(n log n), O(n^2) worst case scenario" << endl;
        cout << "Space complexity of QuickSort is O(log n)" << endl;
    }
    //Continuar en futuro con más algoritmos ...
}