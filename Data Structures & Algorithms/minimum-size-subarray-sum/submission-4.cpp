class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int cursum = nums[0];
        if(cursum >= target) return 1;
        int len = nums.size();
        int i = 0, j = 0;
        int res = len+1;
        while(j < len-1)
        {
            while(j < len-1 && cursum < target){
                j++;
                cursum+=nums[j];
            }
            while(i < j && cursum - nums[i] >= target)
            {
                //cout << i << ' ' << j << '\n';
                cursum-=nums[i];
                i++;
            }
            if(cursum >=target) res = min(res, j-i+1);
            i++;
            j = i;
            cursum = nums[i];
        }

        return res == len+1?0:res;
    }
};