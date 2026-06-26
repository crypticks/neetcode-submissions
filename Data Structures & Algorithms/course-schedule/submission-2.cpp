class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> startpoints;
        for(auto p : prerequisites)
        {
            edges[p[0]].push_back(p[1]);
            startpoints.push_back(p[0]);
        }

        for(int point : startpoints)
        {
            unordered_set<int> seen;
            queue<int> q;
            q.push(point);
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                seen.insert(curr);
                if(!edges.count(curr)) continue;
                for(int next : edges[curr])
                {
                    if(seen.count(next)) return false;
                    q.push(next);
                }        
            }

        }
        return true;
    }
};
