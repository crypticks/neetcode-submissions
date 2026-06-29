class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastindex;
        for(int i = 0; i < s.size(); i++)
        {
            lastindex[s[i]] = i;
        }

        vector<int> res;
        int curr = 1;
        int r = 0;
        int gotill = lastindex[s[0]];
        while(r < s.size())
        {
            if(r == gotill) 
            {
                res.push_back(curr);
                curr = 0;
            }
            curr++;
            r++;
            gotill = max(gotill, lastindex[s[r]]);
        }
        return res;
    }
};
