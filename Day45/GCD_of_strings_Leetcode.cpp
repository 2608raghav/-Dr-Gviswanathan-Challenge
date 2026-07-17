/*
Problem: Greatest Common Divisor of Strings
Platform: Leetcode
Problem Number: 1071
Topic: String, Math

Approach:
1. Check whether:
      str1 + str2 == str2 + str1
   - If not, no common divisor string exists.
2. Compute the greatest common divisor (GCD) of the lengths
   of the two strings.
3. The first gcd(length1, length2) characters of either string
   form the largest possible common divisor string.
4. Return this substring.

Time Complexity: O(n + m)
- n and m are the lengths of the two strings.

Space Complexity: O(n + m)
- Due to string concatenation.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len = gcd((int)str1.size(), (int)str2.size());

        return str1.substr(0, len);
    }
};