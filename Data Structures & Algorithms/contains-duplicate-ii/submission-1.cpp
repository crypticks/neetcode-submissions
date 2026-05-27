class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int len = nums.size();
        for(int i = 0; i < min(k, len); i++)
        {
            if(seen.find(nums[i]) == seen.end()) seen.insert(nums[i]);
            else
            {
                return true;
            }
        }
        int i = 0;
        int j = k;
        while(j<nums.size())
        {
            if(seen.find(nums[j]) == seen.end())
            {
                seen.insert(nums[j]);
                j++;
                seen.erase(nums[i]);
                i++;
            } else 
            {
                return true;
            }
        }
        return false;
    }
};