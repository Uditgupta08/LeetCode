class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (auto it : str) {
            if (it == '{' || it == '[' || it == '(') {
                s.push(it);
            } else {
                if (s.empty()) {
                    return false;
                }
                char top = s.top();
                if ((it == ')' && top != '(') || (it == '}' && top != '{') ||
                    (it == ']' && top != '[')) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};