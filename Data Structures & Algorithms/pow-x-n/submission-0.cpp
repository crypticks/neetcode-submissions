class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n > 0)
            while(n--) res = res * x;
        else
            while(n++) res = res / x;
        return res;
    }
};
