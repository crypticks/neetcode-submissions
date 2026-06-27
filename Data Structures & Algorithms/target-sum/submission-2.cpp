class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, unordered_map<int, int>> cache;
        return dfs(nums, 0, target, cache);
    }

    int dfs(vector<int>& nums, int i, int target, unordered_map<int,unordered_map<int,int>>& cache)
    {
        if(i == nums.size()) return target == 0 ? 1 : 0;
        if(cache[i].count(target)) return cache[i][target];
        int i1 = dfs(nums, i + 1, target + nums[i], cache);
        int i2 = dfs(nums, i + 1, target - nums[i], cache);
        return cache[i][target] = i1 + i2;
    }
};
