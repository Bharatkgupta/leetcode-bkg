class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1, ans = -1;
        while(s<=e) {
            int m = (e-s)/2 + s;
            if(nums[s]<=nums[e]) {
                if(target < nums[m]) {
                    e = m-1;
                } else if(target > nums[m]) {
                    s = m+1;
                } else {
                    ans = m;
                    break;
                }
            } else {
                if(nums[m] > nums[e]) {
                    if(target > nums[e] && target < nums[m]) {
                        e = m-1;
                    } else if(target > nums[m] || target < nums[e]) {
                        s = m+1;
                    } else if(target == nums[e]) {
                        ans = e;
                        break;
                    } else if(target == nums[m]) {
                        ans = m;
                        break;
                    }
                } else {
                    if(target < nums[e] && target > nums[m]) {
                        s = m+1;
                    } else if(target < nums[m] || target > nums[e]) {
                        e = m-1;
                    } else if(target == nums[e]) {
                        ans = e;
                        break;
                    } else if(target == nums[m]) {
                        ans = m;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};