/*
Problem: Binary Tree Inorder Traversal
Platform: Leetcode
Problem Number: 94
Topic: Binary Tree, DFS, Stack

Approach:
1. Use a stack to perform an iterative inorder traversal.
2. Initialize a pointer to the root node.
3. Repeat while the current node is not NULL or the stack is not empty:
   - Traverse as far left as possible, pushing each node onto the stack.
   - Pop the top node from the stack.
   - Add its value to the answer.
   - Move to its right child.
4. Continue until all nodes have been visited.
5. Return the inorder traversal.

Time Complexity: O(n)
- Every node is pushed and popped exactly once.

Space Complexity: O(n)
- In the worst case, the stack stores all nodes along one path.

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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }
};