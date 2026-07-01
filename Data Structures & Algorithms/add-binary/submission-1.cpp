class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int m = a.size(), n = b.size();
        int carry = 0;
        int i;
        for(i = 0; i < min(m, n); i++)
        {
            res = (char)((a[m-i-1] + b[n-i-1] + carry - '0' - '0')%2 + '0')+ res;
            carry = (a[m-i-1] + b[n-i-1] + carry - '0' - '0')/2;
        }
        if(m > n)
        {
            while(i < m)
            {
                res = (char)((carry + a[m-i-1] - '0')%2 + '0') + res;
                carry = (a[m-i-1] + carry - '0')/2;
                i++;
            }
        }
        else if(n > m)
        {
            while(i < n)
            {
                res = (char)((carry + b[n-i-1] - '0')%2 + '0') + res;
                carry = (b[n-i-1] + carry - '0')/2;
                i++;
            }
        }
        if(carry) res = (char)(carry + '0') + res;
        return res;
    }
};