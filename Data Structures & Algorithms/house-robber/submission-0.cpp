class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n+1);
        dp[0] = {nums[0],0};
        for(int i = 1; i<n; i++)
        {
            dp[i] = {dp[i-1].second + nums[i], max(dp[i-1].first, dp[i-1].second)};
        }
        return max(dp[n-1].first, dp[n-1].second);
        
    }
};
