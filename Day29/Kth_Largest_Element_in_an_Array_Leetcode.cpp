/*
Problem: Kth Largest Element in an Array
Platform: Leetcode
Problem Number: 215
Topic: Array, Heap (Priority Queue)

Approach:
1. Use a min-heap (priority queue) of size k.
2. Traverse the array:
   - Insert the current element into the min-heap.
   - If the heap size exceeds k,
     remove the smallest element.
3. After processing all elements:
   - The heap contains the k largest elements.
   - The top of the min-heap is the kth largest element.
4. Return the top element.

Time Complexity: O(n log k)
- Each insertion/removal from the heap takes O(log k).

Space Complexity: O(k)
- The heap stores at most k elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {

            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};