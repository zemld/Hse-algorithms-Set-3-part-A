#include "../array_generator.h"
#include "a2i.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>

void printHeadersIntoOutputStream(std::ofstream &output);
void printResultIntoOutputStream(std::ofstream &output, size_t size, int64_t time);
int64_t standartMergeSortArrayAndGetTime(std::vector<int> &array);
int64_t mergeAndInsertionSortArrayAndGetTime(std::vector<int> &array);

int main() {
    const std::string relative_path_to_file_for_random_array_standart_merge_sort = "Hse_Algorithms/Set3/A/A2/CsvData/random_array_standart_merge_sort.csv";
    const std::string relative_path_to_file_for_reversed_array_standart_merge_sort = "Hse_Algorithms/Set3/A/A2/CsvData/reversed_array_standart_merge_sort.csv";
    const std::string relative_path_to_file_for_almost_sorted_array_standart_merge_sort = "Hse_Algorithms/Set3/A/A2/CsvData/almost_sorted_array_standart_merge_sort.csv";
    const std::string relative_path_to_file_for_random_array_merge_and_insertion_sort = "Hse_Algorithms/Set3/A/A2/CsvData/random_array_merge_and_insertion_sort.csv";
    const std::string relative_path_to_file_for_reversed_array_merge_and_insertion_sort = "Hse_Algorithms/Set3/A/A2/CsvData/reversed_array_merge_and_insertion_sort.csv";
    const std::string relative_path_to_file_for_almost_sorted_array_merge_and_insertion_sort = "Hse_Algorithms/Set3/A/A2/CsvData/almost_sorted_array_merge_and_insertion_sort.csv";

    std::ofstream output_of_random_array_standart_merge_sort(relative_path_to_file_for_random_array_standart_merge_sort);
    std::ofstream output_of_reversed_array_standart_merge_sort(relative_path_to_file_for_reversed_array_standart_merge_sort);
    std::ofstream output_of_almost_sorted_array_standart_merge_sort(relative_path_to_file_for_almost_sorted_array_standart_merge_sort);
    std::ofstream output_of_random_array_merge_and_insertion_sort(relative_path_to_file_for_random_array_merge_and_insertion_sort);
    std::ofstream output_of_reversed_array_merge_and_insertion_sort(relative_path_to_file_for_reversed_array_merge_and_insertion_sort);
    std::ofstream output_of_almost_sorted_array_merge_and_insertion_sort(relative_path_to_file_for_almost_sorted_array_merge_and_insertion_sort);
    printHeadersIntoOutputStream(output_of_random_array_standart_merge_sort);
    printHeadersIntoOutputStream(output_of_reversed_array_standart_merge_sort);
    printHeadersIntoOutputStream(output_of_almost_sorted_array_standart_merge_sort);
    printHeadersIntoOutputStream(output_of_random_array_merge_and_insertion_sort);
    printHeadersIntoOutputStream(output_of_reversed_array_merge_and_insertion_sort);
    printHeadersIntoOutputStream(output_of_almost_sorted_array_merge_and_insertion_sort);

    ArrayGenerator generator;
    auto random_array = generator.generateRandomArray(10000);
    auto reversed_array = generator.generateReversedArray(10000);
    auto almost_sorted_array = generator.generateAlmostSortedArray(10000);

    const size_t start_value = 500;
    const size_t end_value = 10000;
    const size_t step = 100;
    for (size_t size = start_value; size <= end_value; size += step) {
        std::vector<int> part_of_random_array(random_array.begin(), random_array.begin() + size);
        int64_t nanosec = standartMergeSortArrayAndGetTime(part_of_random_array);
        printResultIntoOutputStream(output_of_random_array_standart_merge_sort, size, nanosec);

        std::vector<int> part_of_reversed_array(reversed_array.begin(), reversed_array.begin() + size);
        nanosec = standartMergeSortArrayAndGetTime(part_of_reversed_array);
        printResultIntoOutputStream(output_of_reversed_array_standart_merge_sort, size, nanosec);

        std::vector<int> part_of_almost_sorted_array(almost_sorted_array.begin(), almost_sorted_array.begin() + size);
        nanosec = standartMergeSortArrayAndGetTime(part_of_almost_sorted_array);
        printResultIntoOutputStream(output_of_almost_sorted_array_standart_merge_sort, size, nanosec);
    }

    for (size_t size = start_value; size <= end_value; size += step) {
        std::vector<int> part_of_random_array(random_array.begin(), random_array.begin() + size);
        int64_t nanosec = mergeAndInsertionSortArrayAndGetTime(part_of_random_array);
        printResultIntoOutputStream(output_of_random_array_merge_and_insertion_sort, size, nanosec);

        std::vector<int> part_of_reversed_array(reversed_array.begin(), reversed_array.begin() + size);
        nanosec = mergeAndInsertionSortArrayAndGetTime(part_of_reversed_array);
        printResultIntoOutputStream(output_of_reversed_array_merge_and_insertion_sort, size, nanosec);

        std::vector<int> part_of_almost_sorted_array(almost_sorted_array.begin(), almost_sorted_array.begin() + size);
        nanosec = mergeAndInsertionSortArrayAndGetTime(part_of_almost_sorted_array);
        printResultIntoOutputStream(output_of_almost_sorted_array_merge_and_insertion_sort, size, nanosec);
    }

    output_of_random_array_standart_merge_sort.close();
    output_of_reversed_array_standart_merge_sort.close();
    output_of_almost_sorted_array_standart_merge_sort.close();
    output_of_random_array_merge_and_insertion_sort.close();
    output_of_reversed_array_merge_and_insertion_sort.close();
    output_of_almost_sorted_array_merge_and_insertion_sort.close();
    return 0;
}

void printHeadersIntoOutputStream(std::ofstream &output) {
    output << "size;time\n";
}

void printResultIntoOutputStream(std::ofstream &output, size_t size, int64_t time) {
    output << size << ';' << time << '\n';
}

int64_t standartMergeSortArrayAndGetTime(std::vector<int> &array) {
    auto start = std::chrono::high_resolution_clock::now();
    std::stable_sort(array.begin(), array.end());
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    int64_t nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    return nanosec;
}

int64_t mergeAndInsertionSortArrayAndGetTime(std::vector<int> &array) {
    auto start = std::chrono::high_resolution_clock::now();
    sort(array);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    int64_t nanosec = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    return nanosec;
}
