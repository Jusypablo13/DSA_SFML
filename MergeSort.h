#ifndef MERGESORT_H
#define MERGESORT_H

#include "Algorithm.h"

class MergeSort : public Algorithm {
    private:
        void merge(std::vector<int> &data, int low, int mid, int high);
        void mergeSort(std::vector<int> &data, int low, int high);

    public:
        void sort(std::vector<int> &data) override;
};

#endif // MERGESORT_H