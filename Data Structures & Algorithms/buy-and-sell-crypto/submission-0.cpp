class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int i = 0;
        int j = 1;    
        int len = prices.size();
        while(j < len)
        {
            int prof = prices[j] - prices[i];
            if(prof > 0)
                res = max(res, prof);
            else
            {
                i = j;
            }
            j++;
        }
        return res;
    }
};
