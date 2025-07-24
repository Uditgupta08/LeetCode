class FreqStack {
public:
    unordered_map<int, int> m;
    int maxFreq = 0;
    vector<stack<int>> freqStack;
    FreqStack() {}

    void push(int val) {
        m[val]++;
        int curr = m[val];
        maxFreq = max(maxFreq, curr);
        if (freqStack.size() < curr) {
            stack<int> st;
            st.push(val);
            freqStack.push_back(st);
        } else {
            freqStack[curr - 1].push(val);
        }
    }

    int pop() {
        int n = freqStack.size() - 1;
        int res = freqStack[n].top();
        freqStack[n].pop();
        m[res]--;
        if (freqStack[n].empty()) {
            freqStack.pop_back();
            maxFreq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */