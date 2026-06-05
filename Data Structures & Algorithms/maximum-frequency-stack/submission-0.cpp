class FreqStack {
private:
    unordered_map<int, int> freqs;
    unordered_map<int, stack<int>> stacks;
    int maxCount;
public:
    FreqStack() {
        maxCount = 0;
    }
    
    void push(int val) {
        stacks[freqs[val]].push(val);
        freqs[val]++;
        if(freqs[val] > maxCount) maxCount = freqs[val];
    }
    
    int pop() {
        int res = stacks[maxCount-1].top();
        stacks[maxCount-1].pop();
        freqs[res]--;
        if(stacks[maxCount-1].empty()) maxCount--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */