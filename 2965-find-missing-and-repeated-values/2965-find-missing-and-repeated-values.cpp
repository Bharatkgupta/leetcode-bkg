class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=1;i<=n*n;i++) {
            if(i != grid[(i-1)/n][(i-1)%n]) {
                int val = grid[(i-1)/n][(i-1)%n];
                int temp = grid[(val-1)/n][(val-1)%n];
                if(val == temp) {
                    continue;
                }
                grid[(val-1)/n][(val-1)%n] = val;
                grid[(i-1)/n][(i-1)%n] = temp;
                i--;
            }
        }
        for(int i=1;i<=n*n;i++) {
            cout<<grid[(i-1)/n][(i-1)%n]<<" ";
            if(i != grid[(i-1)/n][(i-1)%n]) {
                return {grid[(i-1)/n][(i-1)%n],i};
            }
        }
        return {0,0};
    }
};