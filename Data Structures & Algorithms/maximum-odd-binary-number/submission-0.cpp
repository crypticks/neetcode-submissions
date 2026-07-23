class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c1 = 0, c0 = 0;
        for(char c : s){
            if(c == '1') c1++;
            if(c == '0') c0++;
        }

        string res = "";
        for(int i = 1; i < c1; i++) res.push_back('1');
        for(int i = 0; i < c0; i++) res.push_back('0');
        res.push_back('1');
        return res;
    }
};