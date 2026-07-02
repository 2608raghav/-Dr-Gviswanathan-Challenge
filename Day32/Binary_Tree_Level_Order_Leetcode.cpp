/*
Problem: Binary Tree Level Order Traversal
Platform: Leetcode
Problem Number: 102
Topic: Binary Tree, Breadth First Search (BFS)

Approach:
1. If the tree is empty, return an empty result.
2. Use a queue to perform Breadth First Search (BFS).
3. Push the root node into the queue.
4. While the queue is not empty:
   - Store the current queue size (number of nodes in the current level).
   - Process exactly those nodes.
   - Add their values to a temporary vector.
   - Push their left and right children into the queue (if they exist).
5. Store the current level in the answer.
6. Repeat until all levels are processed.
7. Return the level order traversal.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- The queue may contain all nodes of one level in the worst case.

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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};