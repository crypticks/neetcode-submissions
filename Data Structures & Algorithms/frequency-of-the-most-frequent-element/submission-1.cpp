class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int modified = 0;
        int res = 1;
        int l = 0;
        for(int r = 1; r < n; r++)
        {
            modified += (nums[r] - nums[r-1]) * (r-l);
            while(modified > k)
            {
                modified -= nums[r] - nums[l++];
            }
            res = max(res, r-l + 1);
        }
        return res;
        
    }
};