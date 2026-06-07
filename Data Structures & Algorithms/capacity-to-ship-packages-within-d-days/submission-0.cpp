class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, u = 0;
        for(int weight: weights)
        {
            l = max(l, weight);
            u+=weight;
        }
        int res;

        while( l <= u )
        {
            //cout << l << ' ' << u << '\n';
            int m = l + (u-l)/2;
            int n = m;
            int count = 1;
            bool f = false;
            for(int i = 0; i < weights.size(); i++)
            {
                n -= weights[i];
                if(n < 0)
                {
                    count++;
                    if(count > days)
                    {
                        f = true; 
                        count = 0;
                        break;
                    }
                    n = m - weights[i];
                } 
            }
            if(f)
            {
                l = m + 1;
            } else
            {
                res = m;
                u = m - 1;
            }
        }
        return res;

    }
};