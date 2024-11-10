class Solution {
    int d[5] = {1,0,-1,0,1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(grid[r][c] == 2) {
                    q.push({r,c});
                }
            }
        }
        int t=-1;
        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                auto currCell = q.front();
                q.pop();
                
                for(int j=0;j<4;j++) {
                    int nr = currCell.first+d[j], nc = currCell.second+d[j+1];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                    }
                }
            }
            t++;
        }
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(grid[r][c] == 1) {
                    return -1;
                }
            }
        }
        return t == -1 ? 0 : t;
    }
};