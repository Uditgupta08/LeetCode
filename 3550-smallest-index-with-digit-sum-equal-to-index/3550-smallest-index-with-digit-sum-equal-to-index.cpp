class Solution {
public:
    int sumOfDigits(int num){
        int ans = 0;
        while(num > 0){
            int rem = num % 10;
            num = num / 10;
            ans += rem;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            if(sumOfDigits(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};