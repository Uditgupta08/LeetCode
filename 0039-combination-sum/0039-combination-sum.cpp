class Solution {
public:
    void solve(int ind, int target, vector<int>& arr, vector<vector<int>>& ans,
               vector<int>& curr) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        if (arr[ind] <= target) {
            curr.push_back(arr[ind]);
            solve(ind, target - arr[ind], arr, ans, curr);
            curr.pop_back();
        }
        solve(ind + 1, target, arr, ans, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, candidates, ans, curr);
        return ans;
    }
};