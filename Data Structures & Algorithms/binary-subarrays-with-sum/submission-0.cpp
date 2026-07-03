class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }

private:
    int helper(vector<int>& nums, int x) {
        if (x < 0) return 0;
        int res = 0, l = 0, cur = 0;
        for (int r = 0; r < nums.size(); r++) {
            cur += nums[r];
            while (cur > x) {
                cur -= nums[l];
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
};