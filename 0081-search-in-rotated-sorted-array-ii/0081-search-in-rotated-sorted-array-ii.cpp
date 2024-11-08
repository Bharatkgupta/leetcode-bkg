class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        while(s<=e) {
            int m = s + (e-s)/2;
            
            if(target == nums[m]) {
                return true;
            }
            
            if(nums[s] == nums[e] && nums[m] == nums[s]) {
                s++;
                e--;
            } else if (nums[s] < nums[e]) {
                if(target > nums[m]) {
                    s = m+1;
                } else {
                    e = m-1;
                }
            } else if((nums[s] == nums[e] && nums[m] != nums[s]) || nums[s] > nums[e]) {
                if(nums[m] <= nums[e]) {
                    if(target > nums[m] && target <= nums[e]) {
                        s = m+1;
                    } else if(target > nums[m] && target > nums[e]) {
                        e = m-1;
                    } else {
                        e = m-1;
                    }
                } else {
                    if(target < nums[m] && target < nums[s]) {
                        s = m+1;
                    } else if(target < nums[m] && target >= nums[s]) {
                        e = m-1;
                    } else {
                        s = m+1;
                    }
                }
            }
        }
        return false;
    }
};