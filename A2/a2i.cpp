#include <iostream>
#include <random>
#include <vector>

void makeInputFast();
size_t inputSize();
std::vector<int> inputVector(size_t size);
void sort(std::vector<int> &array);
void insertionSort(std::vector<int> &array);
int findIndexOfMinimumInArrayPart(std::vector<int> &array, size_t start_index, size_t end_index);
void mergeSort(std::vector<int> &array);
void merge(std::vector<int> &source, std::vector<int> &first, std::vector<int> &second);
void printVector(const std::vector<int> &to_print);

void makeInputFast() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
}

size_t inputSize() {
    size_t size;
    std::cin >> size;
    return size;
}

std::vector<int> inputVector(size_t size) {
    std::vector<int> array(size);
    for (size_t i = 0; i != size; ++i) {
        std::cin >> array[i];
    }
    return array;
}

void sort(std::vector<int> &array) {
    const size_t insertion_sort_threshold = 15;
    if (array.size() < insertion_sort_threshold) {
        insertionSort(array);
    } else {
        mergeSort(array);
    }
}

void insertionSort(std::vector<int> &array) {
    for (size_t i = 0; i != array.size(); ++i) {
        int index_of_minimum_in_part = findIndexOfMinimumInArrayPart(array, i, array.size() - 1);
        std::swap(array[i], array[index_of_minimum_in_part]);
    }
}

int findIndexOfMinimumInArrayPart(std::vector<int> &array, size_t start_index, size_t end_index) {
    int minimum = array[start_index];
    int index_of_minimum = start_index;
    for (size_t i = start_index + 1; i <= end_index; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
            index_of_minimum = i;
        }
    }
    return index_of_minimum;
}

void mergeSort(std::vector<int> &array) {
    std::vector<int> first_half(array.begin(), array.begin() + array.size() / 2);
    std::vector<int> second_half(array.begin() + array.size() / 2, array.end());

    sort(first_half);
    sort(second_half);

    merge(array, first_half, second_half);
}

void merge(std::vector<int> &source, std::vector<int> &first, std::vector<int> &second) {
    int source_index = 0;
    int first_index = 0;
    int second_index = 0;

    while (first_index != first.size() && second_index != second.size()) {
        if (first[first_index] <= second[second_index]) {
            source[source_index] = first[first_index];
            ++source_index;
            ++first_index;
        } else {
            source[source_index] = second[second_index];
            ++source_index;
            ++second_index;
        }
    }

    while (first_index != first.size()) {
        source[source_index] = first[first_index];
        ++source_index;
        ++first_index;
    }
    while (second_index != second.size()) {
        source[source_index] = second[second_index];
        ++source_index;
        ++second_index;
    }
}

void printVector(const std::vector<int> &array) {
    for (size_t i = 0; i != array.size(); ++i) {
        std::cout << array[i];
        if (i != array.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}