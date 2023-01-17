#include <iostream>
#include <vector>
#include "HeapSortAlgo.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heap_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i];
}