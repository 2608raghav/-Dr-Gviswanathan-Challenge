/*
Problem: Validate Binary Search Tree
Platform: Leetcode
Problem Number: 98
Topic: Binary Search Tree (BST), Depth First Search (DFS)

Approach:
1. Traverse the tree recursively while maintaining the valid range
   of values for each node.
2. Initially, the range is:
      (-∞, +∞)
3. For each node:
   - If its value is not within the allowed range,
     return false.
4. Recursively validate:
   - Left subtree with range:
        (minValue, currentNode->val)
   - Right subtree with range:
        (currentNode->val, maxValue)
5. If all nodes satisfy their valid ranges,
   return true.

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
    bool validate(TreeNode* root, long long low, long long high) {

        if (root == NULL)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return validate(root->left, low, root->val) &&
               validate(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {

        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};