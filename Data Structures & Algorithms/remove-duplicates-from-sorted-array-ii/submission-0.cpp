class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int back = 1;
        int currcount = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1]) currcount = 1;
            if(nums[i] == nums[i-1])
            {
                currcount++;
                if(currcount > 2) continue;
            }
            nums[back++] = nums[i];
        }
        return back;
    }
};