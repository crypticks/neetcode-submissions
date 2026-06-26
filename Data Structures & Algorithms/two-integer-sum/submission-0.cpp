class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> res;
        for(int i = 0; i<nums.size(); i++)
        {
            if (seen.find(nums.at(i)) != seen.end())
            {
                res.push_back(seen[nums[i]]);
                res.push_back(i);
                return res;
            }
            else
            {
                seen.insert({target-nums[i], i});
            }
        }
        return res;
    }
};
