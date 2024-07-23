class Solution {
    int d[5] = {1,1,-1,-1,1};

    void disableCells(vector<vector<int>>& canUse, int n, int x, int y) {
        canUse[x][y]--;
        for(int i=0;i<n;i++) {
            canUse[x][i]++;
            canUse[i][y]++;
        }
        for(int i=0;i<4;i++) {
            int xd = x+d[i], yd = y+d[i+1];
            while(xd >=0 && xd<n && yd>=0 && yd<n) {
                canUse[xd][yd]++;
                xd = xd+d[i], yd = yd+d[i+1];
            }
        }
    }

    void enableCells(vector<vector<int>>& canUse, int n, int x, int y) {
        canUse[x][y]++;
        for(int i=0;i<n;i++) {
            canUse[x][i]--;
            canUse[i][y]--;
        }
        for(int i=0;i<4;i++) {
            int xd = x+d[i], yd = y+d[i+1];
            while(xd >=0 && xd<n && yd>=0 && yd<n) {
                canUse[xd][yd]--;
                xd = xd+d[i], yd = yd+d[i+1];
            }
        }
    }

    void placeQueens(vector<vector<string>>& ans, vector<string>& subAns, int n, int row, vector<vector<int>>& canUse) {
        if(row == n) {
            ans.push_back(subAns);
            return;
        }
        for(int i=0;i<n;i++) {
            if(canUse[row][i] == 0) {
                subAns[row][i] = 'Q';
                disableCells(canUse, n, row, i);
                placeQueens(ans, subAns, n, row+1, canUse);
                enableCells(canUse, n, row, i);
                subAns[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        int numQ = 0;
        vector<vector<string>> ans;
        vector<vector<int>> canUse(n, vector<int> (n, 0));
        vector<string> subAns(n, string(n,'.'));
        placeQueens(ans, subAns, n, 0, canUse);
        return ans;
    }
};