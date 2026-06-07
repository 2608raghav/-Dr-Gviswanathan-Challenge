/*
Problem: Plus One
Platform: Leetcode
Topic: Array

Approach:
1. We will initialize a pointer to the last index of the digits array.
2. We will then iterate through the digits array from the last index to the first index until we find a digit that is not 9.
3. If we find a digit that is not 9, we will increment that digit by 1 and return the updated digits array.
4. If we do not find a digit that is not 9, it means that all digits are 9. In this case, we will set all digits to 0 and insert a 1 at the beginning of the digits array to represent the carry over from adding 1 to 999...9.

Time Complexity: O(n) since we may need to iterate through the entire digits array in the worst case where all digits are 9.
Space Complexity: O(1) since we are modifying the digits array in place and only using a constant amount of extra space for the pointer and temporary variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pointer = digits.size()-1;
        while(pointer>=0 && digits[pointer]==9 ){
            digits[pointer] =0;
            pointer--;
        }
        if(pointer>=0){
            digits[pointer]++;
        }
        else{
           digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};