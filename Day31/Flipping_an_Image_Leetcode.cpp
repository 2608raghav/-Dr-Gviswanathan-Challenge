/*
Problem: Flipping an Image
Platform: Leetcode
Problem Number: 832
Topic: Array, Two Pointers, Bit Manipulation

Approach:
1. Traverse each row of the matrix independently.
2. Use two pointers:
   - left at the beginning of the row.
   - right at the end of the row.
3. While left <= right:
   - Swap the elements at left and right.
   - Invert both elements (0 becomes 1, 1 becomes 0).
4. When left == right (middle element of an odd-length row),
   invert it only once.
5. After processing all rows, return the modified image.

Time Complexity: O(m × n)
- Every element is visited exactly once.

Space Complexity: O(1)
- The image is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for (auto &row : image) {

            int left = 0;
            int right = row.size() - 1;

            while (left <= right) {

                if (left == right) {
                    row[left] ^= 1;
                } else {
                    int temp = row[left] ^ 1;
                    row[left] = row[right] ^ 1;
                    row[right] = temp;
                }

                left++;
                right--;
            }
        }

        return image;
    }
};