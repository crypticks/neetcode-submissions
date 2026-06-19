class Solution {
private:
    void f(vector<int>& nums, int i, vector<int> curr, int currsum, vector<vector<int>>& res, int target)
    {
        if(currsum == target) 
        {
            res.push_back(curr);
            return;
        }
        if(i == nums.size() || currsum > target) return;
        curr.push_back(nums[i]);
        f(nums, i, curr, currsum + nums[i], res, target);
        curr.pop_back();

        f(nums, i + 1, curr, currsum, res, target);


    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        f(nums, 0, {}, 0, res, target);
        return res;
        
    }
};
