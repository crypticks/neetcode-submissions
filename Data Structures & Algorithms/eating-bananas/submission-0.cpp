class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, u = 0;
        for(int num:piles) u = max(u, num);

        int res = 0;
        while(l <= u)
        {
            int time = 0;
            int m = l + (u - l) / 2;
            bool f = false;
            for(int num:piles)
            {
                time += ( num + m - 1 ) / m;
                if(time > h) { f = true; break; }
            }
            if (f) l = m + 1;
            else
            {
                res = m;
                u = m - 1;
            }

        }
        return res;
    }
};
