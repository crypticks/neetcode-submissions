class Solution {
private:
    void f(vector<int>& src, int i, vector<int>& curr, int k, vector<vector<int>>& res)
    {
        if(k == 0) { res.push_back(curr); return; }
        if(i == src.size()) return;
        curr.push_back(src[i]);
        f(src, i+1, curr, k-1, res);
        curr.pop_back();
        f(src, i+1, curr, k, res);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> src;
        for(int i = 1; i<=n; i++) src.push_back(i);
        vector<int> curr;
        f(src, 0, curr, k, res);
        return res;
        
    }
};