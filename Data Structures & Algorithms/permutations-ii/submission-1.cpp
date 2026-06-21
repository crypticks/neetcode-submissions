class Solution {
private:
    void f(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res)
    {
        if(i >= nums.size()) { res.push_back(curr); return; }
        unordered_set<int> swapped;
        for(int j = i; j < nums.size(); j++)
        {
            if(swapped.find(nums[j]) == swapped.end())
            {
                swapped.insert(nums[j]);
                swap(nums[i], nums[j]);
                curr.push_back(nums[i]);
                f(nums, i+1, curr, res);
                curr.pop_back();
                swap(nums[i], nums[j]);

            }
        
        }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        //unordered_map<int, int> counts;
        //vector<int> uniq;
        vector<int> curr;
        //for(int num: nums)
        //{
        //    if(!counts[num]) uniq.push_back(num);
        //    counts[num]++;
        //}
        f(nums, 0, curr, res);
        return res;
    }
};