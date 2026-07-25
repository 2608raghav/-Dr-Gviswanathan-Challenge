/*
Problem: Top K Frequent Elements
Platform: LeetCode (347)
Topic: Hash Table, Heap (Priority Queue), Bucket Sort

Approach:
1. Count the frequency of each element using a hash map (unordered_map).
2. Use a min-heap (priority_queue) to keep track of the top k most frequent elements.
3. Iterate through the frequency map and push each element-frequency pair into the min-heap.
4. If the size of the min-heap exceeds k, pop the element with the smallest frequency.
5. Extract all elements from the min-heap into a result vector and return it.

Time Complexity: O(n log k)
- Counting frequencies takes O(n) time.
- Inserting into a heap of size k takes O(log k) time, done for up to n unique elements.

Space Complexity: O(n)
- The map stores up to n elements, and the heap stores k elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Min-heap storing pair<frequency, element>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};