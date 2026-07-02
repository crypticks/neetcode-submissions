class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 1;
        int r = 0;
        for(int num : nums)
        {
            if(num > 0)
            {
                res[r] = num;
                r+=2;
            } else
            {
                res[l] = num;
                l+=2;
            }
        }
        return res;
    }
};