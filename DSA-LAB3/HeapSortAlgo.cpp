#include <vector>
#include <iostream>
#include <bits/stdc++.h>

void swap(std::vector<int> &a, int i, int j, std::vector<int> &b)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
}

void swap_elements(std::vector<std::pair<int, int>> &a, int i, int j)
{
    int temp = a[i].first;
    a[i].first = a[j].first;
    a[j].first = temp;
    int temp1 = a[i].second;
    a[i].second = a[j].second;
    a[j].second = temp1;
    // temp = b[i];
    // b[i] = b[j];
    // b[j] = temp;
}

void max_heapify(std::vector<int> &a, std::vector<int> &b, int k, int n)
{

    int max = k;

    int lchild = 2 * k + 1;
    int rchild = 2 * k + 2;

    if (lchild < n && a[max] < a[lchild])
    {
        max = lchild; // max(a, curr, lch , rch)
    }
    if (rchild < n)
    {
        if (a[max] < a[rchild])
        {
            max = rchild;
        }
    }
    if (max != k)
    {
        swap(a, max, k, b);
        max_heapify(a, b, max, n);
    }
}

void min_heapify(std::vector<int> &a, std::vector<int> &b, int k, int n)
{

    int min = k;

    int lchild = 2 * k + 1;
    int rchild = 2 * k + 2;

    if (lchild < n && a[min] > a[lchild])
    {
        min = lchild; // min(a, curr, lch , rch)
    }
    if (rchild < n)
    {
        if (a[min] > a[rchild])
        {
            min = rchild;
        }
    }
    if (min != k)
    {
        swap(a, min, k, b);
        min_heapify(a, b, min, n);
    }
}

void max_heapify(std::vector<std::pair<int, int>> &a, int k, int n)
{

    int max = k;

    int lchild = 2 * k + 1;
    int rchild = 2 * k + 2;

    if (lchild < n && a[max].first < a[lchild].first)
    {
        max = lchild; // max(a, curr, lch , rch)
    }
    if (rchild < n)
    {
        if (a[max].first < a[rchild].first)
        {
            max = rchild;
        }
    }
    if (max != k)
    {
        swap_elements(a, max, k);
        max_heapify(a, max, n);
    }
}

void min_heapify(std::vector<std::pair<int, int>> &a, int k, int n)
{

    int min = k;

    int lchild = 2 * k + 1;
    int rchild = 2 * k + 2;

    if (lchild < n && a[min].first > a[lchild].first)
    {
        min = lchild; // min(a, curr, lch , rch)
    }
    if (rchild < n)
    {
        if (a[min].first > a[rchild].first)
        {
            min = rchild;
        }
    }
    if (min != k)
    {
        swap_elements(a, min, k);
        min_heapify(a, min, n);
    }
}

void heap_sort(std::vector<int> &a, std::vector<int> &b, int n)
{
    int k = n / 2 - 1; // parent of child =  n/2 - 1
    for (int i = k; i >= 0; i--)
    {
        max_heapify(a, b, i, n);
    }
    // for (int i : a)
    //     cout << i << " ";
    while (n > 0)
    {
        swap(a, 0, n - 1, b);
        n--;
        max_heapify(a, b, 0, n);
    }
}
