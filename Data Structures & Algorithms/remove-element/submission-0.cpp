class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int p1 = len-1;
        int p2 = p1;
        int temp;
        int count = 0;
        while(p1>=0)
        {
            if(nums[p1] == val)
            {
                temp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = temp;
                count++;
                p2--;
            }
            p1--;
        }
        return len-count;
    }
};