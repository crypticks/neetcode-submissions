class Solution {
private:
    void f(vector<int>& nums, int i, vector<int> curr, unordered_map<int,int>& m, vector<vector<int>>& res)
    {
        if(i == nums.size()) { res.push_back(curr); return; }
        if(m[nums[i]])
        {
            curr.push_back(nums[i]);
            m[nums[i]]--;
            f(nums, i, curr, m, res);
            curr.pop_back();
            m[nums[i]]++;
        }
        f(nums, i+1, curr, m, res);

        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> uniq;
        for(int n : nums)
        {
            if(!counts[n]) uniq.push_back(n);
            counts[n]++;
        }
        vector<vector<int>> res;
        f(uniq, 0, {}, counts, res);
        return res;
    }
};
