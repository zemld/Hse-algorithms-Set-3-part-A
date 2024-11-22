#include "../array_generator.h"
#include "../sort_tester.h"
#include "a3i.h"

void quickSortWrapping(std::vector<int> &array);
void quickSortRealization(std::vector<int> &array, int start_index, int end_index);
void introSortWrapping(std::vector<int> &array);

int main() {
    ArrayGenerator generator;
    const int max_array_size = 10000;
    std::vector<int> almost_sorted = generator.generateAlmostSortedArray(max_array_size);
    std::vector<int> random = generator.generateRandomArray(max_array_size);
    std::vector<int> reversed = generator.generateReversedArray(max_array_size);

    SortTester tester;
    tester.storeMeasurmentsOfSortingVectors(almost_sorted, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/almost_sorted_with_quick.csv", quickSortWrapping);
    tester.storeMeasurmentsOfSortingVectors(almost_sorted, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/almost_sorted_with_intro.csv", introSortWrapping);
    tester.storeMeasurmentsOfSortingVectors(random, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/random_with_quick.csv", quickSortWrapping);
    tester.storeMeasurmentsOfSortingVectors(random, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/random_with_intro.csv", introSortWrapping);
    tester.storeMeasurmentsOfSortingVectors(reversed, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/reversed_with_quick.csv", quickSortWrapping);
    tester.storeMeasurmentsOfSortingVectors(reversed, "Hse_Algorithms/Set3/A/A3/SortingTimeMeasurments/reversed_with_intro.csv", introSortWrapping);

    return 0;
}

void quickSortWrapping(std::vector<int> &array) {
    quickSortRealization(array, 0, array.size() - 1);
}

void quickSortRealization(std::vector<int> &array, int start_index, int end_index) {
    int pivot_index = permutateArrayAndReturnPivotIndex(array, start_index, end_index);
    if (start_index < pivot_index) {
        quickSortRealization(array, start_index, pivot_index);
    }
    if (pivot_index + 1 < end_index) {
        quickSortRealization(array, pivot_index + 1, end_index);
    }
}

void introSortWrapping(std::vector<int> &array) {
    int max_recursion_level = getMaxRecursionLevel(array.size());
    introSort(array, 0, array.size() - 1, max_recursion_level);
}
