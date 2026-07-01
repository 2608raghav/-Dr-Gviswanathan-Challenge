/*
Problem: Maximum Depth of Binary Tree
Platform: Leetcode
Problem Number: 104
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Use recursion to calculate the depth of the binary tree.
2. If the current node is NULL:
   - Return 0 since an empty tree has depth 0.
3. Recursively compute:
   - Depth of the left subtree.
   - Depth of the right subtree.
4. The depth of the current node is:
      1 + max(leftDepth, rightDepth)
5. Return the computed depth for the root.

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
    int maxDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};