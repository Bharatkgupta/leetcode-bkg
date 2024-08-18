class Solution {
public:
    int MS(vector<int>& stones, int s, int e, int numPiles, int totalPiles , vector<int>& prefixSum, vector<vector<vector<int>>>& dp) {
        if(s==e && numPiles != 1) {
            return INT_MAX/4;
        }
        if(dp[s][e][numPiles] != -1) {
            return dp[s][e][numPiles];
        }
        if(numPiles == 1) {
            dp[s][e][numPiles] = MS(stones, s, e, totalPiles, totalPiles, prefixSum, dp) + (s==0 ? prefixSum[e] : prefixSum[e]-prefixSum[s-1]);
        } else {
            int mn = INT_MAX;
            for(int m=s;m<e;m++) {
                mn = min(mn, MS(stones, s, m, 1, totalPiles, prefixSum, dp)+MS(stones, m+1, e, numPiles-1, totalPiles, prefixSum, dp));
            }
            dp[s][e][numPiles] = mn;
        }
        return dp[s][e][numPiles];
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)!=0) return -1;
        
        vector<int> prefixSum(n, stones[0]);
        for(int i=1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1]+stones[i];
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (k+1, -1)));
        for(int i=0;i<n;i++) {
            dp[i][i][1] = 0;
        }
        
        return MS(stones, 0, n-1, 1, k, prefixSum, dp);
    }
};