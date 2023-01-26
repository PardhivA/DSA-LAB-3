#include <bits/stdc++.h>
#include "SkipListSearch.h"
using namespace std;

Node::Node()
{
    this->data = INT_MIN;
    this->ArrNodes[0]->data = INT_MAX;
    this->level = 0;
}

void Node::CreateNode(int data, Node *Back, int cur_level)
{
    Node *new_temp = new Node;
    new_temp->data = data;
    Node *temp = Back->ArrNodes[cur_level];
    Back->ArrNodes[cur_level] = new_temp;
    new_temp->ArrNodes[cur_level] = temp;
}

void Node::Insert(int giv_data, int level)
{
    int cur_level = level;
    int size_of_ArrNodes = ArrNodes.size();
    Node *cur_node = ArrNodes[size_of_ArrNodes - 1];
    Node *level_node;
    cur_node->data = INT_MIN;

    while (cur_level >= 0)
    {
        level_node = cur_node;
        while (giv_data <= cur_node->ArrNodes[cur_level]->data)
        {
            cur_node = cur_node->ArrNodes[cur_level];
        }
        cur_level--;
    }

    CreateNode(giv_data, cur_node, cur_level);
}