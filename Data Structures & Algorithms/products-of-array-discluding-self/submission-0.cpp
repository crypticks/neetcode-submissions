class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int non_zero_product = 1;
        int zero_count = 0;
        for(int num:nums){
            product*=num;
            if (num != 0) non_zero_product*=num;
            else zero_count++;
        } 
        vector<int> out;
        if (zero_count>1)
        {
            for(int num:nums) out.push_back(0);
        }
        else
        {
            for(int num:nums) 
            {
                if (num == 0) out.push_back(non_zero_product);
                else out.push_back(product/num);
            }
        }
        return out;
    }
};
