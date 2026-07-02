class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        float curravg = 0;
        for(int i = 0; i < k; i++)
        {
            curravg += arr[i];
        }
        curravg /= k;
        if(curravg >= threshold) res++;
        int l = 0;
        for(int i = k; i < arr.size(); i++)
        {
            curravg += (arr[i] - arr[l++])/(float)k;
            if(curravg >= threshold) res++;
        }
        return res;
    }
};