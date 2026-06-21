struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string s:words)
            trie.addWord(s);
        vector<string> res;
        string curstring = "";
        for(int r = 0; r < board.size(); r++)
            for(int c = 0; c < board[0].size(); c++)
                f(board, curstring, trie.root, r, c, res);
        return res;

        
    }

    void f(vector<vector<char>>& board, string& curstring, TrieNode* curr, int r, int c, 
            vector<string>& res)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()
            || board[r][c] == '#' || !curr->children.count(board[r][c])) return;
        
        char temp = board[r][c];
        curstring.push_back(temp);
        board[r][c] = '#';
        TrieNode *next = curr->children[temp];
        if(next->isWord)
        {
            res.push_back(curstring);
            next->isWord = false;
        }
        f(board, curstring, next, r+1, c, res);
        f(board, curstring, next, r-1, c, res);
        f(board, curstring, next, r, c+1, res);
        f(board, curstring, next, r, c-1, res);
        board[r][c] = temp;
        curstring.pop_back();
    }

};
