class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        stack<int> indices;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!s.empty() && s.top() < temperatures[i])
            {
                res[indices.top()] = i - indices.top();
                s.pop();
                indices.pop();
            }
            s.push(temperatures[i]);
            indices.push(i);
        }
        return res;
    }
};
