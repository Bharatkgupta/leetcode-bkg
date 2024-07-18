class Solution {
    int freq[51];
public:
    void combinationSum(int i, int remaining, vector<int>& temp, vector<vector<int>>& ans) {
        if(remaining == 0) {
            ans.push_back(temp);
            return;
        }
        if(i == 51 || remaining < 0) {
            return;
        }
        for(int j=0;j<=freq[i];j++) {
            for(int k=0;k<j;k++) {
                temp.push_back(i);
                remaining -= i;
            }
            combinationSum(i+1, remaining, temp, ans);
            for(int k=0;k<j;k++) {
                temp.pop_back();
                remaining += i;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(const int& candidate : candidates) {
            freq[candidate]++;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(1, target, temp, ans);
        return ans;
    }
};