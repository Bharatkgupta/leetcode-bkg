class Solution {
    int d[9] = {1,0,-1,0,1,-1,-1,1,1};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        
        queue<pair<int,int>> q;
        q.push({click[0], click[1]});
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            
            if(board[x][y] == 'M') {
                board[x][y] = 'X';
                break;
            } else if(board[x][y] == 'E') {
                int cntMines = 0;
                for(int i=0;i<8;i++) {
                    int nx = x+d[i], ny = y+d[i+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny] == 'M') {
                        cntMines++;
                    }
                }
                if(cntMines == 0) {
                    board[x][y] = 'B';
                    for(int i=0;i<8;i++) {
                        int nx = x+d[i], ny = y+d[i+1];
                        if(nx>=0 && ny>=0 && nx<m && ny<n) {
                            q.push({nx,ny});
                        }
                    }
                } else {
                    board[x][y] = '0'+cntMines;
                }
            }
        }
        return board;
    }
};