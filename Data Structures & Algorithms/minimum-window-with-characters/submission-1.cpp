#include <cstring>
class Solution {
private:
    bool arraysMatch(int *a, int *b)
    {
        for (int i = 0; i < 128; i++) {
            if (a[i] > 0 && b[i] < a[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int a[128];
        int b[128];
        memset(a, 0, 128 * sizeof(int));
        memset(b, 0, 128 * sizeof(int));
        for (char c : t) a[c]++;
        int i = 0;
        int minsize = INT_MAX;

        int start_idx = -1;

        for (int j = 0; j < s.size(); j++) {
            cout << "growing " << j << '\n';
            b[(unsigned char)s[j]]++;

            while (arraysMatch(a, b)) {
                cout << "shrinking " << i << '\n';
                int current_window_size = j - i + 1;
                if (current_window_size < minsize) {
                    minsize = current_window_size;
                    start_idx = i;
                }
                b[(unsigned char)s[i]]--; 
                i++;             
            }
        }

        return (start_idx == -1) ? "" : s.substr(start_idx, minsize);

    
    }
};
