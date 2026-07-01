class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++)
        {
            int a1 = a&1;
            int b1 = b&1;
            int digit = (a1) ^ (b1) ^ carry;
            res += digit << i;
            if((a1 && b1) || (a1 && carry) || (b1 && carry)) carry = 1;
            else carry = 0;
            a >>=1;
            b >>=1;
        }
        return res;
    }
};
