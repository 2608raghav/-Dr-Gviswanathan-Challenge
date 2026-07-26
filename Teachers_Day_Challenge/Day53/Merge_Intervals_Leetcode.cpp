/*
Problem: Merge Intervals
Platform: Leetcode
Topic: Array, Sorting

Approach:
1. Sort all the intervals based on their starting values.
2. Initialize the result vector with the first interval.
3. Traverse the remaining intervals one by one.
4. For each interval:
   - If its start is less than or equal to the end of the last
     interval in the result, merge them by updating the end
     value to the maximum of the two ends.
   - Otherwise, add the current interval to the result.
5. After processing all intervals, return the merged intervals.

Time Complexity: O(n log n)
- Sorting the intervals dominates the complexity.

Space Complexity: O(n)
- In the worst case, no intervals overlap and all are stored
  in the result vector.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= ans.back()[1]) {

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};