class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(s.find(nums[i]) != s.end()) {
                ans.push_back(nums[i]);
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};