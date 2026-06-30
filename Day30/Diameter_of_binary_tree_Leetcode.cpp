/*
Problem: Diameter of Binary Tree
Platform: Leetcode
Problem Number: 543
Topic: Binary Tree, Depth First Search (DFS)

Approach:
1. Traverse the tree using postorder DFS.
2. For each node:
   - Recursively calculate the height of its left subtree.
   - Recursively calculate the height of its right subtree.
3. The diameter passing through the current node is:
      leftHeight + rightHeight
4. Update the global maximum diameter if the current diameter is larger.
5. Return the height of the current node:
      1 + max(leftHeight, rightHeight)
6. After traversing the entire tree, return the maximum diameter found.

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
    int diameter = 0;

    int height(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};