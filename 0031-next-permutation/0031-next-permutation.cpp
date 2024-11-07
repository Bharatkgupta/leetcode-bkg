class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i=n-2;
        while(i>=0 && nums[i] >= nums[i+1]) {
            i--;
        }
        int s = i+1, e = n-1;
        while(s<e) {
            swap(nums[s], nums[e]);
            s++;e--;
        }
        s = i+1;
        while(i!=-1 && s<n && nums[i] >= nums[s]) {
            s++;
        }
        if(i!=-1 && s!=n) {
            swap(nums[i], nums[s]);
        }
    }
};