class Solution {
    int d[5] = {1,0,-1,0,1};
    bool isPresent(vector<vector<char>>& board, string word, int r, int c, int idx) {
        if(idx == word.size()) {
            return true;
        }
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] != word[idx]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '0';
        for(int i=0;i<4;i++) {
            int nr = r+d[i], nc = c+d[i+1];
            if(isPresent(board, word, nr, nc, idx+1)) {
                return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(board[r][c] == word[0] && isPresent(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};