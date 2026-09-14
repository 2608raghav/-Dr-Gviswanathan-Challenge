/*
Problem: Count Values With Equally Spaced Occurrences II
Platform: LeetCode
Problem Number: 4049
Topic: Array, Hash Map, Occurrences

Approach:
1. Store the indices of every value in an unordered_map.

      mp[x] = all indices where x occurs

2. For each distinct value, check whether its occurrences
   are equally spaced.

3. If the occurrence indices are:

      [i1, i2, i3, ..., ik]

   then the value is equally spaced if every consecutive
   difference is the same:

      i2 - i1 = i3 - i2 = ... = ik - i(k-1)

4. We calculate the difference between the first two
   occurrences and use it as the expected gap.

5. Traverse the remaining occurrence indices:
   - If the current gap is different from the expected gap,
     this value is not equally spaced.
   - Otherwise continue checking.

6. If all gaps are equal, increase the answer.

7. We store the indices first so that we don't repeatedly
   scan the entire nums array for every distinct value.

Example:

   nums = [1, 8, 1, 5, 1, 5, 8, 5]

   Occurrences:

   1 -> [0, 2, 4]
   5 -> [3, 5, 7]
   8 -> [1, 6]

   For 1:
      2 - 0 = 2
      4 - 2 = 2
      -> Equally spaced

   For 5:
      5 - 3 = 2
      7 - 5 = 2
      -> Equally spaced

   For 8:
      Only two occurrences
      -> Not enough occurrences for this condition.

Time Complexity: O(n)
- Building the map takes O(n).
- Across all values, the total number of stored
  occurrence indices is n.
- Checking all occurrence lists therefore takes O(n).

Space Complexity: O(n)
- In the worst case, the map stores all n indices.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int, vector<int>> mp;

        // Store all occurrence indices for every value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        // Check every distinct value
        for (auto& [value, indices] : mp) {

            // We need at least 3 occurrences
            if (indices.size() < 3) {
                continue;
            }

            // Expected distance between consecutive occurrences
            int diff = indices[1] - indices[0];

            bool equallySpaced = true;

            // Check all remaining gaps
            for (int i = 2; i < indices.size(); i++) {

                int currentDiff = indices[i] - indices[i - 1];

                if (currentDiff != diff) {
                    equallySpaced = false;
                    break;
                }
            }

            // If all gaps are equal, count this value
            if (equallySpaced) {
                ans++;
            }
        }

        return ans;
    }
};