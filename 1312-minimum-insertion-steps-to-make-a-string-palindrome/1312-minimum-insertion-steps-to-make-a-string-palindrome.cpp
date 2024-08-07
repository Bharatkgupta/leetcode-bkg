class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int l=1;l<n;l++) {
            for(int i=0;i<n-l;i++) {
                if(s[i] == s[i+l]) {
                    dp[i][i+l] = dp[i+1][i+l-1];
                } else {
                    dp[i][i+l] = min(dp[i][i+l-1], dp[i+1][i+l])+1;
                }
            }
        }
        return dp[0][n-1];
    }
};