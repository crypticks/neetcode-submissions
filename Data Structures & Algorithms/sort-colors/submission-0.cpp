class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0,0,0};
        int ptr = 0;
        for(int i  = 0; i < nums.size(); i++)
        {
            counts[nums[i]]++;
        }
        for(int i = 0; i < 3; i++)
        {
            while(counts[i]>0)
            {
                nums[ptr] = i;
                counts[i]--;
                ptr++;
            }
        }
    }
};