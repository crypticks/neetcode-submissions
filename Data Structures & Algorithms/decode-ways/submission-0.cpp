class Solution {

private:
    int helper(string& s, int i, unordered_map<int,int>& cache)
    {
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(i == s.size()-1) return 1;
        if(cache.count(i)) return cache[i];
        int decode1 = 0, decode2 = 0;
        decode1 = helper(s, i+1, cache);
        int combined = (s[i]-'0') * 10 + (s[i+1] - '0');
        if(combined >=10 && combined <= 26) decode2 = helper(s, i+2, cache);
        cache[i] = decode1 + decode2;
        return cache[i];
        
    }
public:
    int numDecodings(string s) {
        unordered_map<int, int> cache;
        return helper(s, 0, cache);
    }
};
