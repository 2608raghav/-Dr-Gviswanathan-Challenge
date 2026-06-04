/*
Problem: Remove Linked List Elements
Platform: Leetcode
Topic: Linked List

Approach:
1. We will create a dummy node that points to the head of the linked list. This helps in handling edge cases where the head node itself needs to be removed.
2. We will initialize two pointers, temp1 and temp2. temp1 will traverse the original linked list, while temp2 will build the new linked list without the nodes that have the value val.
3. We will iterate through the linked list using temp1. If temp1's value is not equal to val, we will link temp2's next to temp1 and move temp2 to the next node.
4. If temp1's value is equal to val, we will simply skip that node and move temp1 to the next node.
5. After the loop, we will set temp2's next to NULL to terminate the new linked list.

Time Complexity: O(n) since we are traversing the linked list once.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variables and update the pointers.

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp1 = head;
        ListNode* res = new ListNode(0);
        ListNode* temp2 = res;
        while(temp1!=NULL){
           if(temp1->val!=val){
             temp2->next = temp1;
             temp2 = temp2->next;
           }
           temp1 = temp1->next;
          

           
        }
        temp2->next = NULL;
        return res->next;
    }
};