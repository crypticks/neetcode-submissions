class Solution {
private:
    int value(string& word, int pos)
    {
        if(pos >= word.size()) return 0;
        return this->pos[word[pos]];
    }
public:
    unordered_map<char, int> pos;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++) pos[order[i]] = i;
        int maxlen = 0;
        for(string word : words)
        {
            maxlen = max(maxlen, int(word.size()));
        }

        for(int j = 0; j < words.size() - 1; j++)
        {
            for(int i = 0; i < maxlen; i++)
            {
                if(value(words[j], i) > value(words[j+1], i))
                {
                    return false;
                }
                if(value(words[j], i) < value(words[j+1], i)) break;
            }
        }
        return true;
    }
};