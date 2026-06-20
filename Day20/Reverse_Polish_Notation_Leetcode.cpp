/*
Problem: Evaluate Reverse Polish Notation
Platform: Leetcode
Problem Number: 150
Topic: Stack

Approach:
1. Use a stack to store operands.
2. Traverse each token in the input vector.
3. If the token is a number:
   - Convert it to an integer using stoi().
   - Push it onto the stack.
4. If the token is an operator (+, -, *, /):
   - Pop the top two elements from the stack.
   - The first popped element is the second operand.
   - The second popped element is the first operand.
   - Perform the operation and push the result back onto the stack.
5. After processing all tokens, the stack contains exactly one element,
   which is the final answer.
6. Return the top of the stack.

Time Complexity: O(n)
- Each token is processed exactly once.

Space Complexity: O(n)
- The stack may store up to n operands.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};