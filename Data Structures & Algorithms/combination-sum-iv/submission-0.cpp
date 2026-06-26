class Solution {
public:
    unordered_map<int, int> cache;
    int combinationSum4(vector<int>& nums, int target) {
        if(target <0) return 0;
        if(target == 0) return 1;
        if(cache.count(target)) return cache[target];
        int res = 0;
        for(int num:nums)
        {
            res += combinationSum4(nums, target-num);
        }
        return cache[target] = res;
    }
};