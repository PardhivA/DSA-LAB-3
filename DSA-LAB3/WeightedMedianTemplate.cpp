#include <bits/stdc++.h>
#include "HeapSortAlgo.h"
#include "WeightedMedianTemplate.h"

#define pb push_back
using namespace std;

// void swap(vector<pair<int, int>> &a, int i, int j)
// {
//     int temp1 = a[i].first;
//     int temp2 = a[i].second;
//     a[i].first = a[j].first;
//     a[i].second = a[j].second;
//     a[j].first = temp1;
//     a[j].second = temp2;
// }

void max_heapify_upwards(vector<pair<int, int>> &a, int n)
{
    // int n = a.size();
    if (n == 0)
        return;

    int parent = (n - 1) / 2;
    cout << a[0].first << "     addasd" << endl;
    cout << a[n].first << "  ddasdas" << endl;
    if (a[n].first > a[parent].first)
    {
        cout << a[0].first << endl;
        swap_elements(a, n, parent);
        cout << a[0].first << endl;
        max_heapify_upwards(a, parent);
    }
}

void min_heapify_upwards(vector<pair<int, int>> &a, int n)
{
    if (n == 0)
        return;
    else
    {
        int parent = (n - 1) / 2;
        if (a[n].first < a[parent].first)
        {
            swap_elements(a, n, parent);
            min_heapify_upwards(a, parent);
        }
    }
}

void check_minheap(vector<pair<int, int>> &a, vector<pair<int, int>> &b, int *p1, int *p2, int *size1, int *size2)
{

    while ((*p1 - a[0].second) / float(*p1 + *p2) > 0.5)
    {
        cout << a[0].first << "a0 here" << endl;
        b.pb(a[0]);
        cout << b[b.size() - 1].first << "b last" << endl;
        // cout << a[0].first << " max top\n";
        *(p1) = *(p1)-a[0].second;
        *(p2) = *(p2) + a[0].second;

        max_heapify_upwards(b, *size2);
        cout << b[0].first << endl
             << *size2 << endl;
        (*size2)++;
        swap_elements(a, 0, *(size1)-1);
        cout << a[0].first << " after swap " << endl;
        a.erase(a.end() - 1);
        (*size1)--;
        min_heapify(a, 0, *size1);
        cout << a[0].first << " after swap " << endl;
    }
}
void check_maxheap(vector<pair<int, int>> &a, vector<pair<int, int>> &b, int *p1, int *p2, int *size1, int *size2)
{
    while ((*p1) / float(*p1 + *p2) > 0.5)
    {
        cout << a[0].first << "a0 here" << endl;
        b.pb(a[0]);
        cout << b[b.size() - 1].first << "b last" << endl;
        *(p1) = *(p1)-a[0].second;
        *(p2) = *(p2) + a[0].second;

        min_heapify_upwards(b, *size2);
        cout << b[0].first << endl;
        (*size2)++;

        swap_elements(a, 0, *(size1)-1);
        a.erase(a.end() - 1);
        *(size1)--;
        max_heapify(a, 0, *size1);
    }
}