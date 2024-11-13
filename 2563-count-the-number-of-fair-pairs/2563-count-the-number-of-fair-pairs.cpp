class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        
        // Iterate over each element with index i
        for (int i = 0; i < n; ++i) {
            int nl = lower - nums[i]; // minimum needed for a fair pair
            int nu = upper - nums[i]; // maximum needed for a fair pair
            
            // Use binary search to find the range of valid j's
            // Find the smallest index j where nums[j] >= nl and j > i
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), nl);
            // Find the first index j where nums[j] > nu
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), nu);
            
            // Count the number of valid pairs
            count += distance(left, right);
        }
        
        return count;
    }
};