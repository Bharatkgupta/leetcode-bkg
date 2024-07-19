class Solution {
public:
    void permutations(vector<int>& nums, vector<bool>& visited, vector<int>& temp, vector<vector<int>>& ans) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.push_back(nums[i]);
                permutations(nums, visited, temp, ans);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        permutations(nums, visited, temp, ans);
        return ans;
    }
};