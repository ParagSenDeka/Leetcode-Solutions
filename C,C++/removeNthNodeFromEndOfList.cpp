#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *res = new ListNode(0, head);
        ListNode *dummy = res;

        for (int i = 0; i < n; i++)
        {
            head = head->next;
        }

        while (head != nullptr)
        {
            head = head->next;
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
        return res->next;
    }
};

int main()
{
    ListNode *node = new ListNode(2, new ListNode(4, new ListNode(5, new ListNode(6))));
    Solution sol;
    sol.removeNthFromEnd(node, 2);

    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }

    delete node;
    return 0;
}