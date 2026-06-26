class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegrees(n, 0);
        for(const auto& edge : edges)
        {
            indegrees[edge[0]]++;
            indegrees[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegrees[i] == 1) q.push(i);
        }
        while(n > 2)
        {
            int size = q.size();
            n-=size;
            for(int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                indegrees[curr] = 0;
    
                for(int neighbor : adj[curr])
                {
                    indegrees[neighbor]--;
                    if(indegrees[neighbor]==1) q.push(neighbor);
                }

            }
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;

    }
};