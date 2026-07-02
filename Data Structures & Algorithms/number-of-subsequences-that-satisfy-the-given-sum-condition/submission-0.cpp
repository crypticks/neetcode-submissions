class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int MOD = 1000000007;
        int res = 0, l = 0, r = nums.size() - 1;
        vector<int> power(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + power[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};