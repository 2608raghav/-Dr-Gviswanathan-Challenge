/*
Problem: Constructing the Array
Platform: Codeforces
Problem Number: 1353D
Topic: Greedy, Priority Queue, Implementation

Approach:
1. Initially, the entire array consists of zeros.
2. Consider the whole array as one available segment [0, n-1].
3. We need to repeatedly select:
      - The longest zero segment.
      - If multiple segments have the same length,
        select the leftmost segment.
4. A priority queue is used to always get the required
   segment efficiently.
5. For every number from 1 to n:
      - Take the highest-priority segment.
      - Find its middle position.
      - Place the current number at that position.
      - Split the remaining segment into:
            Left segment
            Right segment
      - Insert the non-empty segments back into the
        priority queue.
6. Finally, print the constructed array.

Priority Rules:
1. Larger segment length has higher priority.
2. If lengths are equal, the segment with the smaller
   left index has higher priority.

Middle Position:
For a segment [l, r]:

      mid = (l + r) / 2

This automatically gives:
- The exact middle for an odd-length segment.
- The left-middle for an even-length segment.

Time Complexity: O(n log n)
- Each number is processed once.
- Priority queue operations take O(log n).

Space Complexity: O(n)
- The array and priority queue can store up to O(n) elements.
*/

#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int l, r;
};

struct Compare {

    bool operator()(Segment a, Segment b) {

        int lenA = a.r - a.l + 1;
        int lenB = b.r - b.l + 1;

        // Larger segment gets higher priority
        if (lenA != lenB)
            return lenA < lenB;

        // If lengths are equal, the leftmost segment
        // gets higher priority
        return a.l > b.l;
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> ans(n, 0);

        priority_queue<
            Segment,
            vector<Segment>,
            Compare
        > pq;

        // Initially, the entire array is one zero segment
        pq.push({0, n - 1});

        // Place numbers from 1 to n
        for (int num = 1; num <= n; num++) {

            // Get the longest and leftmost segment
            Segment cur = pq.top();
            pq.pop();

            int l = cur.l;
            int r = cur.r;

            // Find the required middle position
            int mid = (l + r) / 2;

            // Place the current number
            ans[mid] = num;

            // Add the left remaining segment
            if (l <= mid - 1) {
                pq.push({l, mid - 1});
            }

            // Add the right remaining segment
            if (mid + 1 <= r) {
                pq.push({mid + 1, r});
            }
        }

        // Print the constructed array
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}