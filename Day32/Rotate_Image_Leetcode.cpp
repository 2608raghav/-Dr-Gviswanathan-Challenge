/*
Problem: Rotate Image
Platform: Leetcode
Problem Number: 48
Topic: Array, Matrix

Approach:
1. Rotate the matrix in-place by performing two operations:
   a) Transpose the matrix.
   b) Reverse every row.
2. Transpose:
   - Swap matrix[i][j] with matrix[j][i] for all j > i.
3. Reverse:
   - Reverse each row of the transposed matrix.
4. After these two operations, the matrix is rotated
   90 degrees clockwise.

Time Complexity: O(n²)
- Every element is visited a constant number of times.

Space Complexity: O(1)
- Rotation is performed in-place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};