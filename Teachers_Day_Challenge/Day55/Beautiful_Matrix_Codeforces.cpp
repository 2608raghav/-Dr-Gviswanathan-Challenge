/*
Problem: Beautiful Matrix
Platform: Codeforces
Problem Number: 263A
Topic: Matrix

Approach:
1. Read the 5 × 5 matrix.
2. Traverse the matrix to find the position of the element '1'.
3. Calculate the Manhattan distance between its current position
   and the center cell (2, 2).
4. The required number of moves is:
      abs(currentRow - 2) + abs(currentCol - 2)
5. Print the minimum number of moves.

Time Complexity: O(25) = O(1)
- The matrix always contains 25 elements.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int matrix[5][5];
    int row, col;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            cin >> matrix[i][j];

            if (matrix[i][j] == 1) {
                row = i;
                col = j;
            }
        }
    }

    cout << abs(row - 2) + abs(col - 2);

    return 0;
}