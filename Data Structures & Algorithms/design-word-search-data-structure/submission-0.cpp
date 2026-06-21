struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};


class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char c : word)
        {
            if(!curr->children.count(c)) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isWord = true;
        
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        return dfs(word, 0, curr);   
    }

    bool dfs(string& word, int i, TrieNode*& curr)
    {
        if(i == word.size() && curr->isWord) return true;
        if(i == word.size()) return false;
        char c = word[i];
        if(c == '.')
        {
            bool res = false;
            for( auto& [key, value] : curr->children) if(dfs(word, i+1, value)) return true;
            return false;
        } else
        {
            if (!curr->children.count(c)) return false;
            else return dfs(word, i+1, curr->children[c]);
        }
    }
};
