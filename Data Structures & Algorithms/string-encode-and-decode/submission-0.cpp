class Solution {
public:

    string encode(vector<string>& strs) {
        int len;
        string res;
        for(string str:strs)
        {
            len = str.size();
            res+=to_string(len) + '#' + str;
        }
        return res;
    }

    vector<string> decode(string s) {

        int len = s.size();
        int i = 0;
        string curr_len;
        string curr_string;
        vector<string> res;
        while(i<len)
        {
            curr_len="";
            curr_string = "";
            while(s[i]!='#')
            {
                curr_len+=s[i];
                i++;
            }
            int to_read = stoi(curr_len);
            for(int j = 0; j < to_read; j++)
            {
                curr_string+=s[i+j+1];
            }
            res.push_back(curr_string);
            i += to_read + 1;
        }
        return res;

    }
};
