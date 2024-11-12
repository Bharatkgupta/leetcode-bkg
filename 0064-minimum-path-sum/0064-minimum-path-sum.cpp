class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, INT_MAX), curr(n, 0);
        prev[0] = 0;
        for(int i=0;i<m;i++) {
            curr[0] = prev[0] + grid[i][0];
            for(int j=1;j<n;j++) {
                curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};