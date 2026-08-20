/*
Problem: Distribute Elements Into Two Arrays I
Platform: LeetCode
Problem Number: 3069
Topic: Array, Simulation

Approach:
1. Put nums[0] into arr1.
2. Put nums[1] into arr2.
3. Starting from nums[2]:
   - If the last element of arr1 is greater than
     the last element of arr2, put nums[i] into arr1.
   - Otherwise, put nums[i] into arr2.
4. Concatenate arr1 and arr2.
5. Return the resulting array.

Time Complexity: O(n)
- Every element is processed exactly once.

Space Complexity: O(n)
- arr1, arr2, and result together store all n elements.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1;
        vector<int> arr2;

        // First operation
        arr1.push_back(nums[0]);

        // Second operation
        arr2.push_back(nums[1]);

        // Process remaining elements
        for (int i = 2; i < nums.size(); i++) {

            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr1 and arr2
        vector<int> result = arr1;

        for (int x : arr2) {
            result.push_back(x);
        }

        return result;
    }
};