class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), mx = 0, ans = 0;
        for(int i=n-2;i>=0;i--) {
            if(nums[i] > nums[i+1]) {
                mx = max(mx, nums[i]);
            }
        }
        vector<int> lpd(mx+1, 0);
        for (int d = 2; d < mx+1; ++d) {
            for (int multiple = d * 2; multiple < mx+1; multiple += d) {
                if (lpd[multiple] == 0) {
                    lpd[multiple] = d;  // Set the lowest divisor if not set already
                }
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(nums[i] > nums[i+1]) {
                if(lpd[nums[i]] == 0) {
                    return -1;
                } else {
                    nums[i] = lpd[nums[i]];
                    if(nums[i] > nums[i+1]) {
                        return -1;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};