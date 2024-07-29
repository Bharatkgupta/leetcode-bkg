class Solution {
public:
    int LSW(vector<int>& stones, int i, int curr, vector<unordered_map<int, int>>& dp) {
        if(i == stones.size()) {
            return curr >= 0 ? curr : INT_MAX;
        }
        if(dp[i].find(curr) != dp[i].end()) {
            return dp[i][curr];
        }
        return dp[i][curr] = min(LSW(stones, i+1, curr+stones[i], dp), LSW(stones, i+1, curr-stones[i], dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        vector<unordered_map<int, int>> dp(stones.size());
        return LSW(stones, 0, 0, dp);
    }
};