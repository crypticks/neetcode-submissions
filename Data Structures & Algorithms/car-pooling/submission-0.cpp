class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(1001,0);
        for(auto trip:trips)
        {
            changes[trip[1]]+=trip[0];
            changes[trip[2]]-=trip[0];
        }
        int c = 0;
        for(int change:changes)
        {
            c+=change;
            if(c > capacity) return false;
        }
        return true;
    }
};