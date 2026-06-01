/*
Problem: Merge Two Sorted Linked Lists
Platform: Leetcode
Topic: Math

Approach:
1. We can use a dummy node to simplify the merging process. The dummy node will act as the starting point of the merged linked list.
2. We maintain two pointers, one for each of the input linked lists (l1 and l2). We also maintain a pointer (current) that will be used to build the merged linked list.
3. We compare the values at the current nodes of both linked lists. We append the smaller value to the merged linked list and move the corresponding pointer to the next node in that linked list.
4. We repeat this process until we reach the end of one of the linked lists. At this point, we can simply append the remaining nodes of the other linked list to the merged linked list.
5. Finally, we return the next node of the dummy node, which will be the head of the merged linked list.



Time Complexity: O(n + m), where n and m are the lengths of the two linked lists, since we traverse both lists once.
Space Complexity: O(1), as we are merging the linked lists in place without using any additional data structures.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }
            else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if(l1!=NULL){
            current->next = l1;
        }
        if(l2!=NULL){
            current->next = l2;
        }
        return dummy->next;

    }
};
