class Solution {
    int mod=1e9+7;
public:
    int CP(vector<int>& nums, int i, int prev1, int prev2, vector<vector<vector<int>>>& dp) {
        if(i == nums.size()) {
            return 1;
        }
        if(dp[i][prev1][prev2] != -1) {
            return dp[i][prev1][prev2];
        }
        int count = 0;
        for(int d=prev1;d<=nums[i];d++) {
            if(nums[i]-d <= prev2) {
                count = (count+CP(nums, i+1, d, nums[i]-d, dp))%mod;
            }
        }
        return dp[i][prev1][prev2] = count;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (52, vector<int> (52, -1)));
        return CP(nums, 0, 0, 50, dp);
    }
};