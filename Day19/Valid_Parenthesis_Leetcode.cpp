/*
Problem: Valid Parentheses
Platform: Leetcode
Topic: Stack, String

Approach:
1. Use a stack to keep track of opening brackets.
2. Traverse the string character by character.
3. If the current character is an opening bracket:
      (, {, [
   push it onto the stack.
4. If the current character is a closing bracket:
   - Check whether the stack is empty.
     If it is, return false.
   - Verify that the top of the stack contains the matching
     opening bracket.
   - If not, return false.
   - Otherwise, pop the opening bracket.
5. After processing all characters:
   - If the stack is empty, all brackets were matched correctly.
   - Otherwise, return false.
6. Return the result.

Time Complexity: O(n)
- Each character is pushed and popped at most once.

Space Complexity: O(n)
- In the worst case, all characters are opening brackets.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty()) {
                    return false;
                }

                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};