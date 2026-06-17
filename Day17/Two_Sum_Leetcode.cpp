/*
Problem: Two Sum
Platform: Leetcode
Problem Number: 1
Topic: Array, Hash Table

Approach:
1. Create a hash map to store:
      number -> index
2. Traverse the array.
3. For each element nums[i]:
   - Compute the required complement:
         complement = target - nums[i]
   - Check if the complement already exists in the hash map.
4. If found:
   - Return the indices of the complement and the current element.
5. Otherwise:
   - Store the current number and its index in the hash map.
6. Since we check before inserting, the same element is never used twice.

Time Complexity: O(n)
- Each lookup and insertion in the hash map takes O(1) on average.

Space Complexity: O(n)
- The hash map may store up to n elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};