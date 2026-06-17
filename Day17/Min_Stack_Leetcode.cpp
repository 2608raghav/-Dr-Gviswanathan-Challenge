/*
Problem: Min Stack
Platform: Leetcode
Problem Number: 155
Topic: Stack, Design

Approach:
1. Maintain two stacks:
   - A normal stack to store all pushed values.
   - A minStack to keep track of the minimum element at each stage.
2. For push(val):
   - Push val into the main stack.
   - If minStack is empty or val <= current minimum,
     push val into minStack as well.
3. For pop():
   - If the top of the main stack equals the top of minStack,
     remove it from minStack.
   - Remove the element from the main stack.
4. For top():
   - Return the top element of the main stack.
5. For getMin():
   - Return the top element of minStack,
     which always stores the current minimum.
6. This allows all operations to run in constant time.

Time Complexity:
- push(): O(1)
- pop(): O(1)
- top(): O(1)
- getMin(): O(1)

Space Complexity: O(n)
- Two stacks are maintained.

*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */