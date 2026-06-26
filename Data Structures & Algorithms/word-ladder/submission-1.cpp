class Solution {
// Find shortest path : BFS

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // edge: cur -> change one letter -> dict.count(new_word)

        unordered_set<string> visited;

        queue<string> bfs;
        visited.insert(beginWord);
        bfs.push(beginWord);

        int step = 1;

        while (!bfs.empty()) {
            const auto level_size = bfs.size();
            for (int i=0; i<level_size; ++i) {
                auto cur = bfs.front(); bfs.pop();
                if (cur == endWord) return step;
                // find all "neighbors" in dict, unvisited and push to queue
                for (int i=0; i<cur.size(); ++i) {
                    auto next = cur;
                    for(char letter='a'; letter<='z'; ++letter ) {
                        next[i] = letter;
                        if(dict.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            bfs.push(next);
                        }
                    }
                }
            }
            ++step;
        }

        return 0;
    }
};
