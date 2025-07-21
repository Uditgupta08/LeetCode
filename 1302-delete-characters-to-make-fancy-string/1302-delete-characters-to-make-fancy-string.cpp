class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int curr = 1;
        ans += s[0];  
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                curr = 1;  
            }
            if (curr < 3) {
                ans += s[i];
            }
        }
        return ans;
    }
};
