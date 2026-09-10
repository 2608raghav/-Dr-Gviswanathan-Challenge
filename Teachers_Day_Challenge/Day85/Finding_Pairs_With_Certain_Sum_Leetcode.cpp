/*
Problem: Finding Pairs With a Certain Sum
Platform: LeetCode
Problem Number: 1865
Topic: Array, Hash Map, Design

Approach:
1. Store nums1 and nums2 as class members because they are
   required by both add() and count() operations.

2. Create an unordered_map called freq to store the frequency
   of every element present in nums2.

3. Constructor:
   - Traverse nums2.
   - Store the frequency of each element in the hash map.

4. add(index, val):
   - Get the old value at nums2[index].
   - Decrease its frequency from the hash map.
   - Add val to nums2[index].
   - Increase the frequency of the new value.

5. count(tot):
   - For every element x in nums1, we need an element y
     from nums2 such that:

          x + y = tot

     Therefore:

          y = tot - x

   - Search for (tot - x) in the frequency map.
   - Add its frequency to the answer.

6. Using the frequency map allows us to find the required
   element in nums2 in O(1) average time instead of
   traversing nums2 for every element of nums1.

Time Complexity:
- Constructor: O(n + m)
- add(): O(1) average
- count(): O(n)

Where:
    n = size of nums1
    m = size of nums2

Space Complexity: O(m)
- The frequency map stores the elements of nums2.
*/
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:

    unordered_map<int, int> freq;
    vector<int> nums1;
    vector<int> nums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        
        this->nums1 = nums1;
        this->nums2 = nums2;

        
        for (int x : nums2) {
            freq[x]++;
        }
    }

    void add(int index, int val) {

        
        int oldValue = nums2[index];

       
        freq[oldValue]--;

        
        nums2[index] += val;

       
        freq[nums2[index]]++;
    }

    int count(int tot) {

        int ans = 0;

        
        for (int x : nums1) {

            
            int required = tot - x;

            
            ans += freq[required];
        }

        return ans;
    }
};