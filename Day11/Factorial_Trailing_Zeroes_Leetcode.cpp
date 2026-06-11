/*
Problem: Factorial Trailing Zeroes
Platform: Leetcode
Topic: Math

Approach:
1. A trailing zero is produced by a factor pair of 2 and 5.
2. In n!, the number of factors of 2 is always greater than the number of factors of 5.
3. Therefore, the number of trailing zeroes depends only on the number of factors of 5.
4. Count:
      n/5     -> numbers contributing at least one factor of 5
      n/25    -> numbers contributing an extra factor of 5
      n/125   -> numbers contributing another extra factor of 5
      and so on.
5. Continue dividing n by 5 and add the quotient to the answer until n becomes 0.
6. Return the total count.

Time Complexity: O(log₅ n)
- The value of n is repeatedly divided by 5.

Space Complexity: O(1)
- Only a constant amount of extra space is used.

*/

 #include <bits/stdc++.h>
 using namespace std;
 class ListNode {
public:

    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    int trailingZeroes(int n) {
        int ans=0;

        while(n>0){
            n/=5;
            ans+=n;
        }
        return ans;
    }
};

