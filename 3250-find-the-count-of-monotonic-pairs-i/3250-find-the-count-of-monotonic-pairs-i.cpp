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
        int s=prev1, e=nums[i];
        while(s<e) {
            int m = s + (e-s)/2;
            if(nums[i] - m > prev2) {
                s = m+1;
            } else if(nums[i] - m < prev2) {
                e = m-1;
            } else {
                s = e = m;
            }
        }
        int count = 0;
        for(int d=s;d<=nums[i];d++) {
            count = (count+CP(nums, i+1, d, nums[i]-d, dp))%mod;
        }
        return dp[i][prev1][prev2] = count;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (52, vector<int> (52, -1)));
        return CP(nums, 0, 0, 50, dp);
    }
};