// https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> minstack;
    multiset<int> minset;
public:
    MinStack() {  }
    
    void push(int val) {
        minset.insert(val);
        minstack.push(val); // O(logN)
    }
    
    void pop() {
        auto it = minset.find(minstack.top());
        minset.erase(it);
        minstack.pop();
    }
    
    int top() {
        return minstack.top();
    }
    
    int getMin() {
        return (*minset.begin());
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

// Push a pair into the stack <num, min_so_far>