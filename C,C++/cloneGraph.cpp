#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;

    void dfs(Node *node)
    {
        Node *copy = new Node(node->val);
        mp[node] = copy;
        for (auto ng : node->neighbors)
        {
            if (mp.find(ng) != mp.end())
            {
                copy->neighbors.push_back(mp[ng]);
            }
            else
            {
                dfs(ng);
                copy->neighbors.push_back(mp[ng]);
            }
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        dfs(node);
        return mp[node];
    }
};

void printGraph(Node *node, unordered_map<int, bool> &visited)
{
    if (!node || visited[node->val])
        return;

    visited[node->val] = true;
    cout << "Node " << node->val << " neighbors: ";
    for (auto neighbor : node->neighbors)
    {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (auto neighbor : node->neighbors)
    {
        printGraph(neighbor, visited);
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    cout << "Original Graph:" << endl;
    unordered_map<int, bool> visited;
    printGraph(node1, visited);

    Solution sol;
    Node *clonedGraph = sol.cloneGraph(node1);

    cout << "\nCloned Graph:" << endl;
    unordered_map<int, bool> clonedVisited;
    printGraph(clonedGraph, clonedVisited);

    return 0;
}
