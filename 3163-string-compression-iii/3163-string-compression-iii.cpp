class Solution {
public:
    string compressedString(string word) {
        int cnt = 0;
        char c = word[0];
        string ans = "";
        for(const char& ch : word) {
            if(c == ch) {
                cnt++;
                if(cnt == 9) {
                    ans += ('0'+cnt);
                    ans += c;
                    cnt = 0;
                }
            } else {
                if(cnt != 0) {
                    ans += ('0'+cnt);
                    ans += c;
                }
                c = ch;
                cnt = 1;
            }
        }
        if(cnt != 0) {
            ans += ('0'+cnt);
            ans += c;
        }
        return ans;
    }
};