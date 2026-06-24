/*
Problem: Basic Calculator
Platform: Leetcode
Problem Number: 224
Topic: Stack, String

Approach:
1. Traverse the expression character by character.
2. Maintain:
   - result: current calculated value.
   - number: current number being formed.
   - sign: current sign (+1 or -1).
3. If a digit is encountered:
   - Build the complete number.
4. If '+' or '-' is encountered:
   - Add the previous number with its sign to the result.
   - Update the sign.
   - Reset the current number.
5. If '(' is encountered:
   - Push the current result and sign onto the stack.
   - Reset result and sign for the new sub-expression.
6. If ')' is encountered:
   - Add the current number to the result.
   - Multiply the result by the sign before '('.
   - Add the result that existed before '('.
7. After traversal, add the last pending number.
8. Return the final result.

Time Complexity: O(n)
- Each character is processed once.

Space Complexity: O(n)
- Stack may store nested expressions.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        long long result = 0;
        long long number = 0;
        int sign = 1;

        for(char c : s) {

            if(isdigit(c)) {
                number = number * 10 + (c - '0');
            }

            else if(c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }

            else if(c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }

            else if(c == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if(c == ')') {

                result += sign * number;
                number = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * number;

        return (int)result;
    }
};