#include <cstdint>
#include <vector>

#ifndef A2I_H
#define A2I_H

void makeInputFast();
size_t inputSize();
std::vector<int> inputVector(size_t size);
void sort(std::vector<int> &array);
void insertionSort(std::vector<int> &array);
int findIndexOfMinimumInArrayPart(std::vector<int> &array, size_t start_index, size_t end_index);
void mergeSort(std::vector<int> &array);
void merge(std::vector<int> &source, std::vector<int> &first, std::vector<int> &second);
void printVector(const std::vector<int> &to_print);

#endif