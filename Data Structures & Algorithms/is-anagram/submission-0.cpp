class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if (len != t.length()) return false;
        unordered_map<int, int> count_s;
        unordered_map<int, int> count_t;

        for(int i = 0; i< len; i++)
        {
            if (count_s.find(s[i]) == count_s.end())
            {
                count_s[s[i]] = 1;
            } else count_s[s[i]]++;
            if (count_t.find(t[i]) == count_t.end())
            {
                count_t[t[i]] = 1;
            } else count_t[t[i]]++;
        }

        for(auto x:count_s)
        {
            auto it = count_t.find(x.first);

            if (it == count_t.end() || it->second != x.second) return false;
        }
        return true;
        
    }
};
