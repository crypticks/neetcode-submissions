class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        string curr = "";
        for(char c: path)
        {
            if(c == '/')
            {
                if(curr.size() > 0)
                {
                    tokens.push_back(curr);
                    tokens.push_back("/");
                }
                curr = "";
                continue;
            }
            else curr = curr + c;
        }
        if(curr.size() > 0) tokens.push_back(curr);

        for(string token:tokens)
        {
            cout << token << ' ';
        }

        stack<string> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "/" || tokens[i] == ".")
            {
                continue;
            } else if (!s.empty() && tokens[i] == "..")
            {
                s.pop();
                while(!s.empty() && s.top() == "/") s.pop();
            }
            else if (tokens[i] == "..") continue;
            else s.push(tokens[i]);
        }
        

        string res = "";
        while(!s.empty())
        {
            res = "/" + s.top() + res;
            s.pop();
        }
        if(res=="") return "/";
        return res;

    }
};