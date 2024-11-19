class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), distinct = 0;
        long long sum = 0, mxSum = 0;
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(freq.find(nums[i]) == freq.end() || (freq.find(nums[i]) != freq.end() && freq[nums[i]] == 0)) {
                distinct++;
                freq[nums[i]] = 0;
            }
            freq[nums[i]]++;
            
            if(i>=k) {
                sum -= nums[i-k];
                freq[nums[i-k]]--;
                if(freq[nums[i-k]] == 0) {
                    distinct--;
                }
            }
            
            if(distinct == k) {
                mxSum = max(mxSum, sum);
            }
        }
        return mxSum;
    }
};