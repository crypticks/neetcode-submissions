class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string res = "";
        int len1 = word1.size();
        int len2 = word2.size();
        while( i < len1 && j < len2 )
        {
            res+=word1[i++];
            res+=word2[j++];
        }
        while( i < len1 )
        {
            res+=word1[i++];
        }
        while( j < len2 )
        {
            res+=word2[j++];
        }
        return res;
    }
};