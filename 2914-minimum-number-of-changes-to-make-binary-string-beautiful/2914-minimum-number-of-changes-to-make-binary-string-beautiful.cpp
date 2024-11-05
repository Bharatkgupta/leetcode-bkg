class Solution {
public:
    int minChanges(string s) {
        int cnt = 0, len = 0;
        char prev = s[0];
        for(const char& b : s) {
            if(b == prev) {
                len++;
            } else {
                if(len%2) {
                    cnt++;
                    len++;
                } else {
                    len = 1;
                    prev = b;
                }
            }
        }
        return cnt;
    }
};