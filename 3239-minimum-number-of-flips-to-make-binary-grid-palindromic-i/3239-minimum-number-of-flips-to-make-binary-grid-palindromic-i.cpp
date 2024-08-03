class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rc=0,cc=0;
        for(int r=0;r<m;r++) {
            int s=0,e=n-1;
            while(s<e) {
                if(grid[r][s] != grid[r][e]) {
                    rc++;
                }
                s++;
                e--;
            }
        }
        for(int c=0;c<n;c++) {
            int s=0,e=m-1;
            while(s<e) {
                if(grid[s][c] != grid[e][c]) {
                    cc++;
                }
                s++;
                e--;
            }
        }
        return min(rc,cc);
    }
};