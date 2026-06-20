class Solution {
private:
    void f(vector<int>& nums, int i, vector<vector<int>>& res)
    {
        if(i == nums.size()) { res.push_back(nums); return; }
        for(int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            f(nums, i+1, res);
            swap(nums[i], nums[j]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        f(nums, 0, res);
        return res;
    }
};
