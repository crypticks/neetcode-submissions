class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return min(nums[0], nums[1]);
        int n = nums.size();
        int l = 0, u = n-1;
        while(l <= u)
        {
            if (l == u) return nums[(l+1)%n];
            int m = l + (u-l)/2;
            if(nums[m] > nums[(m+1)%n]) return nums[(m+1)%n];
            else if(nums[m] > nums[(m + n/2 + 1)%n]) l = (m+1)%n;
            else u = (m-1 + n) % n == u? (u-1 + n)%n : (m-1 + n) % n;
        }
        return nums[0];
        
    }
};
