class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> freq;
        int len = s.size();
        int i = 0;
        int j = 0;
        int maxfreq = 0;
        while(j<len)
        {
            freq[s[j]]++;
            maxfreq = max(maxfreq, freq[s[j]]);
            while(j-i+1 - maxfreq > k)
            {
                freq[s[i]]--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
