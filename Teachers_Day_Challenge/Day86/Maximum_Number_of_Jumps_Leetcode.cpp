/*
Problem: Maximum Number of Jumps to Reach the Last Index
Platform: LeetCode
Problem Number: 2770
Topic: Array, Dynamic Programming

Approach:
1. Let dp[i] represent the maximum number of jumps needed
   to reach index i from index 0.

2. Initially, set all dp values to -1.
   - dp[i] = -1 means index i cannot be reached.
   - dp[0] = 0 because we start at index 0 and have made
     zero jumps.

3. For every reachable index i, try jumping to every
   index j such that:

      i < j < n

   and the jump is allowed when:

      abs(nums[i] - nums[j]) <= target

4. If index j is reachable from index i, then we can reach
   j using one additional jump:

      dp[j] = max(dp[j], dp[i] + 1)

5. Finally:
   - If dp[n-1] == -1, the last index cannot be reached,
     so return -1.
   - Otherwise, return dp[n-1].

6. We use DP because the same index can be reached through
   multiple different paths. We keep the maximum number
   of jumps for each index.

Example:
   nums = [1, 3, 6, 4, 1, 2]
   target = 2

   From index 0:
      1 -> 3  difference = 2  -> valid
      1 -> 6  difference = 5  -> invalid
      1 -> 4  difference = 3  -> invalid
      1 -> 1  difference = 0  -> valid
      1 -> 2  difference = 1  -> valid

   We continue calculating the maximum jumps for every
   reachable index.

Time Complexity: O(n^2)
- For every index i, we check all later indices j.

Space Complexity: O(n)
- The dp array stores the maximum jumps for each index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        // dp[i] = maximum jumps required to reach index i
        // -1 means index i is not reachable
        vector<int> dp(n, -1);

        // We start from index 0 with 0 jumps
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            // If index i cannot be reached, skip it
            if (dp[i] == -1) {
                continue;
            }

            
            for (int j = i + 1; j < n; j++) {

                // Check whether the jump is allowed
                if (abs(nums[i] - nums[j]) <= target) {

                    // Take the path that gives maximum jumps
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // Return -1 if the last index cannot be reached
        return dp[n - 1];
    }
};
