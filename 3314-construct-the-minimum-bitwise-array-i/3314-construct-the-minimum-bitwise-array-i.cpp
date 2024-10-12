class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            int temp = 1;
            while(nums[i] & temp) {
                temp *= 2;
            }
            ans.push_back(nums[i]-(temp/2));
        }
        return ans;
    }
};