/*
Problem: Swapping Nodes in a Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. First, calculate the total number of nodes present in the linked list using a helper function.
2. Initialize two pointers, temp1 and temp2, at the head of the linked list.
3. Move temp1 to the k-th node from the beginning of the linked list.
4. Determine the position of the k-th node from the end using the formula:
      position = (n - k) + 1
   where n is the size of the linked list.
5. Move temp2 to this calculated position from the beginning.
6. Swap the values stored in temp1 and temp2.
7. Return the head of the modified linked list.

Time Complexity: O(n)
- O(n) to calculate the size of the linked list.
- O(k) to reach the k-th node from the beginning.
- O(n-k) to reach the k-th node from the end.
Overall complexity remains O(n).

Space Complexity: O(1)
- Only a few pointer variables are used, and no extra data structures are required.

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
    int size(ListNode* head) {
        ListNode* temp = head;
        int s = 0;

        while (temp != NULL) {
            s++;
            temp = temp->next;
        }

        return s;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        int n = size(head);
        int pointer = 1;

        while (temp1 != NULL && pointer != k) {
            pointer++;
            temp1 = temp1->next;
        }

        k = (n - k) + 1;
        pointer = 1;

        while (temp2 != NULL && pointer != k) {
            pointer++;
            temp2 = temp2->next;
        }

        swap(temp1->val, temp2->val);

        return head;
    }
};