/*
Problem: Implement Stack using Queues
Platform: Leetcode
Topic: Queue, Stack, Design

Approach:
1. Use a single queue to simulate stack operations.
2. For push(x):
   - Push x into the queue.
   - Rotate the queue by moving the first (size - 1) elements
     to the back.
   - This makes the newly inserted element appear at the front.
3. For pop():
   - Remove and return the front element of the queue.
4. For top():
   - Return the front element without removing it.
5. For empty():
   - Return whether the queue is empty.
6. Since the newest element is always kept at the front,
   the queue behaves like a stack.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)
- empty(): O(1)

Space Complexity: O(n)
- The queue stores all stack elements.

*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int sz = q.size();

        while (sz > 1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */