class Solution {
public:
    void CSR(vector<int>& candidates, int target, int i, vector<int>& currComb, int sum, vector<vector<int>>& ans) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            ans.push_back(currComb);
            return;
        }
        for(int j=i; j<candidates.size(); j++) {
            currComb.push_back(candidates[j]);
            CSR(candidates, target, j, currComb, sum+candidates[j], ans);
            currComb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        CSR(candidates, target, 0, currComb, 0, ans);
        return ans;
    }
};