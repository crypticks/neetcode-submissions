class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }

        for (const auto& pair : graph) {
            const string& k = pair.first;
            for (const auto& pair1 : graph[k]) {
                const string& i = pair1.first;
                for (const auto& pair2 : graph[k]) {
                    const string& j = pair2.first;
                    if (!graph[i].count(j)) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> result;
        for (const auto& query : queries) {
            const string& a = query[0];
            const string& b = query[1];
            if (!graph.count(a) || !graph[a].count(b)) {
                result.push_back(-1.0);
            } else {
                result.push_back(graph[a][b]);
            }
        }

        return result;
    }
};