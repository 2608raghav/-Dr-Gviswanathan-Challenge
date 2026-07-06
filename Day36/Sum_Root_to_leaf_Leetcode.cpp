/*
Problem: Sum Root to Leaf Numbers
Platform: Leetcode
Problem Number: 129
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the binary tree using DFS.
2. Maintain the current number formed from the root to the current node.
3. At each node:
   - Update the current number:
         current = current * 10 + root->val
4. If the current node is a leaf:
   - Return the current number.
5. Otherwise:
   - Recursively compute the sum from the left subtree.
   - Recursively compute the sum from the right subtree.
6. Return the sum of both recursive calls.
7. The final answer is the sum of all root-to-leaf numbers.

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
    int dfs(TreeNode* root, int current) {

        if (root == NULL)
            return 0;

        current = current * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
            return current;

        return dfs(root->left, current) +
               dfs(root->right, current);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};