/*
Problem: Contains Duplicate
Platform: Leetcode
Problem Number: 217
Topic: Array, Hash Table

Approach:
1. Create a hash set to store the elements encountered so far.
2. Traverse the array.
3. For each element:
   - Check if it already exists in the hash set.
   - If it exists, a duplicate has been found, so return true.
   - Otherwise, insert the element into the set.
4. If the traversal completes without finding any duplicate,
   return false.

Time Complexity: O(n)
- Each insertion and lookup in the hash set takes O(1) on average.

Space Complexity: O(n)
- In the worst case, all elements are distinct and stored in the set.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            if (st.find(num) != st.end()) {
                return true;
            }

            st.insert(num);
        }

        return false;
    }
};