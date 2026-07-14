/*
Problem: Reverse Words in a String
Platform: Leetcode
Problem Number: 151
Topic: String, Two Pointers

Approach:
1. Traverse the string from the end towards the beginning.
2. Skip all trailing and extra spaces.
3. Identify one word at a time by finding its starting and ending indices.
4. Append each extracted word to the answer string.
5. Add a single space between consecutive words.
6. Continue until all words have been processed.
7. Return the final reversed string.

Time Complexity: O(n)
- Each character is visited at most once.

Space Complexity: O(n)
- Extra space is used to store the resulting string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        string ans;
        int i = s.size() - 1;

        while (i >= 0) {

            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            while (j >= 0 && s[j] != ' ')
                j--;

            if (!ans.empty())
                ans += " ";

            ans += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return ans;
    }
};