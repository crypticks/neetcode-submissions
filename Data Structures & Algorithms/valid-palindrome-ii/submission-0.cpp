class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;
            if(s[i] != s[j]) return (isPalin(s, i+1, j) || isPalin(s, i, j-1));

            i++; j--;
        }
        return true;
        
    }

    bool isPalin(string s, int i, int j)
    {
        while(i<j)
        {
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};