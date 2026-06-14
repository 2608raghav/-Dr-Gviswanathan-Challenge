/*
Problem: Partition List
Platform: Leetcode
Problem Number: 86
Topic: Linked List

Approach:
1. Create two separate linked lists:
   - One for nodes with values less than x.
   - One for nodes with values greater than or equal to x.
2. Use two dummy nodes to simplify list construction.
3. Traverse the original linked list:
   - If the current node's value is less than x, append it to the first list.
   - Otherwise, append it to the second list.
4. After traversal:
   - Connect the end of the first list to the beginning of the second list.
   - Set the end of the second list to NULL to avoid cycles.
5. Return the head of the combined list.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(1)
- Only a few pointer variables are used.

*/

#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:

    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);

        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        while(head != NULL) {
            if(head->val < x) {
                less->next = head;
                less = less->next;
            }
            else {
                greater->next = head;
                greater = greater->next;
            }

            head = head->next;
        }

        greater->next = NULL;
        less->next = greaterDummy->next;

        return lessDummy->next;
    }
};