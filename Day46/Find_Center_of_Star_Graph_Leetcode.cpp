/*
Problem: Find Center of Star Graph
Platform: Leetcode
Problem Number: 1791
Topic: Graph

Approach:
1. In a star graph, the center node is common to every edge.
2. Compare the first two edges:
   - If the first node of the first edge appears in the second edge,
     it is the center.
   - Otherwise, the second node of the first edge is the center.
3. Return the identified center node.

Time Complexity: O(1)
- Only the first two edges are examined.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        if (edges[0][0] == edges[1][0] ||
            edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }

        return edges[0][1];
    }
};