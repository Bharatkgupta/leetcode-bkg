class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        int maxPath = 1;
        
        for (auto dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            
            if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && matrix[nx][ny] > matrix[x][y]) {
                maxPath = max(maxPath, 1 + dfs(matrix, dp, nx, ny));
            }
        }
        
        dp[x][y] = maxPath;
        return maxPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int longestPath = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longestPath = max(longestPath, dfs(matrix, dp, i, j));
            }
        }
        
        return longestPath;
    }
};
