class Solution {
public:
    int minCutBacktrack(string s, int i, int e, vector<vector<bool>>& dp, vector<vector<int>>& dpm) {
        if(dp[i][e]) {
            return 0;
        }
        if(dpm[i][e] != -1) {
            return dpm[i][e];
        }
        int mn = INT_MAX;
        for(int j=i;j<e;j++) {
            if(dp[i][j]) {
                mn = min(mn, 1+minCutBacktrack(s, j+1, e, dp, dpm));
            }
        }
        return dpm[i][e] = mn;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i=0;i<n;i++) {
            dp[i][i] = true;
        }
        for(int i=0;i<n-1;i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;   
            }
        }
        for(int l=2;l<n;l++) {
            for(int i=0;i<n-l;i++) {
                dp[i][i+l] = dp[i+1][i+l-1] && (s[i] == s[i+l]);
            }
        }
        vector<vector<int>> dpm(n, vector<int> (n, -1));
        return minCutBacktrack(s, 0, n-1, dp, dpm);
    }
};