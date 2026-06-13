/*
Problem: Sign of the Product of an Array
Platform: Leetcode
Problem Number: 1822
Topic: Array, Math

Approach:
1. Traverse the array and count the number of negative elements.
2. If any element is 0:
   - The product becomes 0.
   - Return 0 immediately.
3. After traversal:
   - If the count of negative numbers is even,
     the product sign is positive, so return 1.
   - If the count is odd,
     the product sign is negative, so return -1.
4. We only track the sign of the product and never compute the actual product,
   avoiding overflow issues.

Time Complexity: O(n)
- We scan the array once.

Space Complexity: O(1)
- Only a counter variable is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;

        for(int i : nums){
            if(i < 0){
                count++;
            }

            if(i == 0){
                return 0;
            }
        }

        if(count % 2 == 0){
            return 1;
        }

        return -1;
    }
};