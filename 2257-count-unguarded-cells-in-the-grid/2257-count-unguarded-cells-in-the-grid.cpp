class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> isg(m, vector<bool> (n, false));
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(const auto& guard : guards) {
            grid[guard[0]][guard[1]] = -1;
        }
        for(const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        for(int r=0;r<m;r++) {
            bool prev = false;
            for(int c=0;c<n;c++) { 
                if(grid[r][c] == -1) {
                    prev = true;
                }
                if(prev == true) {
                    isg[r][c] = true;
                }
                if(grid[r][c] == 1) {
                    prev = false;
                    isg[r][c] = true;
                }
            }
        }
        for(int c=0;c<n;c++) {
            bool prev = false;
            for(int r=0;r<m;r++) { 
                if(grid[r][c] == -1) {
                    prev = true;
                }
                if(prev == true) {
                    isg[r][c] = true;
                }
                if(grid[r][c] == 1) {
                    prev = false;
                    isg[r][c] = true;
                }
            }
        }
        for(int r=0;r<m;r++) {
            bool prev = false;
            for(int c=n-1;c>=0;c--) { 
                if(grid[r][c] == -1) {
                    prev = true;
                }
                if(prev == true) {
                    isg[r][c] = true;
                }
                if(grid[r][c] == 1) {
                    prev = false;
                    isg[r][c] = true;
                }
            }
        }
        for(int c=0;c<n;c++) {
            bool prev = false;
            for(int r=m-1;r>=0;r--) { 
                if(grid[r][c] == -1) {
                    prev = true;
                }
                if(prev == true) {
                    isg[r][c] = true;
                }
                if(grid[r][c] == 1) {
                    prev = false;
                    isg[r][c] = true;
                }
            }
        }
        int cnt = 0;
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) { 
                if(!isg[r][c]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};