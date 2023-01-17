#include <bits/stdc++.h>
using namespace std;

// void swap(vector<pair<int, int>> &a, int i, int j);
void max_heapify_upwards(vector<pair<int, int>> &a, int n);
void min_heapify_upwards(vector<pair<int, int>> &a, int n);
void check_minheap(vector<pair<int, int>> &a, vector<pair<int, int>> &b, int *p1, int *p2, int *size1, int *size2);
void check_maxheap(vector<pair<int, int>> &a, vector<pair<int, int>> &b, int *p1, int *p2, int *size1, int *size2);
