/*
Problem: Count Values With Equally Spaced Occurrences I
Platform: LeetCode
Problem Number: 4048
Topic: Array, Hash Map, Occurrences

Approach:
1. For every distinct value, store the indices at which it occurs.

2. A value has equally spaced occurrences if the difference between
   consecutive occurrence indices is the same.

   Example:
      indices = [1, 4, 7]

      Difference:
          4 - 1 = 3
          7 - 4 = 3

      Therefore, the occurrences are equally spaced.

3. We can use an unordered_map where:
      key   -> value from nums
      value -> vector of indices where it occurs

4. Traverse the array and store every index in the corresponding
   vector.

5. For every distinct value:
   - If it occurs only once or twice, its occurrences are
     automatically equally spaced.
   - If it occurs 3 or more times, calculate the difference
     between the first two occurrences.
   - Check whether every consecutive pair has the same difference.

6. Count the values that satisfy this condition.

Time Complexity: O(n)
- Building the index lists takes O(n).
- Across all values, every occurrence is checked only once.

Space Complexity: O(n)
- The index vectors store all indices of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countEquallySpaced(vector<int>& nums) {

        unordered_map<int, vector<int>> mp;

        // Store the indices of every value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        // Check every distinct value
        for (auto& [value, indices] : mp) {

            // One or two occurrences are always equally spaced
            if (indices.size() <= 2) {
                ans++;
                continue;
            }

            // Difference between the first two occurrences
            int diff = indices[1] - indices[0];

            bool valid = true;

            // Check all consecutive occurrences
            for (int i = 2; i < indices.size(); i++) {

                if (indices[i] - indices[i - 1] != diff) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans++;
            }
        }

        return ans;
    }
};