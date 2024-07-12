class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        stack<char> st;
        for(const char ch : s) {
            if (ch == top[1] && !st.empty() && st.top() == top[0]) {
                ans += top_score;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        stack<char> stn;
        while(!st.empty()) {
            char top = st.top();
            st.pop();
            if (top == bot[0] && !stn.empty() && stn.top() == bot[1]) {
                ans += bot_score;
                stn.pop();
            } else {
                stn.push(top);
            }
        }

        return ans;
    }
};