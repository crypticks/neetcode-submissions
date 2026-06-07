class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, u = nums.size();

        int res = 0;
        while(l < u)
        {
            int m = l + ( u - l ) / 2;
            if(nums[m] == target) return m;
            else if (nums[m] < target) 
            {
                res = m + 1;
                l = m + 1;
            }
            else
            {
                u = m;
            }
        }
        return res;
        
    }
};