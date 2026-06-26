class Solution {
public:
    unordered_map<int, int> cache;
    int numSquares(int n) {
        if(n == 0) return 0;
        if(cache.count(n)) return cache[n];
        int res = n;
        for(int i = 1; i * i <= n; i++)
        {
            int temp = numSquares(n-(i*i));
            res = min(res, 1 + temp);
        }
        return cache[n] = res;
    }
};