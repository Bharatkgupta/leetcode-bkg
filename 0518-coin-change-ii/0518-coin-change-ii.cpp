class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(const int& coin : coins) {
            for(int i=1;i<=amount;i++) {
                dp[i] = dp[i] + (i>=coin ? dp[i-coin] : 0);
            }
        }
        return dp[amount];
    }
};