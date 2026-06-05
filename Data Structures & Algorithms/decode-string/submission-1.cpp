class Solution {
private:

    bool isAlpha(string s)
    {
        for(char c : s)
        {
            if(!isalpha(c)) return false;
        }
        return true;
    }

public:
    string decodeString(string str) {
        stack<string> s;
        string curr = "";
        for(char c:str)
        {
            //stack<string> ds = s;
            //while(!ds.empty())
            //{
            //    cout << ds.top() << ' ';
            //    ds.pop();
            //}
            //cout << '\n';
            if(c == ']')
            {
                string rep = "";
                if(curr.size() == 0)
                {
                    rep = s.top();
                    s.pop();
                }
                else rep = curr;
                while(isAlpha(s.top()))
                {
                    rep = s.top() + rep;
                    s.pop();
                }
                //cout << rep << ' ';
                int times = stoi(s.top());
                s.pop();
                string st = "";
                for(int i = 0; i < times; i++) st += rep;
                s.push(st);
                curr = "";
            }
            else if(c == '[')
            {
                s.push(curr);
                curr = "";
            }
            else
            {
                if((isalpha(c) && isalpha(curr[0])) || (!isalpha(c) && !isalpha(curr[0]))) curr += c;
                else
                {
                    s.push(curr);
                    curr = "" ;
                    curr += c;
                }
            }

        }
        if(curr.size() > 0 ) s.push(curr);
        while(s.size()>1)
        {
            string k = s.top();
            s.pop();
            string l = s.top();
            s.pop();
            s.push(l+k);
        }
        
        return s.top();
    }
};