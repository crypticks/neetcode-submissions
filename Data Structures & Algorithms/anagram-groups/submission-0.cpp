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
        auto it = groups.find(counts);
        if (it == groups.end())
        {
            vector<string> temp;
            temp.push_back(str);
            groups[counts] = temp;
        }
        else groups[counts].push_back(str);
       }
       vector<vector<string>> res;
       for(auto it: groups)
       {
        res.push_back(it.second);
       }
       return res;
    }
};
