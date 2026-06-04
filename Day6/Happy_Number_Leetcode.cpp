/*
Problem: Happy Number
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use the Floyd's Tortoise and Hare algorithm (also known as the cycle detection algorithm) to determine if a number is a happy number.
2. We will initialize two pointers, slow and fast, both starting at the given number n.
3. We will define a helper function that calculates the sum of the squares of the digits of a number.
4. We will move the slow pointer one step at a time (using the helper function) and the fast pointer two steps at a time (using the helper function twice) until the fast pointer reaches 1 or both pointers meet.
5. If the fast pointer reaches 1, then n is a happy number and we return true. If both pointers meet and are not 1, then n is not a happy number and we return false.

Time Complexity: O(log n) since we are calculating the sum of the squares of the digits, which takes logarithmic time in terms of the number of digits.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variables and update the pointers.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int n){
    int sum=0;
    while(n>0){
        int d=n%10;
        n=n/10;
        sum=sum+d*d;
    }
    return sum;
}
    bool isHappy(int n) {
        int slow=n,fast=n;
        while(fast!=1){
            slow=helper(slow);
            fast=helper(fast);
            fast=helper(fast);
            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};