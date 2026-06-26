class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> edges;
        for(int i = 0; i < equations.size(); i++)
        {
            edges[equations[i][0]][equations[i][1]] = values[i];
            edges[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        for(const auto& p1 : edges)
        {
            const string& k = p1.first;
            for(const auto& p2 : edges)
            {
                const string& i = p2.first;
                for(const auto& p3 : edges)
                {
                    const string& j = p3.first;
                    if(edges[i].count(k) && edges[k].count(j))
                    if(!edges[i].count(j)) edges[i][j] = edges[i][k] * edges[k][j];
                }
            }
        }

        vector<double> res;
        for(const auto& query : queries)
        {
            const string& a = query[0];
            const string& b = query[1];
            if (!edges.count(a) || !edges[a].count(b)) {
                res.push_back(-1.0);
            } else {
                res.push_back(edges[a][b]);
            }
        }
        return res;
    }
};