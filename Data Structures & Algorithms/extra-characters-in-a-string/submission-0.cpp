struct TrieNode
{
    unordered_map<char, TrieNode*> nexts;
    bool isWord = false;
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    { root = new TrieNode(); }

    void addWord(const string& word)
    {
        TrieNode *curr = root;
        for(char c : word)
        {
            if(!curr->nexts.count(c)) curr->nexts[c] = new TrieNode();
            curr = curr->nexts[c];
        }
        curr->isWord = true;
    }
};



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for(auto s : dictionary)
        {
            trie.addWord(s);
        }

        int n = s.size();
        vector<int> dp(n+1);
        for(int i = n-1; i >=0; --i)
        {
            TrieNode *curr = trie.root;
            dp[i] = 1 + dp[i+1];
            for(int j = i; j < n; j++)
            {
                if(!curr->nexts.count(s[j])) break;
                curr = curr->nexts[s[j]];
                if(curr->isWord) dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
        
    }
};