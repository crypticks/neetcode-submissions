class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0, r = cardPoints.size() - k;
        int total = 0;

        for (int i = r; i < cardPoints.size(); i++) {
            total += cardPoints[i];
        }

        int res = total;

        while (r < cardPoints.size()) {
            total += cardPoints[l] - cardPoints[r];
            res = max(res, total);
            l++;
            r++;
        }

        return res;
    }
};