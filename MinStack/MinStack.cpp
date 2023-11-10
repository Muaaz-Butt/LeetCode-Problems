class MinStack {
public:
    stack<int> arr, minArr;
    MinStack() {

    }

    void push(int val) {
        arr.push(val);
        if (!minArr.empty()) {
            val = min(val, minArr.top());
        }
        minArr.push(val);
    }

    void pop() {
        arr.pop();
        minArr.pop();
    }

    int top() {
        return arr.top();
    }

    int getMin() {
        return minArr.top();
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