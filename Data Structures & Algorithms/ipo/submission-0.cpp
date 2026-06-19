class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmp = [](pair<int,int> a, pair<int,int> b){ return a.first < b.first; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxheap(cmp);

        for(int i = 0; i < profits.size(); i++) maxheap.push({profits[i], capital[i]});

        queue<pair<int,int>> q;
        while(k>0)
        {
            while(!maxheap.empty() && maxheap.top().second > w)
            {
                q.push(maxheap.top());
                maxheap.pop();
            }
            if(maxheap.empty()) return w;
            k--;
            w+=maxheap.top().first;
            maxheap.pop();
            if(k <= 0) return w;
            while(!q.empty())
            {
                //if(q.front().second <= w)
                //{
                //    k--;
                //    w+=q.front().first;
                //    if(k <= 0) return w;
                //} else 
                maxheap.push(q.front());
                q.pop();
            }
            
        }
        return w;
    }
};