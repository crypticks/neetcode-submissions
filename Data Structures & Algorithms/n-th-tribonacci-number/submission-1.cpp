class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        int curr = 1;
        for(int i = 1; i < n; i++)
        {
            int temp = curr;
            curr = prev1 + prev2 + curr;
            prev1 = prev2;
            prev2 = temp;
        }
        return curr;
    }
};