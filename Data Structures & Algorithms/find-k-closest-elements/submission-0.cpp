class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int diff = 0;
        for(int i = 0; i < k; i++)
        {
            diff+=abs(arr[i] - x);
        } 
        int mindiff = diff;
        int mindiffindex = 0;
        int i = 0, j = k-1;
        while(j < arr.size()-1)
        {
            j++;
            diff += -abs(arr[i] - x) + abs(arr[j]-x);
            i++;
            if(mindiff > diff)
            {
                mindiff = diff;
                mindiffindex = i;
            }
            
        }
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i+mindiffindex]);
        }
        return res;

    }
};