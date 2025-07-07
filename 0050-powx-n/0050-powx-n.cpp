class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long temp = n;
        bool neg = false;
        if (temp < 0) {
            neg = true;
            temp = -temp;
        }
        while (temp > 0) {
            if (temp % 2 == 0) {
                x = x * x;
                temp = temp / 2;
            } else if (temp % 2 != 0) {
                ans = ans * x;
                temp = temp - 1;
            }
        }
        if (neg) {
            return 1 / ans;
        }
        return ans;
    }
};