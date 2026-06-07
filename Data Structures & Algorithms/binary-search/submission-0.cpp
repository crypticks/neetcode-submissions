class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, u = nums.size();
        while(l < u)
        {
            int m = (l + u) / 2;
            if(nums[m] < target) l = m + 1;
            else if(nums[m] > target) u = m;
            else return m;
        }
        return -1;
    }
};
