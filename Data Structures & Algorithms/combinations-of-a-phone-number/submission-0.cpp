class Solution {
unordered_map<char, vector<char>> mapping = {
    { '2' , {'a', 'b', 'c'} },
    { '3' , {'d', 'e', 'f'} },
    { '4' , {'g', 'h', 'i'} },
    { '5' , {'j', 'k', 'l'} },
    { '6' , {'m', 'n', 'o'} },
    { '7' , {'p', 'q', 'r', 's'} },
    { '8' , {'t', 'u', 'v'} },
    { '9' , {'w', 'x', 'y', 'z'} }
};
private:
    void f(string digits, int i, string& curr, vector<string>& res)
    {
        if(i == digits.size()) { res.push_back(curr); return; }

        for(char c : mapping[digits[i]])
        {
            curr += c;
            f(digits, i+1, curr, res);
            curr.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> res;
        string curr = "";
        f(digits, 0, curr, res);
        return res;
    }
};
