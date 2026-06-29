/*
Problem: Sum of Left Leaves
Platform: Leetcode
Problem Number: 404
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the binary tree using recursion.
2. For each node:
   - Check if its left child exists and is a leaf node.
   - If yes, add its value to the answer.
3. Recursively process both the left and right subtrees.
4. Return the sum of all left leaf nodes.

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
    int sumOfLeftLeaves(TreeNode* root) {

        if (root == NULL)
            return 0;

        int sum = 0;

        if (root->left &&
            root->left->left == NULL &&
            root->left->right == NULL) {

            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};