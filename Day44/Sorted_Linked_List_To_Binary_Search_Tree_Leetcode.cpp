/*
Problem: Convert Sorted List to Binary Search Tree
Platform: Leetcode
Problem Number: 109
Topic: Linked List, Binary Search Tree (BST), Divide and Conquer

Approach:
1. Use the slow and fast pointer technique to find the middle node
   of the linked list.
2. The middle node becomes the root of the current BST.
3. Split the linked list into two halves:
   - Left half forms the left subtree.
   - Right half forms the right subtree.
4. Recursively repeat the same process for both halves.
5. Base cases:
   - If the list is empty, return NULL.
   - If the list contains only one node,
     create and return a tree node.
6. The resulting tree is height-balanced because the middle element
   is chosen as the root at every recursive step.

Time Complexity: O(n log n)
- Finding the middle node takes O(n) for each recursive level.

Space Complexity: O(log n)
- Due to the recursive call stack for a balanced tree.

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


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right)
          : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return new TreeNode(head->val);

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};