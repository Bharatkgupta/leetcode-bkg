class Solution {
public:
    bool find(vector<int>& nums, int i, int sum, int target, vector<vector<int>>& dp) {
        if(sum == target) {
            return true;
        }
        if(i == nums.size() || sum > target) {
            return false;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        return dp[i][sum] = find(nums, i+1, sum, target, dp) || find(nums, i+1, sum+nums[i], target, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const int& num : nums) {
            sum += num;
        }
        int target = sum/2;
        if(2*target != sum) {
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int> (target, -1));
        return find(nums, 0, 0, target, dp);
    }
};