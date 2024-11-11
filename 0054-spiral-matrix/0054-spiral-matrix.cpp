class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiralMat;
        int l=0, r=n-1, t=0, b=m-1;
        while(true) {
            for(int i=l;i<=r;i++) {
                spiralMat.push_back(matrix[t][i]);
            }
            t++;
            if(spiralMat.size() == m*n) {
                break;
            }
            for(int i=t;i<=b;i++) {
                spiralMat.push_back(matrix[i][r]);
            }
            r--;
            if(spiralMat.size() == m*n) {
                break;
            }
            for(int i=r;i>=l;i--) {
                spiralMat.push_back(matrix[b][i]);
            }
            b--;
            if(spiralMat.size() == m*n) {
                break;
            }
            for(int i=b;i>=t;i--) {
                spiralMat.push_back(matrix[i][l]);
            }
            l++;
            if(spiralMat.size() == m*n) {
                break;
            }
        }
        return spiralMat;
    }
};