class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset; 
        for(int num:nums)
        {
         hashset.insert(num);
        }
        int maxlength = 0;
        int length;
        for(int it: hashset)
        {
            length = 1;
            while(hashset.find(it+1) != hashset.end())
            {
                length++;
                it = it+1;
            }
            if(length>maxlength)
            {
                maxlength = length;
            }
         
        }
        return maxlength;
    }
};
