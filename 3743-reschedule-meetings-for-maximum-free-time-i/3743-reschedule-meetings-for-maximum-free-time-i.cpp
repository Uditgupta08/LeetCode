class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int ans = 0;
        vector<int> free;
        free.push_back(startTime[0]);
        int n = startTime.size();
        for (int i = 1; i < n; i++) {
            free.push_back(startTime[i] - endTime[i - 1]);
        }
        free.push_back(eventTime - endTime[n - 1]);
        int l = 0;
        int r = 0;
        int tempSum = 0;
        while (r < free.size()) {
            if (r - l <= k) {
                tempSum += free[r];
                r++;
            } else {
                tempSum -= free[l];
                l++;
            }
            ans = max(ans, tempSum);
        }
        return ans;
    }
};