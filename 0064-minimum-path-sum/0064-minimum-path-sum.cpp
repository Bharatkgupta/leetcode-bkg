class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minSum(m, vector<int> (n, 0));
        minSum[0][0] = grid[0][0];
        for(int i=1;i<m;i++) {
            minSum[i][0] = minSum[i-1][0] + grid[i][0];
        }
        for(int i=1;i<n;i++) {
            minSum[0][i] = minSum[0][i-1] + grid[0][i];
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                minSum[i][j] = grid[i][j] + min(minSum[i-1][j], minSum[i][j-1]);
            }
        }
        return minSum[m-1][n-1];
    }
};