class Solution {
private:
    int sumsquares(int n)
    {
        int res = 0;
        while(n > 0)
        {
            res += (n%10) * (n%10);
            n/=10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        if(n == 0) return false;
        unordered_set<int> seen;
        while(n > 1)
        {
            seen.insert(n);
            n = sumsquares(n);
            if(seen.count(n)) return false;
        }
        return true;
    }
};
