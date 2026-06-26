class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.count(target) || visited.count("0000")) return -1;

        unordered_set<string> begin = {"0000"}, end = {target};

        int steps = 0;
        while(!begin.empty() && !end.empty())
        {
            if(begin.size() > end.size()) swap(begin, end);
            steps++;
            unordered_set<string> temp;
            for(const string& s : begin)
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j : {-1,1})
                    {
                        string next = s;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        if(end.count(next)) return steps;
                        if(visited.count(next)) continue;
                        visited.insert(next);
                        temp.insert(next);

                    }
                }
            }
            begin = temp;
        }

        return -1;
    }
};