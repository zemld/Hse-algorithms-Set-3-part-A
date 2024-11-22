#include "sort_tester.h"

template<class SortingFunction>
int64_t SortTester::sortVectorAndGetTimeOfSorting(std::vector<int> &array, SortingFunction sorter) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter(array);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    int64_t nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    return nanosec;
}

void SortTester::printHeadersIntoStream(std::ofstream &output) {
    output << "array_size;time\n";
}

void SortTester::saveSortingParametersIntoStream(std::ofstream &output, size_t array_size, int64_t sorting_time) {
    output << array_size << ';' << sorting_time << '\n';
}