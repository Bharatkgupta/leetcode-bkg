class Solution {
public:
    int TGS(vector<int>& nums, int index, int remaining, vector<unordered_map<int,int>>& dp) {
        if(index == nums.size()) {
            if(remaining == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if(dp[index].find(remaining) != dp[index].end()) {
            return dp[index][remaining];
        }
        return dp[index][remaining] = TGS(nums, index+1, remaining+nums[index], dp) + TGS(nums, index+1, remaining-nums[index], dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return TGS(nums, 0, target, dp);
    }
};