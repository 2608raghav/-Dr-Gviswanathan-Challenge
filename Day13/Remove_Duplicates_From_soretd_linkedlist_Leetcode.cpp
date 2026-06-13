/*
Problem: Remove Duplicates from Sorted List II
Platform: Leetcode
Topic: Linked List

Approach:
1. If the list is empty or contains only one node, return it directly.
2. Use two pointers:
   - prev points to the current node being examined.
   - curr points to the next node.
3. Maintain a boolean flag 'check' to determine whether the current value
   appears only once in the list.
4. Create a dummy node and a pointer to build the resulting linked list.
5. Traverse the list:
   - If prev and curr have different values:
       - If check is true, append prev to the result list.
       - Reset check to true.
   - Otherwise:
       - Mark check as false since a duplicate has been found.
6. After traversal, handle the last node separately.
7. Return dummy->next, which points to the head of the modified list.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(1)
- Only a few extra pointers are used.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        ListNode* dummy = new ListNode(0);
        ListNode* pointer = dummy;
        bool check = true;

        while(curr!=NULL){

            if(prev->val!=curr->val){
                if(check==true){
                    pointer->next=prev;
                    pointer=pointer->next;
                    pointer->next = NULL;
                }
                check=true;
            }
            else{
                check=false;
            }

            prev=curr;
            curr=curr->next;
        }

        if(check==true){
            pointer->next=prev;
            pointer=NULL;
        }

        return dummy->next;
    }
};