class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int prev = -1, cnt = 0;
        for(const char& ch : s) {
            if(prev != ch-'a') {
                prev = ch-'a';
                cnt=0;
            }
            cnt++;
            if(cnt<3) {
                ans += ch;
            }
        }
        return ans;
    }
};