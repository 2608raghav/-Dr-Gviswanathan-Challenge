/*
Problem: Helpful Maths
Platform: Codeforces
Problem Number: 339A
Topic: String, Sorting

Approach:
1. Read the input string containing numbers separated by '+'.
2. Traverse the string and extract all the digits.
3. Store the digits in a vector.
4. Sort the vector in ascending order.
5. Print the sorted digits separated by '+'.
6. Return the final rearranged expression.

Time Complexity: O(n log n)
- n is the number of digits.
- Sorting dominates the complexity.

Space Complexity: O(n)
- Extra space is used to store the digits.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    vector<char> nums;

    for (char c : s) {
        if (c != '+')
            nums.push_back(c);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        cout << nums[i];

        if (i != nums.size() - 1)
            cout << "+";
    }

    return 0;
}