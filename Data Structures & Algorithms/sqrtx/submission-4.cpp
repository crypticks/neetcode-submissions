class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int l = 0, u = x;
        int res;
        while(l <= u)
        {
            //cout << l << ' ' << u << '\n';
            int m = l + (u - l) / 2;
            if ((long long) m * m < x)
            {
                res = m;
                l = m + 1;
            }
            else if ((long long) m * m> x) u = m - 1;
            else return m;
        }
        return res;
    }
};