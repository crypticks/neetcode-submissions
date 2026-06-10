class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int u = accumulate(nums.begin(), nums.end(), 0);

        int res;
        while(l <= u)
        {
            int m = l + (u - l) / 2;
            if(cansplit(nums, k, m))
            {
                res = m;
                u = m - 1;
            } else l = m + 1;
        }
        return res;
        
    }

    bool cansplit(vector<int>& nums, int k, int largest)
    {
        int cursum = 0;
        int subarrays = 1;
        for(int num:nums)
        {
            cursum += num;
            if(cursum > largest)
            {
                subarrays++;
                if(subarrays > k) return false;
                cursum = num;
            }
        }
        return true;
    }
};