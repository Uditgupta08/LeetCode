class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int sum = 0;
        int curr = 0;
        while (r < n) {
            freq[nums[r]]++;
            curr += nums[r];
            while (freq.size() < r - l + 1) {
                curr -= nums[l];
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            r++;
            sum = max(sum, curr);
        }
        return sum;
    }
};