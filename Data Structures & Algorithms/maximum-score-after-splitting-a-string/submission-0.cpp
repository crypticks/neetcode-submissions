class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zeros(n, 0);
        vector<int> ones(n, 0);
        int curr0 = 0;
        int curr1 = 0;
        for(int i = 0; i < n-1;i ++)
        {
            if(s[i] == '0') zeros[i] = ++curr0;
            if(s[n-1-i] == '1') ones[n-i-2] = ++curr1;
        }
        int maxx = 0;
        for(int i = 0; i < n-1; i++)
        {
            maxx = max(maxx, zeros[i] + ones[i]);
        }
        return maxx;
    }
};