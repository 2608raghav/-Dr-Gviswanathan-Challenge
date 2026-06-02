/*
Problem: Palindrome Number
Platform: Leetcode
Topic: Math

Approach:
1. A palindrome number is a number that reads the same backward as forward. For example, 121 is a palindrome, while -121 is not.
2. To determine if a number is a palindrome, we can reverse the second half of the number and compare it with the first half. If they are the same, then the number is a palindrome.
3. We can also handle edge cases, such as negative numbers and numbers that end with 0 (except for 0 itself), which cannot be palindromes.

Time Complexity: O(log n), where n is the input number, since we are reversing half of the digits.
Space Complexity: O(1), as we are using a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
            return false;
        }
        int a = 0;
        int size =0;
        int copy = x;
        long res =0;
        while(x!=0){
          a = x%10;
          x = x/10;
          size++;
          res = res*10+a;
        }
        if(copy==res){
            return true;
        }
        return false;

    }
};