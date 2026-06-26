class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        int res = 0;
        int curr = 0;
        int edges = 0;
        while(edges < n-1)
        {
            visited[curr] = true;
            int nextnode = -1;
            for(int i = 0; i < n; i++)
            {
                if(visited[i]) continue;
                int curdist = abs(points[curr][0]-points[i][0])
                            + abs(points[curr][1]-points[i][1]);
                dist[i] = min(dist[i], curdist);
                if(nextnode == -1 || dist[i] < dist[nextnode]) nextnode = i;
            }
            res+=dist[nextnode];
            edges++;
            curr = nextnode;
        }
        return res;
    }
};
