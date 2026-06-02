/*
Problem: Linked List Cycle
Platform: Leetcode
Topic: Linked List

Approach:
1. We can use the Floyd's Tortoise and Hare algorithm to detect a cycle in the linked list.
2. We maintain two pointers, one moving at a slower pace (tortoise) and another at a faster pace (hare).
3. If there is a cycle, the hare will eventually catch up to the tortoise.
4. If there is no cycle, the hare will reach the end of the list.
5. We return true if a cycle is detected, false otherwise.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as we are using only two pointers regardless of the size of the linked list.

*/

#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };    

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;

    }
};



