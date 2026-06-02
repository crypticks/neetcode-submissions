class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for(string op: operations)
        {
            if(op == "+")
            {
                int v1 = scores.top();
                scores.pop();
                int v2 = scores.top();
                scores.push(v1);
                scores.push(v1+v2);
            }
            else if(op == "C")
            {
                scores.pop();
            }
            else if(op == "D")
            {
                int v = scores.top();
                scores.push(2*v);
            }
            else
            {
                scores.push(stoi(op));
            }
        }
        int sum = 0;
        while(!scores.empty())
        {
            sum+=scores.top();
            scores.pop();
        }
        return sum;
    }
};