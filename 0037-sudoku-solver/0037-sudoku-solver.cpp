class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y,int i) {
        char val = '0' + i;
        for(int i=0;i<9;i++) {
            if(board[x][i] == val) {
                return false;
            }
        }
        for(int i=0;i<9;i++) {
            if(board[i][y] == val) {
                return false;
            }
        }
        int xx = x/3, yy = y/3;
        for(int i=3*xx;i<3*(xx+1);i++) {
            for(int j=3*yy;j<3*(yy+1);j++) {
                if(board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    bool SS(vector<vector<char>>& board, int x, int y) {
        if(y == 9) {
            return true;
        }
        if(board[x][y] != '.') {
            bool valid = false;
            if(x == 8) {
                valid = SS(board, 0, y+1);
            } else {
                valid = SS(board, x+1, y);
            }
            if(valid) {
                return true;
            }
            return false;
        }
        for(int i=1;i<10;i++) {
            if(isValid(board, x, y, i)) {
                board[x][y] = '0' + i;
                bool valid = false;
                if(x == 8) {
                    valid = SS(board, 0, y+1);
                } else {
                    valid = SS(board, x+1, y);
                }
                if(valid) {
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        SS(board, 0, 0);
    }
};