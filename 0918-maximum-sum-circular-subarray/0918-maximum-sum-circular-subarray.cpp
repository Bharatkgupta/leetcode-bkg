class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = 0, neg = 0, mn = 0, pos = 0, mx = INT_MIN;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            pos += nums[i];
            mx = max(pos, mx);
            if(pos < 0) {
                pos = 0;
            }
            neg += nums[i];
            mn = min(neg, mn);
            if(neg > 0) {
                neg = 0;
            }
        }
        if(sum == mn) {
            return mx;
        }
        return max(sum - mn, mx);
    }
};