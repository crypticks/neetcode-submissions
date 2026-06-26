class Solution {
private:
    int binary_search(vector<int>& nums, int target)
    {
        int l = 0, u = nums.size() - 1;
        while(l <= u)
        {
            int m = l + (u-l)/2;
            if(target <=nums[m])
            {
                u = m-1;
            } else
            {
                l = m+1;
            }
        }
        return l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > dp.back()) dp.push_back(nums[i]);
            else
            {
                int replaceindex = binary_search(dp, nums[i]);
                dp[replaceindex] = nums[i];
            }
        }
        return dp.size();
    }
};
