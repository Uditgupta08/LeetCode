class Solution {
public:
    void solve(int ind, int target, vector<int>& arr, vector<vector<int>>& ans,
               vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            curr.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, candidates, ans, curr);
        return ans;
    }
};