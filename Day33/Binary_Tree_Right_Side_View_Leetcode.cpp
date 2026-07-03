/*
Problem: Binary Tree Right Side View
Platform: Leetcode
Problem Number: 199
Topic: Binary Tree, Breadth First Search (BFS)

Approach:
1. If the tree is empty, return an empty vector.
2. Perform a level order traversal (BFS) using a queue.
3. For each level:
   - Store the number of nodes currently in the queue.
   - Process all nodes in that level.
   - The last node processed in the current level is the
     rightmost node visible from the right side.
4. Add the value of the last node of each level to the answer.
5. Continue until all levels have been processed.
6. Return the resulting vector.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- The queue may contain an entire level of the tree.

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (i == size - 1) {
                    ans.push_back(node->val);
                }

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};