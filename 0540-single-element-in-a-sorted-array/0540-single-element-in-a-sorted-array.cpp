class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        while(s<e) {
            int m = s + (e-s)/2;
            if(nums[m] == nums[m-1]) {
                if((m-s)%2) {
                    s = m+1;
                } else {
                    e = m; 
                }
            } else if(nums[m] == nums[m+1]) {
                if((m-s)%2) {
                    e = m-1;
                } else {
                    s = m;
                }
            } else {
                s = e = m;
            }
        }
        return nums[s];
    }
};