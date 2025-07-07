class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        long long ans = 0;
        bool pos = true;
        if (s[i] == '-') {
            pos = false;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (s[i] == '0') {
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            i++;
            if (pos && ans > INT_MAX) {
                return INT_MAX;
            } else if (!pos && ans > INT_MAX) {
                return INT_MIN;
            }
        }
        if (pos) {
            return ans;
        }
        return -ans;
    }
};