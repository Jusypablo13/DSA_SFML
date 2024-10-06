#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Algorithm.h"

class BubbleSort : public Algorithm {
    public:
        void sort(vector<int> &data) override;
};

#endif // BUBBLESORT_H