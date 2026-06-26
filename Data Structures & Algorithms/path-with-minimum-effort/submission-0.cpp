class DSU {
private:
    vector<int> Parent, Size;

public:
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return false;
        }
        if (Size[pu] < Size[pv]) {
            swap(pu, pv);
        }
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (r + 1 < ROWS) {
                    edges.push_back({abs(heights[r][c] - heights[r + 1][c]), r * COLS + c, (r + 1) * COLS + c});
                }
                if (c + 1 < COLS) {
                    edges.push_back({abs(heights[r][c] - heights[r][c + 1]), r * COLS + c, r * COLS + c + 1});
                }
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(ROWS * COLS);
        for (auto& edge : edges) {
            int weight, u, v;
            tie(weight, u, v) = edge;
            dsu.unionSets(u, v);
            if (dsu.find(0) == dsu.find(ROWS * COLS - 1)) {
                return weight;
            }
        }
        return 0;
    }
};