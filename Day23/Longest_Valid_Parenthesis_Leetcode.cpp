/*
Problem: Longest Valid Parentheses
Platform: Leetcode
Problem Number: 32
Topic: String, Stack, Dynamic Programming

Approach:
1. Use a stack to store indices.
2. Push -1 initially to handle valid substrings starting from index 0.
3. Traverse the string:
   - If the current character is '(':
       push its index onto the stack.
   - Otherwise:
       pop the top element.
4. After popping:
   - If the stack becomes empty,
     push the current index as a new base.
   - Otherwise,
     the length of the current valid substring is:
         currentIndex - stack.top()
     Update the maximum length.
5. Return the maximum valid length found.

Time Complexity: O(n)
- Each index is pushed and popped at most once.

Space Complexity: O(n)
- Stack may store up to n indices.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};