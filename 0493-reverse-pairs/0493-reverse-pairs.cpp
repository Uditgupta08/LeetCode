class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int l = low;
        int r = mid + 1;
        while (l <= mid && r <= high) {
            if (arr[l] <= arr[r]) {
                temp.push_back(arr[l]);
                l++;
            } else {
                temp.push_back(arr[r]);
                r++;
            }
        }
        while (l <= mid) {
            temp.push_back(arr[l]);
            l++;
        }
        while (r <= high) {
            temp.push_back(arr[r]);
            r++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    int countPair(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int r = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (r <= high && (long long)arr[i] > 2LL * arr[r]) {
                r++;
            }
            count += (r - (mid + 1));
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int ans = 0;
        if (low >= high) {
            return ans;
        }
        int mid = low + (high - low) / 2;
        ans += mergeSort(arr, low, mid);
        ans += mergeSort(arr, mid + 1, high);
        ans += countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};