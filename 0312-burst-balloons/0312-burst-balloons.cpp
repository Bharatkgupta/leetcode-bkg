class Solution {
    int dBalloons(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if(s>e) {
            return 0;
        }
        if(dp[s][e] != -1) {
            return dp[s][e];
        }
        int mx = 0;
        for(int m=s;m<=e;m++) {
            int left = dBalloons(nums,s,m-1,dp);
            int right = dBalloons(nums,m+1,e,dp);
            int center = (s-1>=0?nums[s-1]:1) * nums[m] * (e+1<nums.size()?nums[e+1]:1);
            mx = max(mx,left+right+center);
        }
        return dp[s][e] = mx;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return dBalloons(nums, 0, n-1, dp);
    }
};