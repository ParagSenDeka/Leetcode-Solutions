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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                cout << list1->val << endl;
                cur->next = list2;
                list2 = list2->next;
            }
            else
            {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *result = sol.mergeTwoLists(list1, list2);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}