class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), s=0, e=n-1;
        while(s<e) {
            int m = s + (e-s)/2;
            // cout<<s<<" "<<e<<endl;
            
            int prev = m == 0 ? INT_MIN : nums[m-1];
            int next = m == n-1 ? INT_MIN : nums[m+1];
            
            if(nums[m] == prev && nums[m] == next) {
                return m;
            }
            if(nums[m] == prev) {
                if(nums[m] > next) {
                    e = m;
                } else {
                    s = m+1;
                }
            }
            if(nums[m] == next) {
                if(nums[m] > prev) {
                    s = m;
                } else {
                    e = m-1;
                }
            }
            if(nums[m] > prev && next > nums[m]) {
                s = m+1;
            }
            if(nums[m] < prev && next < nums[m]) {
                e = m-1;
            }
            if(nums[m] > prev && nums[m] > next) {
                return m;
            }
            if(nums[m] < prev && nums[m] < next) {
                e = m-1;
            }
        }
        return s;
    }
};