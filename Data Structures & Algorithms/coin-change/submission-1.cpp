class Solution {
private:
    int helper(vector<int>& coins, int amount, unordered_map<int, int>& cache)
    {
        if(amount == 0) return 0;
        if(cache.count(amount)) return cache[amount];
        
        int res = INT_MAX;
        for(int coin : coins)
        {
            if(amount - coin >=0)
            {
                int i = helper(coins, amount - coin, cache);
                if(i != INT_MAX) res = min(res, 1 + i);
            }
        }
        
        return cache[amount] = res;

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> cache;
        int res = helper(coins, amount, cache);
        return res == INT_MAX?-1:res;
    }
};
