/*
Problem: Number of Subarrays With LCM Equal to K
Platform: Leetcode
Topic: Array, Math, Enumeration

Approach:
1. Traverse every possible starting index of a subarray.
2. Initialize the LCM with the first element.
3. Extend the subarray one element at a time:
   - Update the current LCM using:
         lcm(a, b) = (a / gcd(a, b)) * b
4. If the current LCM becomes greater than k or does not divide k,
   stop extending the current subarray because the LCM can only increase.
5. If the current LCM equals k, increment the answer.
6. Continue until all starting indices are processed.
7. Return the total count.

Time Complexity: O(n² × log(max(nums)))
- Each subarray updates its LCM using GCD.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            long long currLCM = 1;

            for(int j = i; j < nums.size(); j++) {

                currLCM = lcm(currLCM, (long long)nums[j]);

                if(currLCM > k || k % currLCM != 0)
                    break;

                if(currLCM == k)
                    ans++;
            }
        }

        return ans;
    }

private:
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long gcd(long long a, long long b) {
        while(b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};