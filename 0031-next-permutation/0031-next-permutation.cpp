class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int curr = -1;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] > a[i - 1]) {
                curr = i-1;
                break;
            }
        }
        if(curr == -1){
            reverse(a.begin(),a.end());
            return;
        }
        int j = n - 1;
        while (j > curr && a[j] <= a[curr]) {
            j--;
        }
        swap(a[curr], a[j]);
        reverse(a.begin() + curr + 1, a.end());
    }
};