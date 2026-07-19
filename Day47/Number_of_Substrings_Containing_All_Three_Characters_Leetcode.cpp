/*
Problem: Number of Substrings Containing All Three Characters
Platform: Leetcode
Problem Number: 1358
Topic: String, Sliding Window

Approach:
1. Maintain the most recent index of each character:
   - 'a'
   - 'b'
   - 'c'
2. Initialize their indices to -1.
3. Traverse the string from left to right.
4. Update the last occurrence of the current character.
5. If all three characters have appeared:
   - Find the minimum among their last occurrence indices.
   - Every substring starting from index 0 to this minimum index
     and ending at the current position contains all three characters.
   - Add (minimum index + 1) to the answer.
6. Continue until the end of the string.
7. Return the total count.

Time Complexity: O(n)
- The string is traversed exactly once.

Space Complexity: O(1)
- Only three indices are maintained.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> last(3, -1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            last[s[i] - 'a'] = i;

            if (last[0] != -1 &&
                last[1] != -1 &&
                last[2] != -1) {

                ans += min({last[0], last[1], last[2]}) + 1;
            }
        }

        return ans;
    }
};