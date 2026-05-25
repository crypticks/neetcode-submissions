class Solution {
private:
    int sum(vector<int>& nums, vector<vector<int>>& dp, int i, int j)
    {

    }
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefSums({{0, 1}});
        int res = 0;
        int curr = 0;
        for(int num:nums)
        {
            curr+=num;
            int diff = curr - k;
            res += prefSums[diff];
            prefSums[curr]++;
        }
        return res;
    }
};