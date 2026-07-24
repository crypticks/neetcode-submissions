class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int res = 0;
        for (int num : nums) {
            int prev = max(cnt[num], cnt[k]);
            cnt[num] = prev + 1;
            res = max(res, cnt[num] - cnt[k]);
        }
        return cnt[k] + res;
    }
};