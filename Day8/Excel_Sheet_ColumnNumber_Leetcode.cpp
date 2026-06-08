/*
Problem: Excel Sheet Column Number
Platform: Leetcode
Topic: Math

Approach:
1. We will iterate through the string from left to right.
2. For each character, we will calculate its value and update the result accordingly.
3. The final result will be the column number.

Time Complexity: O(n) since we need to iterate through the entire string once.
Space Complexity: O(1) since we are only using a constant amount of extra space for the result.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(int i=0; i<columnTitle.size(); i++){
            result = result*26 + (columnTitle[i]-'A'+1);
        }
        return result;
    }
};  

