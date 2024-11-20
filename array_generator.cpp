#include "array_generator.h"
#include <random>
#include <vector>

std::vector<int> ArrayGenerator::generateRandomArray(size_t size) {
    const int minimum_value = 0;
    const int maximum_value = 6000;
    
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> distribution(minimum_value, maximum_value);

    std::vector<int> array(size);
    for (size_t i = 0; i != size; ++i) {
        array[i] = distribution(mt);
    }

    return array;
}

std::vector<int> ArrayGenerator::generateReversedArray(size_t size) {
    std::vector<int> array(size);
    for (size_t i = 0; i != size; ++i) {
        array[i] = size - i;
    }

    return array;
}

std::vector<int> ArrayGenerator::generateAlmostSortedArray(size_t size) {
    std::vector<int> array(size);
    for (size_t i = 0; i != size; ++i) {
        array[i] = i;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> distribution(0, size - 1);

    const int swaps_amount = size / 100;
    for (size_t i = 0; i != swaps_amount; ++i) {
        int first_index = distribution(mt);
        int second_index = distribution(mt);
        std::swap(array[first_index], array[second_index]);
    }

    return array;
}
