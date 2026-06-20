class Solution {
private:
    void f(vector<int>& nums, int target, int i, vector<int>curr, unordered_map<int,int>& counts, vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
        if(i == nums.size() || target < 0) return;
        if(counts[nums[i]] > 0)
        {
            curr.push_back(nums[i]);
            counts[nums[i]]--;
            f(nums, target - nums[i], i, curr, counts, res);
            curr.pop_back();
            counts[nums[i]]++;
        }
        f(nums, target, i+1, curr, counts, res);
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int,int> counts;
        vector<int> A;
        for(int n : nums) 
        {
            if(!counts[n]) A.push_back(n);
            counts[n]++;
        }
        f(A, target, 0, {}, counts, res);
        return res;
        
    }
};
