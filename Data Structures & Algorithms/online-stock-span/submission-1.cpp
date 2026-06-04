class StockSpanner {
private:
stack<int> s;
stack<int> temp;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!s.empty() && s.top() <= price)
        {
            temp.push(s.top());
            s.pop();
            res++;
        }
        while(!temp.empty()) 
        {
            s.push(temp.top());
            temp.pop();
        }
        s.push(price);
        return res;
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */