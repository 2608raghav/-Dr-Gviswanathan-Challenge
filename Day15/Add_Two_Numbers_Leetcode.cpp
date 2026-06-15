/*
Problem: Add Two Numbers
Platform: Leetcode
Problem Number: 2
Topic: Linked List, Math

Approach:
1. Create a dummy node to simplify construction of the result list.
2. Maintain a pointer current to the last node of the result list.
3. Initialize carry = 0.
4. Traverse both linked lists simultaneously:
   - Extract values from the current nodes of both lists.
   - Compute:
         sum = val1 + val2 + carry
   - Create a new node with:
         sum % 10
   - Update carry:
         sum / 10
5. Move to the next nodes in both linked lists.
6. Continue until both lists are exhausted and carry becomes 0.
7. Return dummy->next as the head of the resulting linked list.

Time Complexity: O(max(n, m))
- Each node from both lists is processed once.

Space Complexity: O(max(n, m))
- A new linked list is created to store the result.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummy = new ListNode(0);
       ListNode* pointer = dummy;
       int carry =0;
       int sum =0;
       while(l1!=NULL && l2!=NULL){
         sum = (l1->val)+(l2->val)+carry;
         if(sum>9){
            carry = 1;
            sum=sum%10;
         }
         else{
            carry=0;
         }
         pointer->next=new ListNode(sum);
         pointer=pointer->next;
         l1=l1->next;
         l2=l2->next;
       }
       while(l1!=NULL){
        sum = (l1->val)+carry;
         if(sum>9){
            carry = 1;
            sum=sum%10;
         }
         else{
            carry=0;
         }
         pointer->next=new ListNode(sum);
         pointer=pointer->next;
         l1=l1->next;
         
       }
       while(l2!=NULL){
        sum = (l2->val)+carry;
         if(sum>9){
            carry = 1;
            sum=sum%10;
         }
         else{
            carry=0;
         }
         pointer->next=new ListNode(sum);
         pointer=pointer->next;
         l2=l2->next;
         
       }
       if(carry==1){
        pointer->next= new ListNode(1);
        pointer=pointer->next;
       }
       pointer->next= NULL;
       return dummy->next;
    }
};