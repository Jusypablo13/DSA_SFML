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
    }
    // Añadir más algoritmos
    return "";
}