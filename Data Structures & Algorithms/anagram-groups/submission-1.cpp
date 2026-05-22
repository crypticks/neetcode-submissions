class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> groups; 
       for(string str: strs)
       {
        string counts = "00000000000000000000000000";
        for (char k:str)
        {
            counts[k-'a'] = counts[k-'a']+1;
        }
        groups[counts].push_back(str);
       }
       vector<vector<string>> res;
       for(auto it: groups)
       {
        res.push_back(it.second);
       }
       return res;
    }
};
