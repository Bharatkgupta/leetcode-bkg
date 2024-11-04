class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0;i<n;i++) {
            int is = i, ig = 0, cnt = 0;
            while(ig < n && s[is] == goal[ig]) {
                cnt++;
                is = (is+1)%n;
                ig++;
            }
            if(cnt == n) {
                return true;
            }
        }
        return false;
    }
};