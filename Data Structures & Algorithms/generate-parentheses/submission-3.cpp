class Solution {
private:
    void f(int n, unordered_set<string>& done, vector<string>& res)
    {
        if(n == 1) { res.push_back("()"); return; }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        for(int k = 0; k <= n; k++)
        {
            for(int i = 0; i < k; i++)
            {
                for(string& left : dp[i])
                {
                    for(string& right : dp[k - i -1])
                    {
                        dp[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return dp[n];
    }
};
