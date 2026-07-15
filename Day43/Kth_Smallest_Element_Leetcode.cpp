/*
Problem: Kth Smallest Element in a BST
Platform: Leetcode
Problem Number: 230
Topic: Binary Search Tree (BST), Inorder Traversal

Approach:
1. Perform an inorder traversal of the BST.
2. Since inorder traversal of a BST visits nodes in sorted order,
   maintain a counter for the number of visited nodes.
3. Traverse:
   - Left subtree.
   - Current node.
   - Right subtree.
4. Increment the counter whenever a node is visited.
5. When the counter becomes equal to k:
   - Store the current node's value as the answer.
6. Return the stored answer after the traversal completes.

Time Complexity: O(n)
- In the worst case, every node may be visited.

Space Complexity: O(h)
- h is the height of the tree due to recursion.
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
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {

        if (root == NULL)
            return;

        inorder(root->left, k);

        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);

        return ans;
    }
};