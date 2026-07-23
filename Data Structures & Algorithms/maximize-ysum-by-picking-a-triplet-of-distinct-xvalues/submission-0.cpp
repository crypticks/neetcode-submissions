class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> m;
        for(int i = 0; i < x.size(); i++){
            m[x[i]] = max(m[x[i]], y[i]);
        }
        int i = -1, j = -1, k = -1;
        for(auto& [key, val] : m){
            if(val > i){
                k = j;
                j = i;
                i = val;
            } else if(val > j){
                k = j;
                j = val;
            } else if(val > k){
                k = val;
            }
        }
        if(i >= 0 && j >=0 && k >=0)
            return i + j + k;
        return -1;
    }
};