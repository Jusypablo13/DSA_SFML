#include "Statistics.h"
#include <iostream>
using namespace std;
using namespace std::chrono;

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

void Statistics::displayComplexity(const string& algorithm) const {
    if (algorithm == "BubbleSort") {
        cout << "Time Complexity: O(n^2)" << endl;
        cout << "Space Complexity: O(1)" << endl;
    } else if (algorithm == "QuickSort") {
        cout << "Time Complexity: O(n log n) on average, O(n^2) worst case" << endl;
        cout << "Space Complexity: O(log n)" << endl;
    }
    //Continuar con más ...
}