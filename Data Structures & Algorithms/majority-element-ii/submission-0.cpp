class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int num:nums)
        {
            counts[num]++;
        }
        vector<int> res;
        for(auto& [key, value]:counts)
        {
            if(value > nums.size()/3) res.push_back(key);
        }
        return res;
    }
};