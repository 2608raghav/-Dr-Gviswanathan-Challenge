/*
Problem: Flatten Binary Tree to Linked List
Platform: Leetcode
Problem Number: 114
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the tree recursively in reverse preorder:
      Right -> Left -> Root.
2. Maintain a pointer 'prev' that stores the previously processed node.
3. For each node:
   - Flatten the right subtree.
   - Flatten the left subtree.
   - Set:
        root->right = prev
        root->left = NULL
   - Update prev to the current node.
4. After the traversal, the tree is transformed into a linked list
   following preorder traversal using only the right pointers.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to recursion.
- Worst Case: O(n)
- Balanced Tree: O(log n)

*/

#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};