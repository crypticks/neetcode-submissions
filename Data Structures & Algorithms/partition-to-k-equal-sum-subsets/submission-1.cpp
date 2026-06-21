class Solution {
private:
    bool f(vector<int>& nums, int i, vector<int>& sums, int target)
    {
        if(i == nums.size()) return true;
        for(int k = 0; k < sums.size(); k++)
        {
            if(sums[k] + nums[i] > target) continue;
            sums[k]+=nums[i];
            if(f(nums, i+1, sums, target)) return true;
            sums[k]-=nums[i];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) return false;
        int target = sum/k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;
        vector<int> sums(k, 0);
        return f(nums, 0, sums, target);
    }
};