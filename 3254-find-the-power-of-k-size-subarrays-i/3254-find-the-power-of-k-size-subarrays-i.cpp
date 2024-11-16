class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) {
            return nums;
        }
        int n = nums.size(), s=0;
        vector<int> results;
        for(int e=1;e<n;e++) {
            if(nums[e-1] + 1 != nums[e]) {
                while(s<n-k+1 && s!=e) {
                    results.push_back(-1);
                    s++;
                }
            }
            if(e-s+1 == k) {
                results.push_back(nums[e]);
                s++;
            }
        }
        return results;
    }
};