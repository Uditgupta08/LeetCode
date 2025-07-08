class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < nums.size()){
            if(nums[r] == 0 && k == 0){
                while(nums[l] != 0){
                    l++;
                }
                k++;
                l++;
            }
            if(nums[r] == 0){
                k--;
            }
            r++;
            ans = max(ans, r - l);
        }   
        return ans;
    }
};