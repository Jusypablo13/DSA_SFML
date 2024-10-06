#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

using namespace std;

class Algorithm{
    public:
        virtual void sort(vector<int> &data) = 0;
};

#endif // ALGORITHM_H