/*
Problem: Search in a Binary Search Tree
Platform: Leetcode
Problem Number: 700
Topic: Binary Search Tree (BST)

Approach:
1. Start from the root of the BST.
2. While the current node is not NULL:
   - If the current node's value equals the target,
     return the current node.
   - If the target is smaller than the current node's value,
     move to the left child.
   - Otherwise, move to the right child.
3. If the traversal reaches NULL, the target does not exist
   in the BST.
4. Return NULL.

Time Complexity: O(h)
- h is the height of the BST.
- Worst Case: O(n)
- Balanced BST: O(log n)

Space Complexity: O(1)
- Iterative traversal uses constant extra space.

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
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root != NULL) {

            if (root->val == val)
                return root;

            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return NULL;
    }
};