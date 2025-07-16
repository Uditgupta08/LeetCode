class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int eve = 0;
        int odd = 0;
        int alt = 0;
        int prev = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                eve++;
            }
            else{
                odd++;
            }
            if(nums[i] % 2 != prev){
                prev = nums[i]%2;
                alt++;
            }
        }
        return max(alt,max(eve,odd));
    }
};