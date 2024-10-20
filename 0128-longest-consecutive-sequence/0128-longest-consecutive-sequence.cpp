class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> prev;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(prev.find(nums[i]) != prev.end()) {
                continue;
            }
            if(prev.find(nums[i]-1) != prev.end()) {
                prev[nums[i]] = true;
            } else {
                prev[nums[i]] = false;
            }
            if(prev.find(nums[i]+1) != prev.end()) {
                prev[nums[i]+1] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(prev[nums[i]] == false) {
                int j = nums[i];
                while(prev.find(j) != prev.end()) {
                    j++;
                }
                ans = max(ans, j-nums[i]);
            }
        }
        return ans;
    }
};