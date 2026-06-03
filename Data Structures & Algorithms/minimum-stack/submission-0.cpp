class MinStack {
private:
    stack<int> s;
    stack<int> pref;
public:
    MinStack() {
        pref.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        pref.push(min(val, pref.top()));
    }
    
    void pop() {
        s.pop();
        pref.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return pref.top();
    }
};
