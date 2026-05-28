class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> seen;
        int i = 0;
        int j = 0;
        int curlen = 0;
        while(j<s.size())
        {
            if(seen.find(s[j]) == seen.end())
            {
                seen[s[j]] = j;
                curlen++;
                res = max(res, curlen);
            }
            else
            {
                while(i<=seen[s[j]]) 
                {
                    seen.erase(s[i++]);
                    curlen--;
                }
                seen[s[j]] = j;
                curlen++;
            }
            j++;
        }
        return res;
    }
};
