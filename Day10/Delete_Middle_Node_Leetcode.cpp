/*
Problem: Delete the Middle Node of a Linked List
Platform: Leetcode
Topic: Linked List, Two Pointers

Approach:
1. If the linked list contains only one node, deleting the middle node
   results in an empty list, so return NULL.
2. Use two pointers:
   - slow moves one step at a time.
   - fast moves two steps at a time.
3. Maintain a pointer prev to keep track of the node before slow.
4. When fast reaches the end of the list, slow will be pointing to the middle node.
5. Delete the middle node by updating:
      prev->next = slow->next
6. Return the head of the modified linked list.

Time Complexity: O(n)
- We traverse the linked list only once.

Space Complexity: O(1)
- Only a few pointers are used.

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;

        return head;
    }
};