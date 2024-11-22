#include "sort_tester.h"

template<class SortingFunction>
void SortTester::storeMeasurmentsOfSortingVectors(std::vector<int> &array, std::string path_to_store_data, SortingFunction sorter) {
    std::ofstream output(path_to_store_data);
    SortTester tester;
    tester.printHeadersIntoStream(output);
    const int start_size = 500;
    const int max_array_size = 10000;
    const int step = 500;
    for (int size = start_size; size <= max_array_size; size += step) {
        std::vector<int> array_part(array.begin(), array.begin() + size);
        int64_t time = tester.sortVectorAndGetTimeOfSorting(array_part, sorter);
        tester.saveSortingParametersIntoStream(output, size, time);
    }
    output.close();
}

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