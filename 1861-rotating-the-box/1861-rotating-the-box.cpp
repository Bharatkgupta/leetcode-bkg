class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> roatatedBox(n, vector<char> (m, '.'));
        
        for(int r = 0;r<m;r++) {
            int i = n-1;
            for(int c = n-1;c>=0;c--) {
                if(box[r][c] == '#') {
                    roatatedBox[i][m-r-1] = '#';
                    i--;
                }
                if(box[r][c] == '*') {
                    roatatedBox[c][m-r-1] = '*';
                    i = c-1;
                }
            }
        }
        
        return roatatedBox;
    }
};