class Solution {
    int calculateCoins(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if(l>r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int mxCoins = 0;
        for(int i=l;i<=r;i++) {
            int leftCoins = calculateCoins(nums, l, i-1, dp);
            int rightCoins = calculateCoins(nums, i+1, r, dp);
            int midCoins = nums[i]*(l==0 ? 1 : nums[l-1])*(r==nums.size()-1 ? 1 : nums[r+1]);
            mxCoins = max(mxCoins, leftCoins+rightCoins+midCoins);
        }
        return dp[l][r] = mxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return calculateCoins(nums, 0, n-1, dp);
    }
};