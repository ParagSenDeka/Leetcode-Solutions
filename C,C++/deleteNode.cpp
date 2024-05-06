#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

int main()
{
    vector<ListNode> nodes; // Vector to hold the nodes

    // Values to add to the linked list
    vector<int> values = {1, 3, 4};

    // Create the nodes and store them in the vector
    for (int val : values)
    {
        nodes.emplace_back(val);
    }

    // Link the nodes together
    for (size_t i = 0; i < nodes.size() - 1; ++i)
    {
        nodes[i].next = &nodes[i + 1];
    }

    // Print the values using a loop
    ListNode* currentNode = &nodes[0]; // Start from the first node
    while (currentNode != nullptr)
    {
        cout << currentNode->val << " "; // Print the value of current node
        currentNode = currentNode->next; // Move to the next node
    }
    cout << endl;

    return 0;
}
