class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        int prev = 1;
        int curr = 2;
        for(int i = 2; i < n; i++)
        {
            curr = prev + curr;
            prev = curr-prev;
        }
        return curr;
    }
};
