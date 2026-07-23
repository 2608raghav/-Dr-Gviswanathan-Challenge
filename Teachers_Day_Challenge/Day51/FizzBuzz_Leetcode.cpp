/*
Problem: Fizz Buzz
Platform: Leetcode
Topic: Simulation

Approach:
1. Create an empty result vector.
2. Traverse the numbers from 1 to n.
3. For each number:
   - If it is divisible by both 3 and 5,
     add "FizzBuzz".
   - Else if it is divisible by 3,
     add "Fizz".
   - Else if it is divisible by 5,
     add "Buzz".
   - Otherwise, convert the number to a string and add it.
4. Return the result vector.

Time Complexity: O(n)
- Each number is processed exactly once.

Space Complexity: O(n)
- The output vector stores n strings.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ans;

        for (int i = 1; i <= n; i++) {

            if (i%3==0 && i%5==0)
                ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }

        return ans;
    }
};