#include <vector>

#ifndef A3I_H
#define A3I_H

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

#endif
