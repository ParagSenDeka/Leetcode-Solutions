#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* tmp=head;
        ListNode* p1=l1, *p2=l2;
        int carry=0;
        while(p1 and p2)
        {
            int s=p1->val + p2->val + carry;
            if(s>=10)
            {
                carry=1;s=s%10;
            }
            else carry=0;
            tmp->next=new ListNode(s);
            p1=p1->next;p2=p2->next;tmp=tmp->next;
        }
        while(p1)
        {
            int s=p1->val+carry;
            if(s>=10)
            {
                carry=1;s=s%10;
            }
            else carry=0;
            tmp->next=new ListNode(s);
            p1=p1->next;tmp=tmp->next;
        }while(p2)
        {
            int s=p2->val+carry;
            if(s>=10)
            {
                carry=1;s=s%10;
            }
            else carry=0;
            tmp->next=new ListNode(s);
            p2=p2->next;tmp=tmp->next;
        }
        if(carry)tmp->next=new ListNode(1);
        return head->next;
    }
};

// Utility function to create a linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result);

    // Test case 2
    int arr3[] = {9, 9, 9, 9};
    int arr4[] = {9, 9, 9};
    ListNode* l3 = createList(arr3, 4);
    ListNode* l4 = createList(arr4, 3);
    ListNode* result2 = sol.addTwoNumbers(l3, l4);
    printList(result2);

    return 0;
}
