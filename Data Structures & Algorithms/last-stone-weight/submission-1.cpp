class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap(stones.begin(), stones.end());
        while(maxheap.size() > 1)
        {
            int i = maxheap.top();
            maxheap.pop();
            int j = maxheap.top();
            maxheap.pop();
            if(i == j) continue;
            maxheap.push(abs(i-j));
        }
        return (maxheap.size() == 1? maxheap.top(): 0);
        
    }
};
