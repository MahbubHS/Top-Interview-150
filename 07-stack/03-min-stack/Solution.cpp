class MinStack {
    vector<int> stack;
    vector<int> minStack;
public:
    MinStack() {}
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) minStack.push_back(val);
        else minStack.push_back(minStack.back());
    }
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    int top() {
        return stack.back();
    }
    int getMin() {
        return minStack.back();
    }
};
