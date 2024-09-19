class Solution {
    // int MS(vector<int>& a, vector<int>& b, int ia, int ib, vector<vector<long long>>& dp) {
    //     if(ia == 4) {
    //         return 0;
    //     }
    //     if(ib == b.size()) {
    //         return -1e5;
    //     }
    //     if(dp[ib][ia] != -1) {
    //         return dp[ib][ia];
    //     }
    //     return dp[ib][ia] = max(MS(a, b, ia, ib+1, dp), a[ia]*b[ib]+MS(a, b, ia+1, ib+1, dp));
    // }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long>> dp(n+1, vector<long> (5, -1));
        for(int i=0;i<5;i++) {
            dp[n][i] = -1e11;
        }
        for(int i=0;i<=n;i++) {
            dp[i][4] = 0;
        }
        for(int ib=n-1;ib>=0;ib--) {
            for(int ia=3;ia>=0;ia--) {
                dp[ib][ia] = max(dp[ib+1][ia], ((long) a[ia]*b[ib])+dp[ib+1][ia+1]);
            }
        }
        return dp[0][0];
    }
};