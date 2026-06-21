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
private:


public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string word:wordDict) trie.addWord(word);

        unordered_map<int, vector<string>> cache;
        return backtrack(0, s, trie, cache);
        
    }

    vector<string> backtrack(int idx, string& s, Trie& trie, unordered_map<int,vector<string>>& cache)
    {
        if(idx == s.size()) return {""};
        if(cache.count(idx)) return cache[idx];
        TrieNode* curr = trie.root;

        vector<string> res;
        for(int i = idx; i < s.size(); i++)
        {
            char c = s[i];
            if(!curr->children.count(c)) break;
            curr = curr->children[c];
            if(curr->isWord)
            {
                for(string& suffix : backtrack(i+1, s, trie, cache))
                {
                    if(!suffix.empty()) res.push_back(s.substr(idx, i + 1 - idx) + " " + suffix);
                    else res.push_back(s.substr(idx, i + 1 - idx));
                }
            }
        }
        cache[idx] = res;
        return res;
    }
};