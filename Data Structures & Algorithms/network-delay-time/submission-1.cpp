class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }

        auto cmp = [](pair<int, int> a, pair<int,int> b) {return a.second > b.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minheap(cmp);

        minheap.push({k, 0});
        set<int> visited;
        int time = 0;
        while(!minheap.empty())
        {
            auto curr = minheap.top();
            minheap.pop();
            if(visited.count(curr.first)) continue;
            visited.insert(curr.first);
            time = curr.second;
            for(auto neighbor : adj[curr.first])
            {
                if(!visited.count(neighbor.first))
                {
                    minheap.push({neighbor.first, curr.second + neighbor.second});
                }
            }
        }

        if(visited.size() != n) return -1;
        return time;
    }
};
