#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int> &data, int target) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] == target) {
            return mid; // Encontrado
        } else if (data[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // No encontrado
}