class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> edge(numCourses);
        for(auto& p : prerequisites)
        {
            indegrees[p[0]]++;
            edge[p[1]].push_back(p[0]);
        }

        queue<int> q;
        vector<int> finish;

        for(int i = 0; i < numCourses; i++)
            if(indegrees[i] == 0) q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front();
            finish.push_back(curr);
            q.pop();
            for(int out : edge[curr])
            {
                indegrees[out]--;
                if(indegrees[out] == 0) q.push(out);
            }
        }
        if(finish.size() == numCourses) return finish;
        return {};
    }
};
