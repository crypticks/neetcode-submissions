class Solution {
public:
    int maxArea(vector<int>& heights) {
        int len = heights.size();
        int i = 0;
        int j = len-1;
        int res = 0;
        while(i<j)
        {
            int area = min(heights[i], heights[j]) * (j-i);
            res = max(res, area);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return res;
    }
};
