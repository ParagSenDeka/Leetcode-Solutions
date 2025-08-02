#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)  :  val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int total = 0, carry = 0;
        while (l1 || l2 || carry)
        {
            total = carry; 
            if (l1)
            {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) 
            {
                total += l2->val;
                l2 = l2->next;
            }
            int num = total % 10;
            carry = total / 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }
        return head->next;
    }
};

// Utility function to create a linked list from array
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < n; ++i)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Test case 1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode *l1 = createList(arr1, 3);
    ListNode *l2 = createList(arr2, 3);
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}
