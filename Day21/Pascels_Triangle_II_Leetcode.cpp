/*
Problem: Pascal's Triangle II
Platform: Leetcode
Problem Number: 119
Topic: Array, Math

Approach:
1. The kth row of Pascal's Triangle can be generated directly using the
   binomial coefficient formula.
2. The first element of every row is always 1.
3. Let prev represent the previous element in the row.
4. Using the relation:
      C(n, r) = C(n, r-1) * (n-r+1) / r
   compute each next element from the previous one.
5. For each position i:
      next = prev * (rowIndex - i + 1) / i
6. Append the computed value to the result vector and update prev.
7. Continue until all elements of the row are generated.
8. Return the resulting row.

Time Complexity: O(rowIndex)
- Each element of the row is computed exactly once.

Space Complexity: O(rowIndex)
- The result vector stores rowIndex + 1 elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res(1, 1);

        long long prev = 1;

        for (int i = 1; i <= rowIndex; i++) {

            long long next_val =
                prev * (rowIndex - i + 1) / i;

            res.push_back(next_val);

            prev = next_val;
        }

        return res;
    }
};