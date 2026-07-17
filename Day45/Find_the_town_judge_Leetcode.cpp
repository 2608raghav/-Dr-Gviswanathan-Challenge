/*
Problem: Find the Town Judge
Platform: Leetcode
Problem Number: 997
Topic: Graph, Array

Approach:
1. Create two arrays:
   - indegree[i]: Number of people who trust person i.
   - outdegree[i]: Number of people person i trusts.
2. Traverse the trust relationships:
   - Increment outdegree[a] since person 'a' trusts someone.
   - Increment indegree[b] since person 'b' is trusted.
3. Traverse all people from 1 to n.
4. The town judge must satisfy:
   - indegree[i] == n - 1
   - outdegree[i] == 0
5. If such a person exists, return their label.
6. Otherwise, return -1.

Time Complexity: O(n + m)
- n = number of people.
- m = number of trust relationships.

Space Complexity: O(n)
- Two arrays of size n + 1 are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for (auto &edge : trust) {
            outdegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};