class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = left++;
        while(left <= right)
        {
            res = res & left;
            left++;
        }
        return res;
    }
};