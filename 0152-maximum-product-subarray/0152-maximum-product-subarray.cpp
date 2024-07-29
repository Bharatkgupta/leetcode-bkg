class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long double mx = nums[0], mn = nums[0], ans = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i] < 0) {
                double temp = mx;
                mx = mn;
                mn = temp;
            }
            
            if(nums[i] >= nums[i]*mx) {
                mx = nums[i];
            } else {
                mx  = nums[i]*mx;
            }
            if(nums[i] <= nums[i]*mn) {
                mn = nums[i];
            } else {
                mn  = nums[i]*mn;
            }
            
            if(ans < mx) {
                ans = mx;
            }
        }
        return (int)ans;
    }
};