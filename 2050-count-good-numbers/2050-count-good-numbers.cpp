class Solution {
public:
    int mod = 1e9 + 7;
    long long modPow(long long x, long long power) {
        x = x % mod;
        long long temp = power;
        long long ans = 1;
        while (temp > 0) {
            if (temp % 2 == 0) {
                x = (x * x) % mod;
                temp = temp / 2;
            } else if (temp % 2 != 0) {
                ans = (ans * x) % mod;
                temp = temp - 1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = modPow(5, ((n + 1) / 2));
        long long odd = modPow(4, (n / 2));
        return (even * odd) % mod;
    }
};