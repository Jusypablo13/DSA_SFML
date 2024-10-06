#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Algorithm.h"

class QuickSort : public Algorithm {
    private:
        void quickSort(vector<int> &data, int low, int high);
        int partition(vector<int> &data, int low, int high);
        
    public:
        void sort(vector<int> &data) override;
};

#endif // QUICKSORT_H