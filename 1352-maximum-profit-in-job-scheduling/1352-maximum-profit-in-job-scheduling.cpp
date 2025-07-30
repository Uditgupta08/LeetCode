class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        // SORT BY END TIME
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n);
        // TAKE INITIALLY PROFIT OF 1ST JOB
        dp[0] = jobs[0][2];

        // ITERATE OVER ALL JOBS
        for (int i = 1; i < n; ++i) {
            int currProfit = jobs[i][2];
            int l = 0, r = i - 1;
            int prevPossible = -1;
            // BTA BHAI AGAR YE LELI TO ISSE PEHLE KONSI LU
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][0] <= jobs[i][1]) { 
                    prevPossible = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            // MIL GYI 1 PREV JOB
            if (prevPossible != -1) {
                currProfit += dp[prevPossible];
            }
            // NOT TAKE , TAKE KA MAX LELE
            dp[i] = max(dp[i - 1], currProfit);
        }
        return dp[n - 1];
    }
};
