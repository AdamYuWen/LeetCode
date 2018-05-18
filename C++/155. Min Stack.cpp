/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * https://leetcode.com/problems/min-stack/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 17, 2018
 */

// Method 1:
// It is slow, which takes 319 ms.
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        s.push_back(x);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s[s.size() - 1];
    }
    
    int getMin() {
        int res = INT_MAX;
        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            res = min(res, s[i]);
        }
        return res;
    }

private:
    vector<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


// Method 2:
// It takes 29 ms.
// It is allow to use stacks. The stack in the question has a extra function, which is getMin.
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        numStack.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }
    
    void pop() {
        if (numStack.top() == minStack.top()) {
            minStack.pop();
        }
        numStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
    
private:
    stack<int> numStack, minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
