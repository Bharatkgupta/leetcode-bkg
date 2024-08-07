class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        for(int l=1;l<n;l++) {
            for(int i=0;i<n-l;i++) {
                if(s[i] == s[i+l]) {
                    dp[i][i+l] = dp[i+1][i+l-1] + 2;
                } else {
                    dp[i][i+l] = max(dp[i+1][i+l-1], max(dp[i][i+l-1], dp[i+1][i+l]));
                }
            }
        }
        return dp[0][n-1];
    }
};