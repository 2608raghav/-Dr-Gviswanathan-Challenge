/*
Problem: Perfect Square
Platform: Leetcode
Topic: Binary Search

Approach:
1. We can use a binary search approach to determine if a number is a perfect square.
2. We will initialize two pointers, start and end, to 1 and num respectively.
3. We will calculate the mid value and check if mid*mid is equal to num. If it is, then num is a perfect square and we return true.
4. If mid*mid is less than num, we will move the start pointer to mid + 1, as the perfect square must be greater than mid.
5. If mid*mid is greater than num, we will move the end pointer to mid - 1, as the perfect square must be less than mid.
    

Time Complexity: O(log n) since we are performing a binary search.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variables and update the pointers.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1){
            return true;
        }
        long start = 1;
        long end = num;
        while(start<=end){
            long mid = (start+end)/2;
            if(mid*mid==num){
              return  true;
            }
            if(mid*mid<num){
                start = mid+1;
            }
            else{
                end = mid-1;;
            }
        }
         return false;
    }
};