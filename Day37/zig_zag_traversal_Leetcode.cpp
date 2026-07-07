/*
Problem: Binary Tree Zigzag Level Order Traversal
Platform: Leetcode
Problem Number: 103
Topic: Binary Tree, Breadth First Search (BFS)

Approach:
1. If the tree is empty, return an empty result.
2. Perform a level order traversal (BFS) using a queue.
3. Maintain a boolean flag 'leftToRight' to indicate the traversal
   direction of the current level.
4. For each level:
   - Create a vector of size equal to the number of nodes.
   - Process every node in the current level.
   - If leftToRight is true, place the node value from left to right.
   - Otherwise, place the node value from right to left.
   - Push the left and right children into the queue.
5. Add the completed level to the answer.
6. Toggle the traversal direction for the next level.
7. Return the zigzag level order traversal.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- The queue and result store at most O(n) nodes.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};