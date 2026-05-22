class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int num:nums)
        {
            if(counts.find(num) == counts.end()) counts[num] = 0;
            else counts[num]++;
        }
        vector<vector<int>> freq_to_values;
        freq_to_values.resize(nums.size()+1);
        for(auto it:counts)
        {
            freq_to_values[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i = nums.size(); i>=0; i--)
        {
            if (k==0) return res;
            for(auto it:freq_to_values[i])
            {
                res.push_back(it);
                k--;
                if(k==0) return res;
            }
        }
        return res;

    }
};
