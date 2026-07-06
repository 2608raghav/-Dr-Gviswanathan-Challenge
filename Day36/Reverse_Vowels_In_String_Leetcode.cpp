/*
Problem: Reverse Vowels of a String
Platform: Leetcode
Problem Number: 345
Topic: String

Approach:
1. Traverse the string and identify all vowels (case-insensitive).
2. Store every vowel encountered in a separate string 'v' while preserving their original order.
3. Traverse the original string again.
4. Whenever a vowel is encountered:
   - Replace it with the last vowel stored in 'v'.
   - Remove that vowel from 'v'.
5. Since vowels are inserted in order and removed from the end,
   they are placed back in reverse order.
6. Return the modified string.

Time Complexity: O(n)
- The string is traversed twice.

Space Complexity: O(k)
- k is the number of vowels in the string.
- In the worst case, k = n, so the space complexity is O(n).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string v;

        for (char c : s) {
            char temp = tolower(c);

            if (temp == 'a' ||
                temp == 'e' ||
                temp == 'i' ||
                temp == 'o' ||
                temp == 'u') {

                v.push_back(c);
            }
        }

        for (int i = 0; i < s.size(); i++) {

            char temp = tolower(s[i]);

            if (temp == 'a' ||
                temp == 'e' ||
                temp == 'i' ||
                temp == 'o' ||
                temp == 'u') {

                s[i] = v.back();
                v.pop_back();
            }
        }

        return s;
    }
};