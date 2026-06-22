/*
Problem: Minimum Remove to Make Valid Parentheses
Platform: Leetcode
Problem Number: 1249
Topic: String, Stack

Approach:
1. Traverse the string and use a stack to store the indices of unmatched
   opening parentheses '('.
2. For every character:
   - If it is '(', push its index onto the stack.
   - If it is ')':
       - If the stack is not empty, match it with the latest '('.
       - Otherwise, mark this ')' for removal.
3. After the traversal, any indices left in the stack correspond to
   unmatched '(' and must also be removed.
4. Mark all invalid parentheses.
5. Build the answer string by skipping the marked characters.
6. Return the resulting valid string.

Time Complexity: O(n)
- The string is traversed a constant number of times.

Space Complexity: O(n)
- Stack and marker array may store up to n elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<bool> remove(s.size(), false);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    remove[i] = true;
                }
            }
        }

        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (!remove[i]) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};