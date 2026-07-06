/*
Problem: Lowest Common Ancestor of a Binary Tree
Platform: Leetcode
Problem Number: 236
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the tree recursively.
2. Base cases:
   - If the current node is NULL, return NULL.
   - If the current node is equal to either p or q,
     return the current node.
3. Recursively search:
   - Left subtree.
   - Right subtree.
4. After the recursive calls:
   - If both left and right return non-NULL,
     the current node is the Lowest Common Ancestor.
   - If only one side is non-NULL,
     return that node upward.
   - If both are NULL,
     return NULL.
5. The first node where both targets are found in different
   subtrees is the Lowest Common Ancestor.

Time Complexity: O(n)
- Every node is visited at most once.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) {
            return root;
        }

        return (left != NULL) ? left : right;
    }
};