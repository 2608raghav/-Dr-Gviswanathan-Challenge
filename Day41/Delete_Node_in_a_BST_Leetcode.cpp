/*
Problem: Delete Node in a BST
Platform: Leetcode
Topic: Binary Search Tree (BST)

Approach:
1. Traverse the BST to locate the node with the given key.
2. If the key is smaller than the current node:
   - Recur on the left subtree.
3. If the key is greater than the current node:
   - Recur on the right subtree.
4. When the node to delete is found:
   - If it has no left child, return its right child.
   - If it has no right child, return its left child.
   - If it has both children:
     a. Find the inorder successor (smallest node in the right subtree).
     b. Copy its value to the current node.
     c. Delete the inorder successor from the right subtree.
5. Return the updated root of the BST.

Time Complexity: O(h)
- h is the height of the BST.
- Worst Case: O(n)
- Balanced BST: O(log n)

Space Complexity: O(h)
- Due to recursive calls.
- Worst Case: O(n)
- Balanced BST: O(log n)

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
    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {

            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};