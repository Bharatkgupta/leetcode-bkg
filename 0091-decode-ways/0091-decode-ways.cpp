class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') {
            return 0;
        }
        int n = s.length();
        vector<int> memo(n+1, 0);
        memo[0] = 1;
        for(int i=1;i<=n;i++) {
            if(s[i-1] != '0') {
                memo[i] += memo[i-1];
            }
            if(i-2 >= 0 && s[i-2] != '0' && stoi(s.substr(i-2, 2)) > 0 && stoi(s.substr(i-2, 2)) < 27) {
                memo[i] += memo[i-2];
            }
        }
        return memo[n];
    }
};