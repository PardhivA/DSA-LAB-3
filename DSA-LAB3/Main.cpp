#include <bits/stdc++.h>
#include "WeightedMedianTemplate.h"
#include "HeapSortAlgo.h"
using namespace std;

#define pb push_back
#define fi first
#define se second

class Data
{
private:
    vector<pair<int, int>> max_heap;
    vector<pair<int, int>> min_heap;
    int p1, p2;
    int size1, size2;

public:
    Data()
    {
        p1 = 0;
        p2 = 0;
        size1 = 0;
        size2 = 0;
    }
    void set(int x, int y)
    {
        cout << "in set\n";
        if (size2 == 0)
        {
            cout << "la;ksdfj\n";
            min_heap.pb({x, y});
            p2 = p2 + y;
            size2++;
        }
        else if (size2 != 0)
        {
            if (x > min_heap[0].first)
            {
                cout << "in set\n";

                cout << "la;ksdfj\n";

                min_heap.pb({x, y});

                p2 = p2 + y;

                min_heapify_upwards(min_heap, size2);
                cout << " min upwards done\n";
                size2++;
                check_minheap(min_heap, max_heap, &p2, &p1, &size2, &size1);
                cout << "check min done \n";
            }
            else
            {
                p1 += y;
                max_heap.pb({x, y});
                max_heapify_upwards(max_heap, size1);
                size1++;
                check_maxheap(max_heap, min_heap, &p1, &p2, &size1, &size2);
            }
        }
    }

    int get_median()
    {
        return max_heap[0].first;
    }
};

void Display()
{
    cout << "1. Enter some new integers 2. Calculate current weighted mean 3. Exit" << endl;
}

void Set_Display()
{
    cout << "Enter a pair of Elements" << endl;
}

void Weighted_median_display()
{
    cout << "Weighted Median: ";
}

int main()
{
    Data obj;
    bool status = true;
    while (status)
    {
        Display();
        int temp;
        cin >> temp;
        switch (temp)
        {
        case 1:
            Set_Display();
            int x, y;
            cin >> x >> y;
            obj.set(x, y);
            break;

        case 2:
            cout << obj.get_median() << endl;
            break;
        case 3:
            status = false;
            break;
        }
    }
}