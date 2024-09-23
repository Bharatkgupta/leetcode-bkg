class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalPaths[m][n];
        for(int i=0;i<m;i++) {
            totalPaths[i][0] = 1;
        }
        for(int i=0;i<n;i++) {
            totalPaths[0][i] = 1;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                totalPaths[i][j] = totalPaths[i-1][j] + totalPaths[i][j-1];
            }
        }
        return totalPaths[m-1][n-1];
    }
};