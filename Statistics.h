#ifndef STATISTICS_H
#define STATISTICS_H

#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

class Statistics{
    private:
        high_resolution_clock::time_point startTime;
        high_resolution_clock::time_point endTime;
    
    public:
        void startTimer();
        void stopTimer();
        double getExecutionTime() const;
        string getComplexity(const string &algorithm) const;
};

#endif // STATISTICS_H