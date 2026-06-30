class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res;
        for(int i = digits.size() - 1; i>=0; i--)
        {
            digits[i] = (digits[i] + carry)%10;
            carry = (digits[i] == 0 && carry == 1) ? 1 : 0;
            if(i == 0) if(carry) res.push_back(1);
        }
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};
