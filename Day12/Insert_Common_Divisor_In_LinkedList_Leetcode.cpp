/*
Problem: Insert Greatest Common Divisors in Linked List
Platform: Leetcode
Problem Number: 2807
Topic: Linked List, Math

Approach:
1. Traverse the linked list using a pointer curr.
2. For every pair of adjacent nodes:
   - Compute the GCD of their values.
   - Create a new node containing the GCD.
3. Insert the new node between the current node and the next node.
4. Move the pointer to the original next node and continue the process.
5. Repeat until the end of the linked list is reached.
6. Return the modified head.

Time Complexity: O(n × log(min(a, b)))
- We compute one GCD for each adjacent pair of nodes.

Space Complexity: O(1)
- Ignoring the space required for the newly inserted nodes.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            int gcdValue = gcd(curr->val, curr->next->val);

            ListNode* newNode = new ListNode(gcdValue);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }
};