class KthLargest {
private:
    int k;
    stack<int> s;
    priority_queue<int> heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->heap = priority_queue<int>(nums.begin(), nums.end());
    }
    
    int add(int val) {
        heap.push(val);
        for(int i = 0; i < k-1; i++)
        {
            s.push(heap.top());
            heap.pop();
        }
        int res = heap.top();
        while(!s.empty())
        {
            heap.push(s.top());
            s.pop();
        }
        return res;
    }
};
