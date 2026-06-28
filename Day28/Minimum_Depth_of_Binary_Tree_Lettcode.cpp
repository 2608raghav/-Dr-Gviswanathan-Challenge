/*
Problem: Minimum Depth of Binary Tree
Platform: Leetcode
Topic: Binary Tree, DFS

Approach:
1. If the tree is empty, return 0.
2. If the node is a leaf node, return 1.
3. If only the left child exists:
   - Return 1 + minimum depth of the left subtree.
4. If only the right child exists:
   - Return 1 + minimum depth of the right subtree.
5. If both children exist:
   - Return 1 + minimum of the two subtree depths.
6. The recursion eventually reaches the nearest leaf node.

Time Complexity: O(n)
- Every node is visited once.

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
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        if(root->left == NULL)
            return 1 + minDepth(root->right);

        if(root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};