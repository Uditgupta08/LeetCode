class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        int count1 = 0;
        int count2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && a[i] != e2) {
                count1 = 1;
                e1 = a[i];
            } else if (count2 == 0 && a[i] != e1) {
                count2 = 1;
                e2 = a[i];
            } else if (e1 == a[i]) {
                count1++;
            } else if (e2 == a[i]) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (e1 == a[i]) {
                count1++;
            }
            if (e2 == a[i]) {
                count2++;
            }
        }
        int mini = (n / 3) + 1;
        if (count1 >= mini) {
            ans.push_back(e1);
        }
        if (count2 >= mini) {
            ans.push_back(e2);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};