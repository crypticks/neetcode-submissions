class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> onhand = {0,0};
        for(int bill : bills)
        {
            if(bill == 5) onhand[0]++;
            else if(bill == 10)
            {
                onhand[0]--;
                onhand[1]++;
            }
            else
            {
                if(onhand[1]>0)
                {
                    onhand[1]--;
                    onhand[0]--;
                }
                else
                {
                    onhand[0]-=3;
                }
            }
            if(onhand[0]<0) return false;
        }
        return true;
    }
};