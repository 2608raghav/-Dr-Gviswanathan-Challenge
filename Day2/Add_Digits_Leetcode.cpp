/*
Problem: Add Digits
Platform: Leetcode
Topic: Math

Approach:
1. We can use the concept of digital root to solve this problem efficiently.
2. The digital root of a non-negative integer is the single-digit value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.
3. The digital root can be calculated using the formula:
   - If num is 0, the digital root is 0.
   - If num is divisible by 9, the digital root is 9.
   - Otherwise, the digital root is num % 9.


Time Complexity: O(1), since we are using a mathematical formula.
Space Complexity: O(1), as we use only a constant amount of extra space.

*/

class Solution {
public:
    int addDigits(int num) {
        if(num==0){
            return 0;
        }
        if(num%9==0){
            return 9;
        }
        return num%9;
    }
};