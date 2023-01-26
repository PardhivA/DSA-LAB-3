#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
public:
    int data;
    int level;
    vector<Node *> ArrNodes;
    void CreateNode(int data, Node *Back, int cur_level);
    void Insert(int data, int level);
};
