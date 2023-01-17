// #include <iostream>
#include <vector>
// using namespace std;
#ifndef MY_FUN
#define MY_FUN

void swap(std::vector<int> &a, std::vector<int> &b, int i, int j);
void swap_elements(std::vector<std::pair<int, int>> &a, int i, int j);
void max_heapify(std::vector<int> &a, std::vector<int> &b, int k, int n);
void min_heapify(std::vector<int> &a, std::vector<int> &b, int k, int n);

void max_heapify(std::vector<std::pair<int, int>> &a, int k, int n);
void min_heapify(std::vector<std::pair<int, int>> &a, int k, int n);
void heap_sort(std::vector<int> &a, std::vector<int> &b, int n);

#endif