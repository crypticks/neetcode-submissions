class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len+1, vector<int>(2, 0));
        for(int i = len-1; i >= 0; i--)
        {
            dp[i][0] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], prices[i] + dp[i+1][0]);
        }

        return dp[0][0];
    }
};