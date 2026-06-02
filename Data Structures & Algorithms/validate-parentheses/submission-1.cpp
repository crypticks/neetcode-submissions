class Solution {
public:
    bool isValid(string s) {
        stack<char> parset;
        for(char c:s)
        {
            switch(c)
            {
                case '(': case '{': case '[':
                    parset.push(c);
                    break;
                case ')':
                    if(parset.empty() || parset.top() != '(')
                    {
                        return false;
                    }
                    parset.pop();
                    break;
                case '}':
                    if(parset.empty() || parset.top() != '{')
                    {
                        return false;
                    }
                    parset.pop();
                    break;
                case ']':
                    if(parset.empty() || parset.top() != '[')
                    {
                        return false;
                    }
                    parset.pop();
                    break;
            }
        }
        if(parset.empty()) return true;
        return false;
    }
};
