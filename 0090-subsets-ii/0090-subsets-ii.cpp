class Solution {
    int freq[21];
public:
    void makeSubsets(int i, vector<int>& temp, vector<vector<int>>& ans) {
        if(i == 21) {
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<=freq[i];j++) {
            for(int k=0;k<j;k++) {
                temp.push_back(i-10);
            }
            makeSubsets(i+1, temp, ans);
            for(int k=0;k<j;k++) {
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for(const int& num : nums) {
            freq[num+10]++;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        makeSubsets(0, temp, ans);
        return ans;
    }
};