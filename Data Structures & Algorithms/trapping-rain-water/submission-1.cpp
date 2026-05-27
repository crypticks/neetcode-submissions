class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        if(j==0) return 0;
        int res = 0;
        vector<int> maxheights(j+1, 0);
        maxheights[j] = height[j];
        for(int s = j-1; s>=0; s--) maxheights[s] = max(maxheights[s+1], height[s]);

        while(height[i] == 0) i++;
        while(height[j] == 0) j--;
        while(i<j)
        {
            int cur_height = min(maxheights[i+1], height[i]);
            int k = i+1;
            while(k < j && height[k]<cur_height)
            {
                res+=cur_height-height[k];
                k++;
            }
            i = k;
        }
        return res;
        
    }
};
