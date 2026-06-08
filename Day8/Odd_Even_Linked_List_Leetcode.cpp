/*
Problem: Odd Even Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. We will initialize two pointers, odd and even, to the head of the linked list and the second node of the linked list respectively.
2. We will also initialize a pointer, evenHead, to the second node of the linked list to keep track of the head of the even indexed nodes.
3. We will then iterate through the linked list until we reach the end of the linked list, updating the next pointers of the odd and even nodes accordingly.
4. Finally, we will connect the last odd indexed node to the head of the even indexed nodes and return the head of the modified linked list.

Time Complexity: O(n) since we need to iterate through the entire linked list once to rearrange the nodes.
Space Complexity: O(1) since we are modifying the linked list in place and only using a constant amount of extra space for the pointers.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};