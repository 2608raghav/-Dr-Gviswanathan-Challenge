/*
Problem: Implement Queue using Stacks
Platform: Leetcode
Problem Number: 232
Topic: Stack, Queue, Design

Approach:
1. Use two stacks:
   - inputStack: used for push operations.
   - outputStack: used for pop and peek operations.
2. For push(x):
   - Simply push x into inputStack.
3. For pop():
   - If outputStack is empty:
       - Transfer all elements from inputStack to outputStack.
   - Pop and return the top element of outputStack.
4. For peek():
   - If outputStack is empty:
       - Transfer all elements from inputStack to outputStack.
   - Return the top element of outputStack.
5. For empty():
   - The queue is empty if both stacks are empty.
6. This transfer reverses the order of elements,
   giving FIFO behavior.

Time Complexity:
- push(): O(1)
- pop(): O(1) amortized
- peek(): O(1) amortized
- empty(): O(1)

Space Complexity: O(n)
- Two stacks together store at most n elements.

*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> inputStack;
    stack<int> outputStack;

    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        int frontElement = outputStack.top();
        outputStack.pop();

        return frontElement;
    }

    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */