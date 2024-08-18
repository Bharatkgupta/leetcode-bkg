class Solution {
public:
    int MST(vector<int>& v, int s, int e, vector<vector<int>>& dp) {
        if(dp[s][e] != -1) {
            return dp[s][e];
        }
        int mn = INT_MAX;
        for(int m = s+1; m < e; m++) {
            mn = min(mn, MST(v, s, m, dp)+v[s]*v[e]*v[m]+MST(v, m, e, dp));
        }
        return dp[s][e] = mn == INT_MAX ? 0 : mn;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return MST(values, 0, n-1, dp);
    }
};