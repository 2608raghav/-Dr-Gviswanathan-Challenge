/*
Problem: Lowest Common Ancestor of a Binary Search Tree
Platform: Leetcode
Problem Number: 235
Topic: Binary Search Tree (BST)

Approach:
1. Start from the root of the BST.
2. Compare the values of p and q with the current node:
   - If both values are smaller than the current node,
     move to the left subtree.
   - If both values are greater than the current node,
     move to the right subtree.
3. Otherwise:
   - The current node is the point where the paths to p and q
     diverge (or one of them is the current node).
   - Therefore, it is the Lowest Common Ancestor.
4. Return the current node.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while (root != NULL) {

            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return NULL;
    }
};