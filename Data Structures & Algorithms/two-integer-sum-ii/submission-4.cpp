class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len-1;
        while(i<len && j < len)
        {
            int sum = numbers[i] + numbers[j];
            if(sum>target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else {
                return {i+1, j+1};
            }
        }
        return {0, 0};
    }
};
