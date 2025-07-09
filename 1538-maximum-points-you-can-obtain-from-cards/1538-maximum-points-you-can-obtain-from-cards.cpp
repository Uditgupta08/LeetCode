class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        if (k >= cardPoints.size()) {
            for (auto it : cardPoints) {
                sum += it;
            }
            return sum;
        }
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        sum = max(sum, lsum);
        int rcurr = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rcurr];
            rcurr--;
            sum = max(sum, lsum + rsum);
        }
        return sum;
    }
};