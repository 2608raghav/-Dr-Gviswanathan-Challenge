/*
Problem: Perfect Number
Platform: Leetcode
Topic: Math

Approach:
1. A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding itself. For example, 6 is a perfect number because its divisors are 1, 2, and 3, and their sum is 6.
2. To determine if a number is perfect, we can iterate through all numbers from 1 to n/2 (inclusive) and sum up the divisors of n.


Time Complexity: O(n), where n is the input number, since we iterate through all numbers from 1 to n/2.
Space Complexity: O(1), as we are using a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1){
            return false;
        }
        int sum =0;
        for(int i=1;i<=num/2;i++){
            if(num%i==0){
                sum+=i;
            }
        }
        return sum==num;

    }
};