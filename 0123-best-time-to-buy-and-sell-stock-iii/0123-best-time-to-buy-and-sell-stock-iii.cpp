class Solution {
public:
    int MP(vector<int>& prices, int idx, int state, int isBuy, vector<vector<vector<int>>>& dp) {
        if(idx == prices.size() || state == 0) {
            return 0;
        }
        if(dp[idx][state][isBuy] != -1) {
            return dp[idx][state][isBuy];
        }
        int profit = MP(prices, idx+1, state, isBuy, dp);
        if(isBuy) {
            profit = max(profit, MP(prices, idx+1, state, 0, dp)-prices[idx]);
        } else {
            profit = max(profit, MP(prices, idx+1, state-1, 1, dp)+prices[idx]);
        }
        return dp[idx][state][isBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2, -1)));
        return MP(prices, 0, 2, 1, dp);
    }
};