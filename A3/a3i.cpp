#include <cmath>
#include <iostream>
#include <random>
#include <vector>

void makeInputFast();
int inputSize();
std::vector<int> inputVector(int size);
int getMaxRecursionLevel(int size);
void introSort(std::vector<int> &array, int start_index, int end_index, int remaining_recursion_level);
void insertionSort(std::vector<int> &array, int start_index, int end_index);
int findIndexOfMinimumInArrayPart(std::vector<int> &array, int start_index, int end_index);
void heapSort(std::vector<int> &array, int start_index, int end_index);
void sinkDown(std::vector<int> &array, int index, int last_index, int offset);
int getLeftChildIndex(int index, int offset);
int getRightChildIndex(int index, int offset);
void quickSort(std::vector<int> &array, int start_index, int end_index, int remaining_recursion_level);
int permutateArrayAndReturnPivotIndex(std::vector<int> &array, int start_index, int end_index);
int getRandomValueInBounds(int left_bound, int right_bound);
void printVector(const std::vector<int> &to_print);

void makeInputFast() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
}

int inputSize() {
    int size;
    std::cin >> size;
    return size;
}

std::vector<int> inputVector(int size) {
    std::vector<int> array(size);
    for (int i = 0; i != size; ++i) {
        std::cin >> array[i];
    }
    return array;
}

int getMaxRecursionLevel(int size) {
    return 2 * static_cast<int>(std::log2(size));
}

void introSort(std::vector<int> &array, int start_index, int end_index, int remaining_recursion_level) {
    const int insertion_sort_threshold = 16;
    if (end_index - start_index < insertion_sort_threshold) {
        insertionSort(array, start_index, end_index);
    } else if (remaining_recursion_level == 0) {
        heapSort(array, start_index, end_index);
    } else {
        quickSort(array, start_index, end_index, remaining_recursion_level);
    }
}

void insertionSort(std::vector<int> &array, int start_index, int end_index) {
    for (int i = start_index + 1; i < end_index; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= start_index && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int findIndexOfMinimumInArrayPart(std::vector<int> &array, int start_index, int end_index) {
    int minimum = array[start_index];
    int index_of_minimum = start_index;
    for (int i = start_index + 1; i != end_index; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
            index_of_minimum = i;
        }
    }
    return index_of_minimum;
}


void heapSort(std::vector<int> &array, int start_index, int end_index) {
    for (int i = (end_index - start_index - 1) / 2 + start_index; i >= start_index; --i) {
        sinkDown(array, i, end_index - 1, start_index);
    }

    for (int i = end_index - 1; i > start_index; --i) {
        std::swap(array[start_index], array[i]);
        sinkDown(array, start_index, i - 1, start_index);
    }
}

void sinkDown(std::vector<int> &array, int index, int last_index, int offset) {
    while (2 * (index - offset + 1) <= last_index - offset + 1) {
        int child_index = getLeftChildIndex(index, offset);
        if (child_index < last_index && array[child_index] < array[getRightChildIndex(index, offset)]) {
            child_index = getRightChildIndex(index, offset);
        }
        if (array[index] > array[child_index]) {
            break;
        }
        std::swap(array[index], array[child_index]);
        index = child_index;
    }
}

int getLeftChildIndex(int index, int offset) {
    return 2 * (index - offset + 1) + offset - 1;
}

int getRightChildIndex(int index, int offset) {
    return 2 * (index - offset + 1) + offset;
}

void quickSort(std::vector<int> &array, int start_index, int end_index, int remaining_recursion_level) {
    int pivot_index = permutateArrayAndReturnPivotIndex(array, start_index, end_index);

    --remaining_recursion_level;
    introSort(array, start_index, pivot_index, remaining_recursion_level);
    introSort(array, pivot_index + 1, end_index, remaining_recursion_level);
}

int permutateArrayAndReturnPivotIndex(std::vector<int> &array, int start_index, int end_index) {
    int left = start_index;
    int right = end_index - 1;
    int pivot_index = getRandomValueInBounds(left, right);
    int pivot = array[pivot_index];
    std::swap(array[start_index], array[pivot_index]);
    ++left;
    while (left <= right) {
        if (array[left] <= pivot) {
            ++left;
        } else if (array[right] >= pivot) {
            --right;
        } else if (array[right] < pivot && array[left] > pivot) {
            std::swap(array[left], array[right]);
        }
    }
    std::swap(array[start_index], array[--left]);
    return left;
}

int getRandomValueInBounds(int left_bound, int right_bound) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> distribution(left_bound, right_bound);
    return distribution(mt);
}

void printVector(const std::vector<int> &array) {
    for (int i = 0; i != array.size(); ++i) {
        std::cout << array[i];
        if (i != array.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}