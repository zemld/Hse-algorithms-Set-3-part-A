#include <chrono>
#include <cstdint>
#include <fstream>
#include <vector>

#ifndef SORT_TESTER_H
#define SORT_TESTER_H

class SortTester {
public:
    void printHeadersIntoStream(std::ofstream &output);
    template <class SortingFunction>
    int64_t sortVectorAndGetTimeOfSorting(std::vector<int> &array, SortingFunction sorter);
    void saveSortingParametersIntoStream(std::ofstream &output, size_t array_size, int64_t sorting_time);
};

#endif
