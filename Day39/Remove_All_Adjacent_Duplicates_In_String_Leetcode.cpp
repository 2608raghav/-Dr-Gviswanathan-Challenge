/*
Problem: Remove All Adjacent Duplicates In String
Platform: Leetcode
Problem Number: 1047
Topic: String, Stack

Approach:
1. Use a stack (or a string acting as a stack).
2. Traverse each character of the string.
3. For every character:
   - If the stack is not empty and the top character is the same,
     remove the top character.
   - Otherwise, push the current character onto the stack.
4. After processing all characters, the stack contains the final string
   with all adjacent duplicates removed.
5. Return the resulting string.

Time Complexity: O(n)
- Each character is pushed and popped at most once.

Space Complexity: O(n)
- The stack may store all characters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        string st;

        for (char c : s) {

            if (!st.empty() && st.back() == c) {
                st.pop_back();
            }
            else {
                st.push_back(c);
            }
        }

        return st;
    }
};