class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        res.reserve(2*len);
        for ( int i = 0; i < len; i++ )
        {
            res.push_back(nums[i]);
        }
        for ( int i = 0; i < len; i++ )
        {
            res.push_back(nums[i]);
        }
        return res;
    }
};