class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string res = ""; 
       int len = 201;
       for(auto x:strs)
       {
        if(x.size() < len) len = x.size();
       }

       for(int i = 0; i < len; i++)
       {
        char c = strs[0][i];
        for(auto x:strs)
        {
            if (x[i] != c) return res;
        }
        res.push_back(c);
       }
       return res;
    }
};