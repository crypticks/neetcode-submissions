class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i< position.size(); i++)
        {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        stack<double> s;
        for(auto& p: pairs)
        {
            double t = (target-p.first)/(double)(p.second);
            if(s.empty() || s.top() < t) 
            {
                s.push(t);
            }
        }
        return s.size();
    }
};
