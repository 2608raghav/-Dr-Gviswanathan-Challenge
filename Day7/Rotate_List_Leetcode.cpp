/*
Problem: Rotate List
Platform: Leetcode
Topic: Linked List

Approach:
1. We will first calculate the size of the linked list.
2. We will then take the modulus of k with the size of the linked list to handle cases where k is greater than the size of the linked list.
3. We will then create a copy of the linked list values in a vector.
4. We will then reverse the first n-k elements of the vector, reverse the last k elements of the vector, and then reverse the entire vector to achieve the desired rotation.
5. Finally, we will update the values of the linked list nodes with the values from the vector and return the head of the linked list.

Time Complexity: O(n) since we are iterating through the linked list to calculate its size, creating a copy of the linked list values in a vector, and updating the values of the linked list nodes with the values from the vector.
Space Complexity: O(n) since we are using a vector to store the values of the linked list nodes.

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
void reverse(vector<int>&arr,int start,int end){
       while(start<end){
         int temp = arr[start];
         arr[start] = arr[end];
         arr[end] = temp;
         start++;
         end--;
       }
}
int size(ListNode* head)
{
    ListNode* temp = head;
    int size =0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
  return size;
}
    ListNode* rotateRight(ListNode* head, int k) {
        int n = size(head);
        if(n==0){
            return head;
        }
        k = k%n;
        k = (n-k);
        vector<int>copy;
        ListNode* temp = head;
        while(temp!=NULL){
            copy.push_back(temp->val);
            temp= temp->next;
        }
        
        
        k = k%n;

        reverse(copy,0,k-1);
        reverse(copy,k,n-1);
        reverse(copy,0,n-1);
        temp = head;
        int i=0;
         while(temp!=NULL){
            temp->val = copy[i];
            temp= temp->next;
            i++;
        }
        return head;
    }
};