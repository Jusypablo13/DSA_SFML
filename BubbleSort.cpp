#include "BubbleSort.h"

void BubbleSort::sort(vector<int>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}