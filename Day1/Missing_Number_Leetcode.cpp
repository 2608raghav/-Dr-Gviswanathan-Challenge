/*
Problem: Missing Number
Platform: LeetCode
Topic: Array

Approach:
1. We can calculate the sum of the first n natural numbers using the formula n*(n+1)/2, where n is the size of the input vector.
2. We can then iterate through the input vector and calculate the sum of the elements in the vector.
3. Finally, we can subtract the sum of the elements in the vector from the total sum to get the missing number.

Time Complexity: O(n) since we are iterating through the input vector once, where n is the size of the input vector.
Space Complexity: O(1) since we are using a constant amount of space to store the sum and total variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int total = (n*(n+1))/2;
        return (total-(sum));
    }
};