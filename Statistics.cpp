#include "Statistics.h"

void Statistics::startTimer() {
    startTime = high_resolution_clock::now();
}

void Statistics::stopTimer() {
    endTime = high_resolution_clock::now();
}

double Statistics::getExecutionTime() const {
    duration<double> executionTime = duration_cast<duration<double>>(endTime - startTime);
    return executionTime.count();
}

string Statistics::getComplexity(const string& algorithm) const {
    if (algorithm == "BubbleSort") {
        return "Complejidad Temporal: O(n^2)\nComplejidad Espacial: O(1)";
    } else if (algorithm == "QuickSort") {
        return "Complejidad Temporal: O(n log n) en promedio\nComplejidad Espacial: O(log n)";
    } else if (algorithm == "MergeSort") {
        return "Complejidad Temporal: O(n log n)\nComplejidad Espacial: O(n)";
    } else if (algorithm == "BinarySearch") {
        return "Complejidad Temporal: O(log n)\nComplejidad Espacial: O(1)";
    }
    // Añadir más algoritmos
    return "";
}