class Solution {
public:
    void makeSubsets(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        makeSubsets(nums, i+1, temp, ans);
        temp.push_back(nums[i]);
        makeSubsets(nums, i+1, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        makeSubsets(nums, 0, temp, ans);
        return ans;
    }
};