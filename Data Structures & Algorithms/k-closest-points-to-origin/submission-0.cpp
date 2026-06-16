class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, vector<int>> a, pair<int, vector<int>> b) {return a.first > b.first; };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> minheap(cmp);
        for(auto point:points)
        {
            minheap.push({point[0] * point[0] + point[1] * point[1], point});
        }
        vector<vector<int>> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
        
    }
};
