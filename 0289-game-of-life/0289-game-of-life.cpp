class Solution {
    int d[5] = {-1,1,0,1,1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> prev(n, 0);
        for(int r=0;r<m;r++) {
            vector<int> curr = board[r];
            for(int c=0;c<n;c++) {
                int cntAlive = 0;
                for(int i=0;i<4;i++) {
                    int nr = r+d[i+1], nc = c+d[i];
                    if(nr>=0 && nc>=0 && nr<m && nc<n) {
                        cntAlive+=board[nr][nc];
                    }
                }
                cntAlive += c==0 ? 0 : curr[c-1]+prev[c-1];
                cntAlive += (prev[c] + (c==n-1 ? 0 : prev[c+1]));
                if(board[r][c]) {
                    if(cntAlive < 2) {
                        board[r][c] = 0;
                    }
                    if(cntAlive > 3) {
                        board[r][c] = 0;
                    }
                } else {
                    if(cntAlive == 3) {
                        board[r][c] = 1;
                    }
                }
            }
            prev = curr;
        }
    }
};