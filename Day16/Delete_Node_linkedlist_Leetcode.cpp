/*
Problem: Delete Node in a Linked List
Platform: Leetcode
Problem Number: 237
Topic: Linked List

Approach:
1. The node to be deleted is given directly, and it is guaranteed not to be
   the last node of the linked list.
2. Copy the value of the next node into the current node.
3. Store a pointer to the next node.
4. Update the current node's next pointer to skip the next node.
5. Delete the skipped node to free memory.
6. This effectively removes the given node from the linked list.

Time Complexity: O(1)
- Only a constant number of operations are performed.

Space Complexity: O(1)
- No extra space is used.

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};