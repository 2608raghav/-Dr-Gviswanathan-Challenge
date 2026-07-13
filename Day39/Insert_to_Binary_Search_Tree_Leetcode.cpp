/*
Problem: Insert into a Binary Search Tree
Platform: Leetcode
Problem Number: 701
Topic: Binary Search Tree (BST)

Approach:
1. If the tree is empty, create a new node and return it.
2. Start from the root of the BST.
3. Compare the value to be inserted with the current node:
   - If the value is smaller, move to the left subtree.
   - Otherwise, move to the right subtree.
4. When a NULL child is reached:
   - Create a new node.
   - Attach it as the appropriate left or right child.
5. Return the original root of the BST.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == NULL)
            return new TreeNode(val);

        TreeNode* curr = root;

        while (true) {

            if (val < curr->val) {

                if (curr->left == NULL) {
                    curr->left = new TreeNode(val);
                    break;
                }

                curr = curr->left;
            }
            else {

                if (curr->right == NULL) {
                    curr->right = new TreeNode(val);
                    break;
                }

                curr = curr->right;
            }
        }

        return root;
    }
};