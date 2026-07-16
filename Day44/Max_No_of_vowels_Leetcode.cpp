/*
Problem: Maximum Number of Vowels in a Substring of Given Length
Platform: Leetcode
Problem Number: 1456
Topic: String, Sliding Window

Approach:
1. Count the number of vowels in the first window of size k.
2. Store this count as the initial answer.
3. Slide the window one character at a time:
   - If the character leaving the window is a vowel,
     decrement the count.
   - If the new character entering the window is a vowel,
     increment the count.
4. After each slide, update the maximum vowel count.
5. Continue until the end of the string and return the answer.

Time Complexity: O(n)
- Each character is processed at most twice.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        int ans = count;

        for (int i = k; i < s.size(); i++) {

            if (isVowel(s[i - k]))
                count--;

            if (isVowel(s[i]))
                count++;

            ans = max(ans, count);
        }

        return ans;
    }
};