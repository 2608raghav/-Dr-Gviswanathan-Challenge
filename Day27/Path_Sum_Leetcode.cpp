/*
Problem: Path Sum
Platform: Leetcode
Problem Number: 112
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the binary tree using recursion.
2. At each node:
   - Subtract the current node's value from targetSum.
3. If the current node is a leaf node:
   - Check whether the remaining targetSum equals the node's value.
   - If yes, a valid root-to-leaf path exists.
4. Otherwise:
   - Recursively search the left subtree.
   - Recursively search the right subtree.
5. If either subtree contains a valid path, return true.
6. If no valid path is found, return false.

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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};