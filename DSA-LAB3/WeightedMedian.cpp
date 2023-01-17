#include <iostream>
#include "HeapSortAlgo.h"
using namespace std;

#define pb push_back
class Stream
{
public:
    void set(int x, int y)
    {
        a.pb(x);
        b.pb(y);
    }

    int get_weighted_median()
    {
        heap_sort(a, b, a.size());
        int sum = 0;
        for (int i = 0; i < b.size(); i++)
            sum += b[i];
        int temp_sum = 0;
        for (int i = 0; i < b.size(); i++)
        {
            temp_sum += b[i];

            if (temp_sum / float(sum) > 0.5)
            {
                if (i == 0)
                {
                    cout << "Out of Bounds" << endl;
                    return -1;
                }
                else
                    return a[i - 1];
            }
        }
    }

private:
    vector<int> a;
    vector<int> b;
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
    Stream obj;
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
            Weighted_median_display();
            cout << obj.get_weighted_median() << endl;
            break;
        case 3:
            status = false;
            break;
        }
    }
}