/*
Problem: Remove Nth Node From End of List
Platform: Leetcode
Topic: Linked List

Approach:
1. Traverse the linked list once to calculate its total size.
2. Convert the position from the end into a position from the beginning using:
      position = (size - n) + 1
3. Traverse the linked list again to reach the target node.
4. Maintain a previous pointer to keep track of the node before the target node.
5. If the target node is the head node:
   - Return head->next as the new head.
6. Otherwise:
   - Connect the previous node directly to the node after the target node.
   - Delete the target node.
7. Return the modified head.

Time Complexity: O(n)
- One traversal to find the size and another traversal to find the target node.

Space Complexity: O(1)
- Only a few pointer variables are used.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

int size(ListNode* head){
    ListNode* temp = head;
    int size =0;
    while(temp!=NULL){

        size++;
        temp = temp->next;
        
    }
    return size;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head==NULL or head->next==NULL){
            return nullptr;
         }
        int N = size(head);
        n = (N-n)+1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int counter = 1;
        while(temp!=NULL){
             if(counter==n){
                break;
             }
             prev = temp;
             temp = temp->next;
             counter++;
        }
        if(prev==NULL){
            delete(prev);
            return temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
    }
};

 