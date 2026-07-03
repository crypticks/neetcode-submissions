class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, fruit1_lastIdx = 0, fruit2_lastIdx = -1;
        int fruit1 = fruits[0], fruit2 = -1, total = 1, res = 1;

        for (int r = 0; r < fruits.size(); r++) {
            int f = fruits[r];
            if (f == fruit1) {
                total++;
                fruit1_lastIdx = r;
            } else if (f == fruit2 || fruit2 == -1) {
                total++;
                fruit2_lastIdx = r;
                fruit2 = f;
            } else {
                if (fruit2_lastIdx == min(fruit1_lastIdx, fruit2_lastIdx)) {
                    swap(fruit1_lastIdx, fruit2_lastIdx);
                    swap(fruit1, fruit2);
                }
                total -= (fruit1_lastIdx - l + 1);
                l = fruit1_lastIdx + 1;
                fruit1 = f;
                fruit1_lastIdx = r;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};